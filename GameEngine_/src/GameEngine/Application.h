#pragma once

#include "Core.h"

#include "Window.h"
#include "GameEngine/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace GameEngine {

	class GAME_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
        
        void OnEvent(Event& e);
        
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

	private:
        bool OnWindowClose(WindowCloseEvent& e);
        
        WindowProps m_WindowProps;
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
        LayerStack m_LayerStack;
	};

	// To be Degined in CLIENT
	Application* CreateApplication();

}
