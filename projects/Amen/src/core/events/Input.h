#pragma once
#include "event.h"

namespace Amen
{
	class AMEN_API Input
	{
		friend class App;

		public:
			static bool GetKeyDown(KeyboardE key) { return s_instance->GetKeyDownImp(key); }
			static bool GetKeyUp(KeyboardE key) { return s_instance->GetKeyUpImp(key); }
			static bool GetKey(KeyboardE key) { return s_instance->GetKeyImp(key); }

			static bool GetButtonDown(MouseButtonE button) { return s_instance->GetButtonDownImp(button); }
			static bool GetButtonUp(MouseButtonE button) { return s_instance->GetButtonUpImp(button); }
			static bool GetButton(MouseButtonE button) { return s_instance->GetButtonImp(button); }

			static std::pair<double, double> GetMousePos() { return s_instance->GetMousePosImp(); }
			static double GetMouseX() { return s_instance->GetMouseXImp(); }
			static double GetMouseY() { return s_instance->GetMouseYImp(); }

		protected:

			virtual bool GetKeyDownImp(KeyboardE key) = 0;
			virtual bool GetKeyUpImp(KeyboardE key) = 0;
			virtual bool GetKeyImp(KeyboardE key) = 0;

			virtual bool GetButtonDownImp(MouseButtonE button) = 0;
			virtual bool GetButtonUpImp(MouseButtonE button) = 0;
			virtual bool GetButtonImp(MouseButtonE button) = 0;

			virtual std::pair<double, double> GetMousePosImp() = 0;
			virtual double GetMouseXImp() = 0;
			virtual double GetMouseYImp() = 0;

		private:
			static void Init();

		private:
			static Input *s_instance;

	};
}
