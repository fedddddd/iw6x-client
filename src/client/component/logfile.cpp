#include <std_include.hpp>
#include "loader/component_loader.hpp"

#include "game/game.hpp"

#include "scheduler.hpp"
#include "scripting.hpp"
#include "command.hpp"

#include "utils/hook.hpp"
#include "utils/string.hpp"

#include <fstream>

namespace logfile
{
	const auto start = std::chrono::high_resolution_clock::now();

	std::queue<std::string> message_queue;
	std::mutex mutex;
	std::ofstream stream;

	const char* get_time_offset()
	{
		const auto now = std::chrono::high_resolution_clock::now();

		const auto seconds = int(std::chrono::duration_cast<std::chrono::seconds>(now - start).count());
		const auto minutes = int(std::floor(seconds / 60));

		const auto s = seconds - minutes * 60;

		return utils::string::va("%3i:%s%i ", minutes, s < 9 ? "0" : "", s);
	}

	void queue_message(const char* fmt, ...)
	{
		static thread_local utils::string::va_provider<8, 256> provider;
		va_list ap;
		va_start(ap, fmt);
		std::string message = provider.get(fmt, ap);
		va_end(ap);

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
		std::string get_dirname(const std::string& fname)
		{
			size_t pos = fname.find_last_of("\\/");
			return (std::string::npos == pos)
				? ""
				: fname.substr(0, pos);
		}

		std::string clean_name(std::string name)
		{
			char clean_name[32] = { 0 };
			strncpy_s(clean_name, name.data(), 32);
			game::I_CleanStr(clean_name);

			return std::string(clean_name);
		}

		void add_callbacks()
		{
			command::add_sv("say", [](int clientNum, const command::params_sv& params)
			{
				const auto self = &game::mp::g_entities[clientNum];

				auto msg = params.join(1);
				msg.erase(0, 1);

				queue_message("say;%s;%i;%s;%s",
					game::SV_GetGuid(clientNum),
					clientNum,
					clean_name(self->client->sess.cs.name).data(),
					msg.data()
				);
			});

			command::add_sv("say_team", [](int clientNum, const command::params_sv& params)
			{
				const auto self = &game::mp::g_entities[clientNum];

				auto msg = params.join(1);
				msg.erase(0, 1);

				queue_message("sayteam;%s;%i;%s;%s",
					game::SV_GetGuid(clientNum),
					clientNum,
					clean_name(self->client->sess.cs.name).data(),
					msg.data()
				);
			});

			scripting::on("connected", [](scripting::event& e)
			{
				const auto player = e.arguments[0].as<scripting::entity>();

				queue_message("J;%s;%i;%s",
					player.call("getGuid", {}).as<std::string>().data(),
					player.call("getEntityNumber", {}).as<int>(),
					clean_name(player.get<std::string>("name")).data()
				);
			});

			scripting::on("disconnect", [](scripting::event& e)
			{
				const auto player = e.entity;

				queue_message("Q;%s;%i;%s",
					player.call("getGuid", {}).as<std::string>().data(),
					player.call("getEntityNumber", {}).as<int>(),
					clean_name(player.get<std::string>("name")).data()
				);
			});

			scripting::on("damage", [](scripting::event& e)
			{

			});
		}
	}

	class module final : public component_interface
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

				const auto logpath = utils::string::va("%s\\%s\\%s",
					game::Dvar_FindVar("fs_basepath")->current.string,
					game::Dvar_FindVar("fs_basegame")->current.string,
					g_logpath->current.string
				);

				game::Sys_Mkdir(get_dirname(logpath).data());

				stream.open(logpath, std::ofstream::out | std::ofstream::app);

				scheduler::loop(log_messages, scheduler::pipeline::async, 50ms);
			});

			add_callbacks();
		}
		void pre_destroy() override
		{
			stream.close();
		}
	};
}

REGISTER_COMPONENT(logfile::module)
