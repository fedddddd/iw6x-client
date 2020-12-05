#pragma once
#include <utils/concurrent_list.hpp>

namespace scripting::lua
{
	class context;

	class task_handle
	{
	public:
		unsigned long long id = 0;
	};

	class task final : public task_handle
	{
	public:
		std::chrono::steady_clock::time_point last_execution{};
		std::function<void()> callback{};
		std::chrono::milliseconds delay{};
		bool is_volatile = false;
	};

	class scheduler final
	{
	public:
		scheduler(sol::state& state);

		scheduler(scheduler&&) noexcept = delete;
		scheduler& operator=(scheduler&&) noexcept = delete;

		scheduler(const scheduler&) = delete;
		scheduler& operator=(const scheduler&) = delete;

		void run_frame();
		void clear();

	private:
		utils::concurrent_list<task> tasks_;
		std::atomic_int64_t current_task_id_ = 0;

		task_handle add(const std::function<void()>& callback, long long milliseconds, bool is_volatile);
		task_handle add(const std::function<void()>& callback, std::chrono::milliseconds delay, bool is_volatile);

		void remove(const task_handle& handle);
	};
}
