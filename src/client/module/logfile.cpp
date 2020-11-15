#include <std_include.hpp>
#include "loader/module_loader.hpp"

#include "game/game.hpp"
#include "module/scheduler.hpp"
#include "utils/hook.hpp"
#include "utils/string.hpp"

#include <fstream>

namespace logfile
{
	const auto start = std::chrono::high_resolution_clock::now();

	std::queue<std::string> message_queue;
	std::mutex mutex;
	std::string logpath;
	std::ofstream stream;

	std::string trail_character(std::string string, int length, const char* c)
	{
		while (string.length() < length)
		{
			string.insert(0, c);
		}

		return string;
	}

	const char* get_time_offset()
	{
		const auto now = std::chrono::high_resolution_clock::now();

		const auto seconds = int(std::chrono::duration_cast<std::chrono::seconds>(now - start).count());
		const auto minutes = int(std::floor(seconds / 60));

		const auto s = std::to_string(seconds - minutes * 60);
		const auto m = std::to_string(minutes);

		return utils::string::va("%s:%s ", trail_character(m, 3, " ").data(), trail_character(m, 2, "0").data());
	}

	void queue_message(std::string message)
	{
		message.insert(0, get_time_offset());
		message_queue.push(message);
	}

	void log_messages()
	{
		while (!message_queue.empty())
		{
			std::queue<std::string> message_queue_copy;

			{
				std::lock_guard _(mutex);
				message_queue_copy = message_queue;
				message_queue = {};
			}

			while (!message_queue_copy.empty())
			{
				stream << message_queue_copy.front() << std::endl;
				message_queue_copy.pop();
			}
		}
	}

	namespace
	{
		utils::hook::detour player_connect_hook;
		utils::hook::detour player_disconnect_hook;

		utils::hook::detour player_damage_hook;
		utils::hook::detour player_killed_hook;

		utils::hook::detour client_command_hook;

		utils::hook::detour exit_level_hook;
		utils::hook::detour init_game_hook;

		std::string get_clean_name(const char* name)
		{
			char clean_name[32] = { 0 };
			strncpy_s(clean_name, name, 32);
			game::I_CleanStr(clean_name);

			return std::string(clean_name);
		}

		const char* get_mod_string(int meansOfDeath)
		{
			const game::scr_string_t mod_scr_string = reinterpret_cast<game::scr_string_t*>(0x14450CEB4)[meansOfDeath];
			const auto* mod_string = game::SL_ConvertToString(mod_scr_string);

			return mod_string;
		}

		void player_connect_stub(game::mp::gentity_s* self)
		{
			char clean_name[32] = { 0 };
			strncpy_s(clean_name, self->client->sess.cs.name, 32);
			game::I_CleanStr(clean_name);

			queue_message(utils::string::va("J;%s;%i;%s", game::SV_GetGuid(self->client->ps.clientNum), self->client->ps.clientNum, clean_name));

			return player_connect_hook.invoke<void>(self);
		}

		void player_disconnect_stub(game::mp::gentity_s* self, const char* reason)
		{
			char clean_name[32] = { 0 };
			strncpy_s(clean_name, self->client->sess.cs.name, 32);
			game::I_CleanStr(clean_name);

			queue_message(utils::string::va("Q;%s;%i;%s", game::SV_GetGuid(self->client->ps.clientNum), self->client->ps.clientNum, clean_name));

			return player_disconnect_hook.invoke<void>(self, reason);
		}

		void player_damage_stub(game::mp::gentity_s* self, const game::mp::gentity_s* inflictor, game::mp::gentity_s* attacker, int damage, int dflags,
			int meansOfDeath, const game::Weapon weapon, bool isAlternate, const float* vPoint, const float* vDir, const game::hitLocation_t hitLoc, int timeOffset)
		{
			char weaponName[256];
			game::BG_GetWeaponNameComplete(weapon, isAlternate, weaponName, 256);

			auto attackerNum = !inflictor || !inflictor->client ? self->client->ps.clientNum : inflictor->client->ps.clientNum;

			queue_message(utils::string::va("D;%s;%i;%s;%s;%s;%i;%s;%s;%s;%i;%s;%s",
				game::SV_GetGuid(self->client->ps.clientNum),
				self->client->ps.clientNum,
				self->client->sess.cs.team == 0x2 ? "allies" : "axis",
				get_clean_name(self->client->sess.cs.name).data(),
				game::SV_GetGuid(attackerNum),
				attackerNum,
				game::mp::g_entities[attackerNum].client->sess.cs.team == 0x2 ? "allies" : "axis",
				get_clean_name(game::mp::g_entities[attackerNum].client->sess.cs.name).data(),
				weaponName,
				damage,
				get_mod_string(meansOfDeath),
				reinterpret_cast<const char**>(0x1409E62B0)[hitLoc]
			));

			return player_damage_hook.invoke<void>(self, inflictor, attacker, damage, dflags, meansOfDeath, weapon, isAlternate, vPoint, vDir, hitLoc, timeOffset);
		}

