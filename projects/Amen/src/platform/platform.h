#pragma once
#include <core/core.h>

namespace Hazel
{
	enum class PlatformTypeE
	{
		WINDOWS,
		LINUX
	};



	class AMEN_API Platform
	{

		public:

		/**
		* Initialize the platform on compilation.
		*/
		static void Init();

		/**
		* @return The PlatformTypeE.
		*/
		inline static PlatformTypeE GetPlatformType() { return s_type; }

		private:
		static PlatformTypeE s_type;

	};
}
