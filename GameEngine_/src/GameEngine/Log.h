#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace GameEngine {

	class GAME_ENGINE_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};

}

// Core Log Macros

#define GE_CORE_TRACE(...)     ::GameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_INFO(...)      ::GameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_WARN(...)      ::GameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...)     ::GameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_FATAL(...)     ::GameEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client Log Macros

#define GE_TRACE(...)          ::GameEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_INFO(...)           ::GameEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define GE_WARN(...)           ::GameEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_ERROR(...)          ::GameEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define GE_FATAL(...)          ::GameEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)


