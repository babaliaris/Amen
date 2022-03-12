#include "pch.h"
#include "platform.h"
#include <core/core.h>
#include <core/window.h>
#include <platform/glfw/glfw_window.h>
#include <platform/glfw/ImGuiGLFWLayer.h>
#include <platform/OpenGL/OpenGLRendererAPI.h>
#include <GLFW/glfw3.h>

//Initialize the s_type static variable.
Hazel::PlatformTypeE Hazel::Platform::s_type;



void Hazel::Platform::Init()
{
	#ifdef AMEN_WINDOWS
		s_type = PlatformTypeE::WINDOWS;
	#endif

	#ifdef AMEN_LINUX
		s_type = PlatformTypeE::LINUX;
	#endif
}


//GLFW Window.
#if defined(AMEN_WINDOWS) || defined(AMEN_LINUX)

	//Implement Window::Create()
	Hazel::Scope<Hazel::Window> Hazel::Window::Create(const Hazel::WindowProps& props)
	{
		//Create the window.
		GLFW_Window *window = new GLFW_Window(props);

		//Get the GLFW window.
		GLFWwindow* glfw_window = static_cast<GLFWwindow*>( window->GetNativeWindow() );

		//Create the OpenGLRenderer.
		new OpenGLRendererAPI( (GLADloadproc)glfwGetProcAddress );

		//Return  the window.
		return Hazel::Scope<Window>(window);
	}

	//Implement ImguiLayer::Create()
	Hazel::Layer* Hazel::ImguiLayer::Create()
	{
		return new ImGuiGLFWLayer();
	}

#endif