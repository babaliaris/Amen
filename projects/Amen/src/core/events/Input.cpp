#include "pch.h"
#include "Input.h"
#include <core/logger.h>
#include <core/core.h>

#include <platform/glfw/GLFWInput.h>

Hazel::Input* Hazel::Input::s_instance = nullptr;


void Hazel::Input::Init()
{
	AMEN_ASSERT(s_instance == nullptr, "Already another instance? This is a singleton!");

	//GLFW Input.
	#if defined(AMEN_WINDOWS) || defined(AMEN_LINUX)
		s_instance = new GLFWInput();
	#endif
}
