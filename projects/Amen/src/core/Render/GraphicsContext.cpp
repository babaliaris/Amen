#include "pch.h"
#include "GraphicsContext.h"
#include <core/logger.h>


Amen::GraphicsContext* Amen::GraphicsContext::s_instance = nullptr;

Amen::GraphicsContext::GraphicsContext()
{
	AMEN_ASSERT(s_instance == nullptr, "Already another instance? This is a singleton!");
	s_instance = this;
}
