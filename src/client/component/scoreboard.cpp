#include <std_include.hpp>
#include "loader/component_loader.hpp"

#include "game/game.hpp"
#include "scheduler.hpp"
#include "utils/hook.hpp"
#include "utils/string.hpp"

#define scoreboard_font game::R_RegisterFont("fonts/normalfont")
#define material_white game::Material_RegisterHandle("white")

namespace scoreboard
{
	namespace
	{
		bool toggled;

		float font_color[4] = {0.9f, 0.9f, 0.9f, 1.0f};
		float font_color_red[4] = {1.0f, 0.2f, 0.2f, 1.0f};
		float font_color_yellow[4] = {1.0f, 0.7f, 0.13f, 1.0f};

		float scale_x = 1.f;
		float scale_y = 1.f;

		float base_x = 1.f;
		float base_y = 1.f;

		float scoreboard_width = 1300.f;

		float team_colors[5][4] =
		{
			{ 1.f, 1.f, 1.f, 0.5f },
			{ 0.7f, 0.5f, 0.2f, 0.5f },
			{ 0.2f, 0.5f, 0.6f, 0.5f },
			{ 0.5f, 0.5f, 0.5f, 0.5f },
			{ 0.5f, 0.5f, 0.5f, 0.5f }
		};

		const auto team_scores = reinterpret_cast<int*>(0x141820C4C);
		const auto team_players = reinterpret_cast<int*>(0x141820C6C);

		game::mp::ScoreInfo* clientScores = reinterpret_cast<game::mp::ScoreInfo*>(0x1419B714E);
		game::mp::score_t* scores = reinterpret_cast<game::mp::score_t*>(0x141820C80);

		std::unordered_map<int, const char*> team_names =
		{
			{0, "Free"},
			{1, "Federation"},
			{2, "Ghosts"},
			{3, "Spectator"},
			{4, "Spectator"}
		};

		std::unordered_map<std::string, std::function<void(int, float, float)>> scoreboard_entries;

		void add_entry(std::string name, std::function<void(int, float, float)> callback)
		{
			scoreboard_entries[name] = callback;
		}

		int get_client_count()
		{
			const auto* sv_maxclients = game::Dvar_FindVar("sv_maxclients");
			auto count = 0;

			for (auto i = 0; i < sv_maxclients->current.integer; i++)
			{
				if (scores[i].rankDisplayLevel != NULL)
				{
					count++;
				}
			}

			return count;
		}

		void check_resize()
		{
			base_x = game::ScrPlace_GetViewPlacement()->realViewportSize[0] / 4;
			base_y = game::ScrPlace_GetViewPlacement()->realViewportSize[1] / 4;

			scale_x = game::ScrPlace_GetViewPlacement()->realViewportSize[0] / 2560.f;
			scale_y = game::ScrPlace_GetViewPlacement()->realViewportSize[1] / 1440.f;

			base_y -= (get_client_count() / 2) * (25.f * scale_y);
			base_y = std::max(base_y, 200.f * scale_y);
		}

		float hue_to_rgb(float p, float q, float t)
		{
			if (t < 0.f) t += 1.f;
			if (t > 1.f) t -= 1.f;
			if (t < 1.f / 6.f) return p + (q - p) * 6.f * t;
			if (t < 1.f / 2.f) return q;
			if (t < 2.f / 3.f) return p + (q - p) * (2.f / 3.f - t) * 6.f;
			return p;
		}

		void hsl_to_rgb(float h, float s, float l, float* out)
		{
			float q = l < 0.5f
				? l * (1.f + s)
				: l + s - l * s;

			float p = 2.f * l - q;

			out[0] = hue_to_rgb(p, q, h + 1.f / 3.f);
			out[1] = hue_to_rgb(p, q, h);
			out[2] = hue_to_rgb(p, q, h - 1.f / 3.f);
		}

		void draw_text(const char* text, float x, float y, float _color[4])
		{
			x = x * scale_x + base_x;
			y = y * scale_y + base_y;

			game::R_AddCmdDrawText(text, 0x7FFFFFFF, scoreboard_font, x, y, scale_x, scale_y, 0.0f, _color, 0);
		}

		void draw_box(float x, float y, float w, float h, game::vec4_t _dark_color, game::vec4_t _color)
		{
			x = x * scale_x + (2 * base_x - scoreboard_width / 2);
			y = y * scale_y + base_y;

			w *= scale_x;
			h *= scale_y;

			game::R_AddCmdDrawStretchPic(x, y, w, h, 0.0f, 0.0f, 0.0f, 0.0f, _color, material_white);
			game::R_AddCmdDrawStretchPic(x, y, 2.0f, h, 0.0f, 0.0f, 0.0f, 0.0f, _dark_color, material_white);
			game::R_AddCmdDrawStretchPic((x + w) - 2.0f, y, 2.0f, h, 0.0f, 0.0f, 0.0f, 0.0f, _dark_color,
				material_white);
			game::R_AddCmdDrawStretchPic(x, y, w, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, _dark_color, material_white);
			game::R_AddCmdDrawStretchPic(x, (y + h) - 2.0f, w, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, _dark_color,
				material_white);
		}

		void draw_icon(float x, float y, float w, float h, game::Material* material)
		{
			x = x * scale_x + base_x;
			y = y * scale_y + base_y;

			w *= scale_x;
			h *= scale_y;

			game::R_AddCmdDrawStretchPic(x, y, w, h, 0.0f, 0.0f, 1.0f, 1.0f, NULL, material);
		}

		std::vector<std::vector<int>> get_sorted_clients()
		{
			const auto sv_maxclients = game::Dvar_FindVar("sv_maxclients");

			std::vector<std::vector<int>> teams(5);

			for (auto i = 0; i < sv_maxclients->current.integer; i++)
			{
				teams[scores[i].team].push_back(i);
			}

			return teams;
		}

