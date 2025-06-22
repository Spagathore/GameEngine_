#pragma once

#if defined(GE_PLATFORM_WINDOWS) || defined(GE_PLATFORM_MACOS)

extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc, char** argv)
{
	GameEngine::Log::Init();
	GE_CORE_WARN("Initialzed LOG!");
	int a = 5;
	GE_INFO("Hello! Var={0}", a);
#ifdef GE_PLATFORM_MACOS
    GE_INFO("Running From Mac");
#else
    GE_INFO("Running From Windows");
#endif
    
	auto app = GameEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
