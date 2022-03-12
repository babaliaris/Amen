#include "pch.h"
#include "GLFWInput.h"
#include "GlfwToHazel.h"
#include <core/logger.h>
#include <core/core.h>

Hazel::GLFWInput::GLFWInput(): m_window( static_cast<GLFWwindow *>(App::Get().GetWindow().GetNativeWindow()) )
{
}





bool Hazel::GLFWInput::GetKeyDownImp(KeyboardE key)
{
	int state = glfwGetKey(m_window, GlfwToHazel::KeyToGLFW(key) );

	return (state == GLFW_PRESS ? true : false) || (state == GLFW_REPEAT ? true : false);
}





bool Hazel::GLFWInput::GetKeyUpImp(KeyboardE key)
{
	int state = glfwGetKey(m_window, GlfwToHazel::KeyToGLFW(key));

	return (state == GLFW_RELEASE ? true : false);
}





bool Hazel::GLFWInput::GetKeyImp(KeyboardE key)
{
	AMEN_ASSERT(false, "Hasn't been implemented yet.");
	return false;
}





bool Hazel::GLFWInput::GetButtonDownImp(MouseButtonE button)
{
	int status = glfwGetMouseButton(m_window, GlfwToHazel::MouseButtonToGLFW(button));

	return status == GLFW_PRESS ? true : false;
}





bool Hazel::GLFWInput::GetButtonUpImp(MouseButtonE button)
{
	int status = glfwGetMouseButton(m_window, GlfwToHazel::MouseButtonToGLFW(button));

	return status == GLFW_RELEASE ? true : false;
}





bool Hazel::GLFWInput::GetButtonImp(MouseButtonE button)
{
	AMEN_ASSERT(false, "Hasn't been implemented yet.");
	return false;
}





std::pair<double, double> Hazel::GLFWInput::GetMousePosImp()
{
	double x, y;
	glfwGetCursorPos(m_window, &x, &y);
	return std::pair<double, double>(x, y);
}





double Hazel::GLFWInput::GetMouseXImp()
{
	double x, y;
	glfwGetCursorPos(m_window, &x, &y);

	return x;
}





double Hazel::GLFWInput::GetMouseYImp()
{
	double x, y;
	glfwGetCursorPos(m_window, &x, &y);

	return y;
}
