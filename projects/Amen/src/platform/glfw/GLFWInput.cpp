#include "pch.h"
#include "GLFWInput.h"
#include "GlfwToAmen.h"
#include <core/logger.h>
#include <core/core.h>

Amen::GLFWInput::GLFWInput(): m_window( static_cast<GLFWwindow *>(App::Get().GetWindow().GetNativeWindow()) )
{
}





bool Amen::GLFWInput::GetKeyDownImp(KeyboardE key)
{
	AMEN_ASSERT(false, "Hasn't been implemented yet.");
	return false;
}





bool Amen::GLFWInput::GetKeyUpImp(KeyboardE key)
{
	AMEN_ASSERT(false, "Hasn't been implemented yet.");
	return false;
}





bool Amen::GLFWInput::GetKeyImp(KeyboardE key)
{
	AMEN_ASSERT(false, "Hasn't been implemented yet.");
	return false;
}





bool Amen::GLFWInput::GetButtonDownImp(MouseButtonE button)
{
	int status = glfwGetMouseButton(m_window, GlfwToAmen::MouseButtonToGLFW(button));

	return status == GLFW_PRESS ? true : false;
}





bool Amen::GLFWInput::GetButtonUpImp(MouseButtonE button)
{
	int status = glfwGetMouseButton(m_window, GlfwToAmen::MouseButtonToGLFW(button));

	return status == GLFW_RELEASE ? true : false;
}





bool Amen::GLFWInput::GetButtonImp(MouseButtonE button)
{
	AMEN_ASSERT(false, "Hasn't been implemented yet.");
	return false;
}





std::pair<double, double> Amen::GLFWInput::GetMousePosImp()
{
	double x, y;
	glfwGetCursorPos(m_window, &x, &y);
	return std::pair<double, double>(x, y);
}





double Amen::GLFWInput::GetMouseXImp()
{
	double x, y;
	glfwGetCursorPos(m_window, &x, &y);

	return x;
}





double Amen::GLFWInput::GetMouseYImp()
{
	double x, y;
	glfwGetCursorPos(m_window, &x, &y);

	return y;
}
