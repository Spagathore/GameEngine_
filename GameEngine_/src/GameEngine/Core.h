#pragma once

#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL
		#define GAME_ENGINE_API __declspec(dllexport)
	#else
		#define GAME_ENGINE_API __declspec(dllimport)
	#endif 
#elif defined(GE_PLATFORM_MACOS)
	#ifdef GE_BUILD_DLL
		#define GAME_ENGINE_API __attribute__((visibility("default")))
	#else
		#define GAME_ENGINE_API
	#endif
#else
	#error Unsupported platform! Currently supports Windows and macOS only.
#endif