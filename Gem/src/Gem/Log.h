#pragma once
#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Gem
{
	class GEM_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger();
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger();

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

// Defining Core Logger Macros for easiness
#define GE_CORE_TRACE(...) ::Gem::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_INFO(...)  ::Gem::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_WARN(...)  ::Gem::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...) ::Gem::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_FATAL(...) ::Gem::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Defining Client Side Logger Macros
#define GE_TRACE(...) ::Gem::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_INFO(...)  ::Gem::Log::GetClientLogger()->info(__VA_ARGS__)
#define GE_WARN(...)  ::Gem::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_ERROR(...) ::Gem::Log::GetClientLogger()->error(__VA_ARGS__)
#define GE_FATAL(...) ::Gem::Log::GetClientLogger()->fatal(__VA_ARGS__)
