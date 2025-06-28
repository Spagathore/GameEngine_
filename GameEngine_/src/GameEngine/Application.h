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

		inline Window& GetWindow() const { return *m_Window; }

		inline static Application& Get() { return  *s_Instance; }
	
	private:
        bool OnWindowClose(WindowCloseEvent& e);
        
        WindowProps m_WindowProps;
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
        LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	// To be Degined in CLIENT
	Application* CreateApplication();

}
