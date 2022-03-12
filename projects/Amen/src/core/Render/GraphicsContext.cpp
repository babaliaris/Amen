#include "pch.h"
#include "GraphicsContext.h"
#include <core/logger.h>


Hazel::GraphicsContext* Hazel::GraphicsContext::s_instance = nullptr;

Hazel::GraphicsContext::GraphicsContext()
{
	AMEN_ASSERT(s_instance == nullptr, "Already another instance? This is a singleton!");
	s_instance = this;
}
