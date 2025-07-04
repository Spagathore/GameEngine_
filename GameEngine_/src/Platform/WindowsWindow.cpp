#include "ge_pch.h"
#include "WindowsWindow.h"

namespace GameEngine {

    static bool s_GLFWInitialized = false;

    Window* Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props) 
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow() 
    {
        ShutDown();
    }

    void WindowsWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        GE_CORE_INFO("Creating Window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized)
        {
            int success = glfwInit();
            GE_CORE_ASSERT(success, "Could not initialize GLFW!");

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    void WindowsWindow::ShutDown() 
    {
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::OnUpdate() 
    { 
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled) 
    { 
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const 
    { 
        return m_Data.VSync; 
    }
}
