#pragma once
#include <core/Layer.h>
#include <core/app.h>

namespace Amen
{
	class AMEN_API ImguiLayer : public Layer
	{
		public:
			ImguiLayer():Layer("Imgui Layer"), m_window( App::Get().GetWindow() ) {};
			~ImguiLayer();

			void OnUpdate() override;


			void OnEvent(Event& e) override;


			void OnAttach() override;


			void OnDetach() override;

		private:
			Window& m_window;
			bool m_showDemoWindow = true;
	};
}
