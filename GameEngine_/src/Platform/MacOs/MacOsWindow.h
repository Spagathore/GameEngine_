//
//  MacOsWindow.h
//  GameEngine_
//
//  Created by Ankit Rathore on 25/06/25.
//

#pragma once

#include "GameEngine/Window.h"

#include <GLFW/glfw3.h>

#ifdef GE_PLATFORM_MACOS

namespace GameEngine {

    class MacOsWindow : public Window
    {
    public:
        MacOsWindow(const WindowProps& props);
        virtual ~MacOsWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

    private:
        virtual void Init(const WindowProps& props);
        virtual void ShutDown();

    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };
        
        WindowData m_Data;
    };
}

#endif