		void draw_player(int num, float x, float y, float w, float h)
		{
			const auto self = scores[num];
			const auto score_info = clientScores[self.client];

			const auto text_y_offset = y + h - scoreboard_font->pixelHeight / 4;
			const char* name = reinterpret_cast<const char*>(0x1417A7460 + 0xD8 * self.client);
			const auto icon_height = h - 10.f;

			draw_icon(30.f, y + 5.f, icon_height, icon_height, self.hRankIcon);

			draw_text(self.rankDisplayLevel, 30.f + icon_height, y + h, font_color);

			if (self.hStatusIcon != NULL)
			{
				draw_icon(110.f, y + 5.f, icon_height, icon_height, self.hStatusIcon);
			}

			const auto _font_color = self.client == game::mp::cgArray->ps.clientNum 
				? font_color_yellow
				: font_color;

			draw_text(name, 180.f, text_y_offset, _font_color);

			auto x_offset = 500.f;
			for (auto entry : scoreboard_entries)
			{
				entry.second(num, x_offset, text_y_offset);
				x_offset += (scoreboard_width - 500.f) / scoreboard_entries.size();
			}
		}

		void draw_scoreboard()
		{
			if (!toggled)
			{
				return;
			}

			check_resize();

			const auto w = base_x * 2;
			const auto h = base_y * 2;

			const auto teams = get_sorted_clients();
			const auto offset = 0.f;

			auto base_offset = 50.f;
			auto drawn_clients = 0;

			for (auto i = 1; i < teams.size(); i++)
			{
				if (!teams[i].size())
				{
					continue;
				}

				draw_text(utils::string::va("%s (%i)", team_names[i], team_players[i]), 180.f, base_offset, font_color);

				auto x_offset = 500.f;
				for (auto entry : scoreboard_entries)
				{
					draw_text(entry.first.data(), x_offset, base_offset, font_color);
					x_offset += (scoreboard_width - 500.f) / scoreboard_entries.size();
				}

				for (auto c = 0; c < teams[i].size(); c++)
				{
					const auto self = scores[teams[i][c]];

					if (self.rankDisplayLevel != NULL)
					{
						float background[4] =
						{
							team_colors[self.team][0],
							team_colors[self.team][1],
							team_colors[self.team][2],
							c % 2 == 0 ? team_colors[self.team][3] : 0.3f
						};

						const auto y_offset = base_offset + c * 50.f;
						const auto height = scoreboard_font->pixelHeight * 1.5f;

						drawn_clients++;

						draw_box(0,
							y_offset,
							scoreboard_width,
							height,
							background,
							background
						);

						draw_player(teams[i][c], base_x, y_offset, scoreboard_width, height);
					}
				}

				base_offset += drawn_clients * 50.f + 100.f;
				drawn_clients = 0;
			}
		}
	}

	bool scoreboard_key_event(int local_client_num, int key, int down)
	{
		if (key == game::keyNum_t::K_TAB && game::CL_IsCgameInitialized())
		{
			toggled = down;

			return true;
		}

		return false;
	}
	
	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			if (game::environment::is_dedi())
			{
				return;
			}

			add_entry("Score", [](int num, float x, float y)
			{
				const auto self = scores[num];
				const auto score_info = clientScores[self.client];

				const auto _font_color = self.client == game::mp::cgArray->ps.clientNum
					? font_color_yellow
					: font_color;

				draw_text(utils::string::va("%i", self.score), x, y, _font_color);
			});

			add_entry("Kills", [](int num, float x, float y)
			{
				const auto self = scores[num];
				const auto score_info = clientScores[self.client];

				const auto _font_color = self.client == game::mp::cgArray->ps.clientNum
					? font_color_yellow
					: font_color;

				draw_text(utils::string::va("%i", self.kills), x, y, _font_color);
			});

			add_entry("Deaths", [](int num, float x, float y)
			{
				const auto self = scores[num];
				const auto score_info = clientScores[self.client];

				const auto _font_color = self.client == game::mp::cgArray->ps.clientNum
					? font_color_yellow
					: font_color;

				draw_text(utils::string::va("%i", self.deaths), x, y, _font_color);
			});

			add_entry("Assists", [](int num, float x, float y)
			{
				const auto self = scores[num];
				const auto score_info = clientScores[self.client];

				const auto _font_color = self.client == game::mp::cgArray->ps.clientNum
					? font_color_yellow
					: font_color;

				draw_text(utils::string::va("%i", self.assists), x, y, _font_color);
			});

			add_entry("KDR", [](int num, float x, float y)
			{
				const auto self = scores[num];
				const auto score_info = clientScores[self.client];

				const auto _font_color = self.client == game::mp::cgArray->ps.clientNum
					? font_color_yellow
					: font_color;

				const auto kdr = (float)self.kills / (float)std::max(self.deaths, 1);

				draw_text(utils::string::va("%.2f", kdr), x, y, _font_color);
			});

			add_entry("Ping", [](int num, float x, float y)
			{
				const auto self = scores[num];

				float ping_color[4] = { 0.f, 0.f, 0.f, 1.f };
				const auto hue = std::max(0.f, 150.f - std::max((float)self.ping, 50.f) / 2.f);

				hsl_to_rgb(hue / 360.f, 1.f, 0.5f, ping_color);

				draw_text(utils::string::va("%i", self.ping), x, y, ping_color);
			});

			scheduler::loop(draw_scoreboard, scheduler::pipeline::renderer);
		}
	};
}

REGISTER_COMPONENT(scoreboard::component)
