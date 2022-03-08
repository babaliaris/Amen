#include "pch.h"
#include "Renderer.h"
#include <core/logger.h>




Amen::Renderer* Amen::Renderer::s_instance = nullptr;





Amen::Renderer::Renderer()
{
	AMEN_ASSERT(s_instance == nullptr, "Already another instance? This is a singleton!");
	s_instance = this;
}