		void player_killed_stub(game::mp::gentity_s* self, const game::mp::gentity_s* inflictor, game::mp::gentity_s* attacker, int damage,
			int meansOfDeath, const game::Weapon weapon, bool isAlternate, const float* vDir, const game::hitLocation_t hitLoc, int psTimeOffset, int deathAnimDuration)
		{
			char weaponName[256];
			game::BG_GetWeaponNameComplete(weapon, isAlternate, weaponName, 256);

			auto attackerNum = !inflictor || !inflictor->client ? self->client->ps.clientNum : inflictor->client->ps.clientNum;

			queue_message(utils::string::va("K;%s;%i;%s;%s;%s;%i;%s;%s;%s;%i;%s;%s",
				game::SV_GetGuid(self->client->ps.clientNum),
				self->client->ps.clientNum,
				self->client->sess.cs.team == 0x2 ? "allies" : "axis",
				get_clean_name(self->client->sess.cs.name).data(),
				game::SV_GetGuid(attackerNum),
				attackerNum,
				game::mp::g_entities[attackerNum].client->sess.cs.team == 0x2 ? "allies" : "axis",
				get_clean_name(game::mp::g_entities[attackerNum].client->sess.cs.name).data(),
				weaponName,
				damage,
				get_mod_string(meansOfDeath),
				reinterpret_cast<const char**>(0x1409E62B0)[hitLoc]
			));

			return player_killed_hook.invoke<void>(self, inflictor, attacker, damage, meansOfDeath, weapon, isAlternate, vDir, hitLoc, psTimeOffset, deathAnimDuration);
		}

		void client_command_stub(int clientNum)
		{
			auto self = &game::mp::g_entities[clientNum];
			auto hidden = false;
			char cmd[1024];

			game::SV_Cmd_ArgvBuffer(0, cmd, 1024);

			if (cmd == "say"s || cmd == "say_team"s)
			{
				std::string message(game::ConcatArgs(1));

				hidden = message[1] == '/';
				message.erase(0, hidden ? 2 : 1);

				char clean_name[32] = { 0 };
				strncpy_s(clean_name, self->client->sess.cs.name, 32);
				game::I_CleanStr(clean_name);

				queue_message(utils::string::va("%s;%s;%i;%s;%s",
					cmd == "say"s ? "say" : "sayteam",
					game::SV_GetGuid(clientNum),
					clientNum,
					clean_name,
					message.data()
				));
			}

			if (!hidden)
			{
				return client_command_hook.invoke<void>(clientNum);
			}
		}

		void exit_level_stub()
		{
			queue_message("ExitLevel: executed");

			return exit_level_hook.invoke<void>();
		}

		void init_game_stub(int restart, int registerDvars, int savegame)
		{
			queue_message("------------------------------------------------------------");
			queue_message("InitGame");
			queue_message("------------------------------------------------------------");

			return init_game_hook.invoke<void>(restart, registerDvars, savegame);
		}
	}

	class module final : public module_interface
	{
	public:
		void post_unpack() override
		{
			if (!game::environment::is_dedi())
			{
				return;
			}

			scheduler::on_game_initialized([&]() 
			{
				const auto g_log = game::Dvar_FindVar("g_log");
				const auto g_logpath = game::Dvar_FindVar("g_logpath");

				if (!g_log || !g_logpath || !g_log->current.integer)
				{
					return;
				}

				logpath = game::Dvar_FindVar("fs_basepath")->current.string;
				logpath.append("\\iw6x\\");
				logpath.append(g_logpath->current.string);

				stream.open(logpath, std::ofstream::out | std::ofstream::app);

				scheduler::loop(log_messages, scheduler::pipeline::async, 50ms);
			});

			exit_level_hook.create(0x14039E2E0, exit_level_stub);
			init_game_hook.create(0x140475B00, init_game_stub);

			client_command_hook.create(0x1403929B0, client_command_stub);

			player_connect_hook.create(0x1403CE0A0, player_connect_stub);
			player_disconnect_hook.create(0x1403CE200, player_disconnect_stub);

			player_damage_hook.create(0x1403CE0C0, player_damage_stub);
			player_killed_hook.create(0x1403CE260, player_killed_stub);
		}
		void pre_destroy() override
		{
			stream.close();
		}
	};
}

REGISTER_MODULE(logfile::module)
