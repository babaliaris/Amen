#pragma once

namespace Amen
{
	class GraphicsContext
	{
		public:
			virtual void Init() = 0;
			virtual void SwapBuffers() = 0;

		protected:
			GraphicsContext();

		private:
			static GraphicsContext* s_instance;
	};
}