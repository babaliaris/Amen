#pragma once
#include <core/imgui/imguiLayer.h>

namespace Amen
{
	class ImGuiGLFWLayer : public ImguiLayer
	{
		public:

			ImGuiGLFWLayer();

			~ImGuiGLFWLayer();

			void OnUpdate() override;

			void OnAttach() override;
	};
}
