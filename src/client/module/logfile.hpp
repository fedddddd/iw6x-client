#pragma once
#include <string>

namespace logfile
{
	void queue_message(std::string message);
	const char* get_time_offset();
}