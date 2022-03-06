#pragma once
#include <core/Layer.h>
#include <core/app.h>

/**
* Root namespace of Amen Engine.
*
*/
namespace Amen
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

		protected:
			ImguiLayer() : Layer("ImGui Layer"), m_window(App::Get().GetWindow()) {};


		private:
			static Layer* Create();

		protected:
			Window& m_window;
			bool m_showDemoWindow = true;

	};
}
