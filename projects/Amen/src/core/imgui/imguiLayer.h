#pragma once
#include <core/Layer.h>
#include <core/app.h>

/**
* Root namespace of Hazel Engine.
*
*/
namespace Hazel
{

	/**
	* ImguiLayer class. App will handle this class.
	*
	*/
	class AMEN_API ImguiLayer : public Layer
	{
		friend class App;

		public:

			/**
			* Deconstructor..
			*
			*/
			virtual ~ImguiLayer(){}


			/**
			* Begin.
			*
			*/
			virtual void Begin() = 0;


			/**
			* End.
			*
			*/
			virtual void End() = 0;


			/**
			* SetShowDemoWindow.
			*
			*/
			inline void SetShowDemoWindow(bool enabled) { m_showDemoWindow = enabled; }

		protected:
			ImguiLayer() : Layer("ImGui Layer"), m_window(App::Get().GetWindow()) {};


		private:
			static Layer * Create();

		protected:
			Window& m_window;
			bool m_showDemoWindow = true;

	};
}
