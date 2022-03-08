#pragma once

namespace Amen
{
	class Renderer
	{
		public:
			inline static Renderer& Get() { return *s_instance; }

		public:
			virtual void SetClearColor(float r, float g, float b, float a) = 0;
			virtual void ClearColorBuffer() = 0;


		protected:
			Renderer();

		private:
			static Renderer* s_instance;
	};
}
