#include "pch.h"
#include "glfw_window.h"
#include <GLFW/glfw3.h>

#include <core/core.h>
#include <core/logger.h>
#include "GlfwToHazel.h"

#include <core/events/keyboard_events.h>
#include <core/events/mouse_events.h>
#include <core/events/application_events.h>


Hazel::GLFW_Window::GLFW_Window(const WindowProps& props) : m_window(nullptr)
{
	//Try to Initilize GLFW.
	AMEN_ASSERT( glfwInit(), "Window failure: GLFW Failed to be initialized." );

	//Set OpenGL 3.3 Core Profile.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Try to create the window.
	m_window = glfwCreateWindow( props.m_width, props.m_height, props.m_title.c_str(), nullptr, nullptr );
	AMEN_ASSERT( m_window != NULL, "Window failure: GLFW Failed to create the window." );

	//Create the OpenGL Context.
	m_context = new GLFWOpenGLContext();
	m_context->SetWindow(m_window);
	m_context->Init();

	//VSync Off.
	glfwSwapInterval(0);

	//Initialize m_data from props.
	m_data.m_width		= props.m_width;
	m_data.m_height		= props.m_height;
	m_data.m_title		= props.m_title;
	m_data.m_vSynced	= false;

	//Set Window User Pointer.
	glfwSetWindowUserPointer(m_window, &m_data);

	//Initialize callbacks.
	this->InitilizeCallbacks();
}




Hazel::GLFW_Window::~GLFW_Window()
{
	AMEN_INFO("Calling ~GLFW_Window()");
	glfwDestroyWindow(m_window);
	glfwTerminate();
}





void Hazel::GLFW_Window::Update()
{
	glfwPollEvents();
	m_context->SwapBuffers();
}





void Hazel::GLFW_Window::SetTitle(const std::string& title)
{
	glfwSetWindowTitle(m_window, title.c_str());
	m_data.m_title = title;

	WindowTitleChangedEvent e(title);
	m_data.m_eventCallback(e);
}




void Hazel::GLFW_Window::SetWidth(int width)
{
	glfwSetWindowSize(m_window, width, m_data.m_height);
	m_data.m_width = width;
}





void Hazel::GLFW_Window::SetHeight(int height)
{
	glfwSetWindowSize(m_window, m_data.m_width, height);
	m_data.m_height = height;
}




void Hazel::GLFW_Window::SetSize(int width, int height)
{
	glfwSetWindowSize(m_window, width, height);
	m_data.m_width = width;
	m_data.m_height = height;
}





void Hazel::GLFW_Window::SetVSync(bool enabled)
{
	//VSync.
	glfwSwapInterval( enabled ? 1 : 0 );

	m_data.m_vSynced = enabled;
}




double Hazel::GLFW_Window::GetTime() const
{
	return glfwGetTime();
}




void Hazel::GLFW_Window::InitilizeCallbacks() const
{
	glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		WindowData& data = *(WindowData *)glfwGetWindowUserPointer(window);

		switch (action)
		{

			case GLFW_PRESS:
			{
				KeyboardKeyPressEvent e( GlfwToHazel::KeyToHazel(key) );
				data.m_eventCallback(e);
				break;
			}

			case GLFW_RELEASE:
			{
				KeyboardKeyReleasedEvent e(GlfwToHazel::KeyToHazel(key) );
				data.m_eventCallback(e);
				break;
			}

			case GLFW_REPEAT:
			{
				KeyboardKeyRepeatEvent e(GlfwToHazel::KeyToHazel(key), 1 );
				data.m_eventCallback(e);
				break;
			}

			default:
			{
				AMEN_ASSERT(false, "This line should never be reached.")
				break;
			}

		}
	});



	glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		switch (action)
		{
			case GLFW_PRESS:
			{
				MouseButonPressedEvent e( GlfwToHazel::MouseButtonToHazel(button) );
				data.m_eventCallback(e);
				break;
			}

			case GLFW_RELEASE:
			{
				MouseButonReleasedEvent e(GlfwToHazel::MouseButtonToHazel(button));
				data.m_eventCallback(e);
				break;
			}

			default:
			{
				AMEN_ASSERT(false, "This line should never be reached.")
				break;
			}
		}
	});



	glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		MouseScrolledEvent e(xoffset, yoffset);

		data.m_eventCallback(e);
	});



	glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		MouseMovedEvent e(xpos, ypos);

		data.m_eventCallback(e);
	});



	glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		WindowResizedEvent e(width, height);

		//Check if the window has been restored to its normal position.
		if ( (width != 0 || height != 0) && data.m_width == 0 && data.m_height == 0)
		{
			WindowRestoredEvent e;
			data.m_eventCallback(e);
		}

		//Update the width and height of the window.
		data.m_width = width;
		data.m_height = height;

		//Set the Window Resize Event.
		data.m_eventCallback(e);

		//Sent WindowMinimizedEvent.
		if (width == 0 && height == 0)
		{
			WindowMinimizedEvent e;
			data.m_eventCallback(e);
		}
	});



	glfwSetWindowPosCallback(m_window, [](GLFWwindow* window, int xpos, int ypos)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		WindowMovedEvent e(xpos, ypos);

		data.m_eventCallback(e);
	});



	glfwSetWindowFocusCallback(m_window, [](GLFWwindow* window, int focused)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		switch (focused)
		{

			case GLFW_TRUE:
			{
				WindowFocusedEvent e;
				data.m_eventCallback(e);
				break;
			}

			case GLFW_FALSE:
			{
				WindowLostFocusEvent e;
				data.m_eventCallback(e);
				break;
			}

			default:
			{
				AMEN_ASSERT(false, "This line should never be reached.")
				break;
			}
		}
	});



	glfwSetWindowCloseCallback(m_window, [](GLFWwindow *window)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		WindowClosedEvent e;
		data.m_eventCallback(e);
	});
}
