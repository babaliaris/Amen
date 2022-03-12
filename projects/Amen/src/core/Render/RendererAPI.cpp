#include "pch.h"
#include "RendererAPI.h"
#include <core/logger.h>




Hazel::RendererAPI* Hazel::RendererAPI::s_instance = nullptr;





Hazel::RendererAPI::RendererAPI()
{
	AMEN_ASSERT(s_instance == nullptr, "Already another instance? This is a singleton!");
	s_instance = this;
}
