#include <std_include.hpp>
#include "loader/component_loader.hpp"

#include "game/game.hpp"

#include "sol/sol.hpp"

#include <utils/io.hpp>

namespace plugins
{
	namespace
	{
		std::vector<HMODULE> loaded_plugins;

		void load_plugins()
		{
			const auto plugin_dir = "iw6x/plugins/"s;

			if (!utils::io::directory_exists(plugin_dir))
			{
				return;
			}

			const auto plugin_list = utils::io::list_files(plugin_dir);

			for (const auto& file : plugin_list)
			{
				if (file.ends_with(".dll"))
				{
					printf("Loading plugin %s...\n", file.data());

					const auto plugin = LoadLibrary(file.data());

					loaded_plugins.push_back(plugin);
				}
			}
		}
	}

	void initialize_context(const char* script, sol::state* state)
	{
		for (const auto& plugin : loaded_plugins)
		{
			const auto addr = GetProcAddress(plugin, "on_initialize_context");

			if (addr)
			{
				reinterpret_cast<void (*)(const char*, sol::state*)>(addr)(script, state);
			}
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			if (!game::environment::is_dedi())
			{
				return;
			}

			load_plugins();
		}
	};
}

REGISTER_COMPONENT(plugins::component)
