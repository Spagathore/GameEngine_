#pragma once

#include "ge_pch.h"

#include "Core.h"
#include "Events/Event.h"

namespace GameEngine {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Game Engine",
			unsigned int widht = 1280,
			unsigned int height = 720)
			: Title(title), Width(widht), Height(height)
		{
		}
	};

	// Interface
	class GAME_ENGINE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attribs
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}