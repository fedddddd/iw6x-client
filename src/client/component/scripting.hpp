#pragma once

#include <std_include.hpp>

#include "game/scripting/entity.hpp"
#include "game/scripting/execution.hpp"
#include "game/scripting/event.hpp"

namespace scripting
{
	void on(const char* name, std::function<void(event&)> callback);
}