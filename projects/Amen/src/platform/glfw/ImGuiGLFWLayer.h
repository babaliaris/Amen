#pragma once
#include <core/imgui/imguiLayer.h>

namespace Amen
{
	class ImGuiGLFWLayer : public ImguiLayer
	{
		public:

			ImGuiGLFWLayer();

			~ImGuiGLFWLayer();

			virtual void OnAttach() override;

			virtual void Begin() override;

			virtual void End() override;

			virtual void OnImGuiRender() override;
	};
}
