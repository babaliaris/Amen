#pragma once
#include <core/events/Input.h>
#include <core/app.h>

struct GLFWwindow;

namespace Hazel
{
	class GLFWInput: public Input
	{
		public:
			GLFWInput();

			virtual bool GetKeyDownImp(KeyboardE key) override;
			virtual bool GetKeyUpImp(KeyboardE key) override;
			virtual bool GetKeyImp(KeyboardE key) override;

			virtual bool GetButtonDownImp(MouseButtonE button) override;
			virtual bool GetButtonUpImp(MouseButtonE button) override;
			virtual bool GetButtonImp(MouseButtonE button) override;

			virtual std::pair<double, double> GetMousePosImp() override;
			virtual double GetMouseXImp() override;
			virtual double GetMouseYImp() override;

		private:
			GLFWwindow* m_window;
	};
}
