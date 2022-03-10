#include "pch.h"
#include "RendererAPI.h"
#include <core/logger.h>




Amen::RendererAPI* Amen::RendererAPI::s_instance = nullptr;





Amen::RendererAPI::RendererAPI()
{
	AMEN_ASSERT(s_instance == nullptr, "Already another instance? This is a singleton!");
	s_instance = this;
}
