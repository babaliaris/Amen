#pragma once
#include <core/logger.h>
#include <core/core.h>
#include <core/events/event.h>
#include <GLFW/glfw3.h>

namespace Amen
{
	class GlfwToAmen
	{
		public:

			static KeyboardE KeyToAmen(int glfw_key)
			{
				switch (glfw_key)
				{
					case GLFW_KEY_ESCAPE:
					{
						return Amen::KeyboardE::k_escape;
					}

					case GLFW_KEY_F1:
					{
						return Amen::KeyboardE::k_f1;
					}

					case GLFW_KEY_F2:
					{
						return Amen::KeyboardE::k_f2;
					}

					case GLFW_KEY_F3:
					{
						return Amen::KeyboardE::k_f3;
					}

					case GLFW_KEY_F4:
					{
						return Amen::KeyboardE::k_f4;
					}

					case GLFW_KEY_F5:
					{
						return Amen::KeyboardE::k_f5;
					}

					case GLFW_KEY_F6:
					{
						return Amen::KeyboardE::k_f6;
					}

					case GLFW_KEY_F7:
					{
						return Amen::KeyboardE::k_f7;
					}

					case GLFW_KEY_F8:
					{
						return Amen::KeyboardE::k_f8;
					}

					case GLFW_KEY_F9:
					{
						return Amen::KeyboardE::k_f9;
					}

					case GLFW_KEY_F10:
					{
						return Amen::KeyboardE::k_f10;
					}

					case GLFW_KEY_F11:
					{
						return Amen::KeyboardE::k_f11;
					}

					case GLFW_KEY_F12:
					{
						return Amen::KeyboardE::k_f12;
					}

					case GLFW_KEY_GRAVE_ACCENT:
					{
						return Amen::KeyboardE::k_tilde;
					}

					case GLFW_KEY_1:
					{
						return Amen::KeyboardE::k_1;
					}

					case GLFW_KEY_2:
					{
						return Amen::KeyboardE::k_2;
					}

					case GLFW_KEY_3:
					{
						return Amen::KeyboardE::k_3;
					}

					case GLFW_KEY_4:
					{
						return Amen::KeyboardE::k_4;
					}

					case GLFW_KEY_5:
					{
						return Amen::KeyboardE::k_5;
					}

					case GLFW_KEY_6:
					{
						return Amen::KeyboardE::k_6;
					}

					case GLFW_KEY_7:
					{
						return Amen::KeyboardE::k_7;
					}

					case GLFW_KEY_8:
					{
						return Amen::KeyboardE::k_8;
					}

					case GLFW_KEY_9:
					{
						return Amen::KeyboardE::k_9;
					}

					case GLFW_KEY_0:
					{
						return Amen::KeyboardE::k_0;
					}

					case GLFW_KEY_MINUS:
					{
						return Amen::KeyboardE::k_minus;
					}

					case GLFW_KEY_EQUAL:
					{
						return Amen::KeyboardE::k_plus;
					}

					case GLFW_KEY_BACKSPACE:
					{
						return Amen::KeyboardE::k_backspace;
					}

					case GLFW_KEY_INSERT:
					{
						return Amen::KeyboardE::k_insert;
					}

					case GLFW_KEY_HOME:
					{
						return Amen::KeyboardE::k_home;
					}

					case GLFW_KEY_PAGE_UP:
					{
						return Amen::KeyboardE::k_pageup;
					}

					case GLFW_KEY_TAB:
					{
						return Amen::KeyboardE::k_tab;
					}

					case GLFW_KEY_Q:
					{
						return Amen::KeyboardE::k_q;
					}

					case GLFW_KEY_W:
					{
						return Amen::KeyboardE::k_w;
					}

					case GLFW_KEY_E:
					{
						return Amen::KeyboardE::k_e;
					}

					case GLFW_KEY_R:
					{
						return Amen::KeyboardE::k_r;
					}

					case GLFW_KEY_T:
					{
						return Amen::KeyboardE::k_t;
					}

					case GLFW_KEY_Y:
					{
						return Amen::KeyboardE::k_y;
					}

					case GLFW_KEY_U:
					{
						return Amen::KeyboardE::k_u;
					}

					case GLFW_KEY_I:
					{
						return Amen::KeyboardE::k_i;
					}

					case GLFW_KEY_O:
					{
						return Amen::KeyboardE::k_o;
					}

					case GLFW_KEY_P:
					{
						return Amen::KeyboardE::k_p;
					}

					case GLFW_KEY_LEFT_BRACKET:
					{
						return Amen::KeyboardE::k_left_bracket;
					}

					case GLFW_KEY_RIGHT_BRACKET:
					{
						return Amen::KeyboardE::k_right_bracket;
					}

					case GLFW_KEY_BACKSLASH:
					{
						return Amen::KeyboardE::k_backslash;
					}

					case GLFW_KEY_DELETE:
					{
						return Amen::KeyboardE::k_delet;
					}

					case GLFW_KEY_END:
					{
						return Amen::KeyboardE::k_end;
					}

					case GLFW_KEY_PAGE_DOWN:
					{
						return Amen::KeyboardE::k_pagedown;
					}

					case GLFW_KEY_CAPS_LOCK:
					{
						return Amen::KeyboardE::k_caps;
					}

					case GLFW_KEY_A:
					{
						return Amen::KeyboardE::k_a;
					}

					case GLFW_KEY_S:
					{
						return Amen::KeyboardE::k_s;
					}

					case GLFW_KEY_D:
					{
						return Amen::KeyboardE::k_d;
					}

					case GLFW_KEY_F:
					{
						return Amen::KeyboardE::k_f;
					}

					case GLFW_KEY_G:
					{
						return Amen::KeyboardE::k_g;
					}

					case GLFW_KEY_H:
					{
						return Amen::KeyboardE::k_h;
					}

					case GLFW_KEY_J:
					{
						return Amen::KeyboardE::k_j;
					}

					case GLFW_KEY_K:
					{
						return Amen::KeyboardE::k_k;
					}

					case GLFW_KEY_L:
					{
						return Amen::KeyboardE::k_l;
					}

					case GLFW_KEY_SEMICOLON:
					{
						return Amen::KeyboardE::k_semicolon;
					}

					case GLFW_KEY_APOSTROPHE:
					{
						return Amen::KeyboardE::k_quotes;
					}

					case GLFW_KEY_ENTER:
					{
						return Amen::KeyboardE::k_enter;
					}

					case GLFW_KEY_LEFT_SHIFT:
					{
						return Amen::KeyboardE::k_left_shift;
					}

					case GLFW_KEY_Z:
					{
						return Amen::KeyboardE::k_z;
					}

					case GLFW_KEY_X:
					{
						return Amen::KeyboardE::k_x;
					}

					case GLFW_KEY_C:
					{
						return Amen::KeyboardE::k_c;
					}

					case GLFW_KEY_V:
					{
						return Amen::KeyboardE::k_v;
					}

					case GLFW_KEY_B:
					{
						return Amen::KeyboardE::k_b;
					}

					case GLFW_KEY_N:
					{
						return Amen::KeyboardE::k_n;
					}

					case GLFW_KEY_M:
					{
						return Amen::KeyboardE::k_m;
					}

					case GLFW_KEY_COMMA:
					{
						return Amen::KeyboardE::k_less;
					}

					case GLFW_KEY_PERIOD:
					{
						return Amen::KeyboardE::k_greater;
					}

					case GLFW_KEY_SLASH:
					{
						return Amen::KeyboardE::k_question;
					}

					case GLFW_KEY_RIGHT_SHIFT:
					{
						return Amen::KeyboardE::k_right_shift;
					}

					case GLFW_KEY_UP:
					{
						return Amen::KeyboardE::k_up;
					}

					case GLFW_KEY_LEFT_CONTROL:
					{
						return Amen::KeyboardE::k_left_control;
					}

					case GLFW_KEY_LEFT_SUPER:
					{
						return Amen::KeyboardE::k_super;
					}

					case GLFW_KEY_LEFT_ALT:
					{
						return Amen::KeyboardE::k_left_alt;
					}

					case GLFW_KEY_SPACE:
					{
						return Amen::KeyboardE::k_space;
					}

					case GLFW_KEY_RIGHT_ALT:
					{
						return Amen::KeyboardE::k_right_alt;
					}

					case GLFW_KEY_RIGHT_CONTROL:
					{
						return Amen::KeyboardE::k_right_control;
					}

					case GLFW_KEY_LEFT:
					{
						return Amen::KeyboardE::k_left;
					}

					case GLFW_KEY_DOWN:
					{
						return Amen::KeyboardE::k_down;
					}

					case GLFW_KEY_RIGHT:
					{
						return Amen::KeyboardE::k_right;
					}

					case GLFW_KEY_KP_DIVIDE:
					{
						return Amen::KeyboardE::kp_slash;
					}

					case GLFW_KEY_KP_MULTIPLY:
					{
						return Amen::KeyboardE::kp_asterisk;
					}

					case GLFW_KEY_KP_SUBTRACT:
					{
						return Amen::KeyboardE::kp_minus;
					}

					case GLFW_KEY_KP_ADD:
					{
						return Amen::KeyboardE::kp_plus;
					}

					case GLFW_KEY_KP_ENTER:
					{
						return Amen::KeyboardE::kp_enter;
					}

					case GLFW_KEY_KP_DECIMAL:
					{
						return Amen::KeyboardE::kp_comma;
					}

					case GLFW_KEY_KP_0:
					{
						return Amen::KeyboardE::kp_0;
					}

					case GLFW_KEY_KP_1:
					{
						return Amen::KeyboardE::kp_1;
					}

					case GLFW_KEY_KP_2:
					{
						return Amen::KeyboardE::kp_2;
					}

					case GLFW_KEY_KP_3:
					{
						return Amen::KeyboardE::kp_3;
					}

					case GLFW_KEY_KP_4:
					{
						return Amen::KeyboardE::kp_4;
					}

					case GLFW_KEY_KP_5:
					{
						return Amen::KeyboardE::kp_5;
					}

					case GLFW_KEY_KP_6:
					{
						return Amen::KeyboardE::kp_6;
					}

					case GLFW_KEY_KP_7:
					{
						return Amen::KeyboardE::kp_7;
					}

					case GLFW_KEY_KP_8:
					{
						return Amen::KeyboardE::kp_8;
					}

					case GLFW_KEY_KP_9:
					{
						return Amen::KeyboardE::kp_9;
					}


					default:
					{
						return Amen::KeyboardE::k_uknown;
					}
				}
			}



			static int KeyToGLFW(KeyboardE key)
			{
				AMEN_ASSERT(false, "Not implemented yet");
				return 0;
			}



			static MouseButtonE MouseButtonToAmen(int glfw_button)
			{
				switch (glfw_button)
				{
					case GLFW_MOUSE_BUTTON_1:
						return Amen::MouseButtonE::button_left;

					case GLFW_MOUSE_BUTTON_2:
						return Amen::MouseButtonE::button_right;

					case GLFW_MOUSE_BUTTON_3:
						return Amen::MouseButtonE::button_middle;

					case GLFW_MOUSE_BUTTON_4:
						return Amen::MouseButtonE::button_extra1;

					case GLFW_MOUSE_BUTTON_5:
						return Amen::MouseButtonE::button_extra2;

					default:
						return Amen::MouseButtonE::button_uknown;
				}
			}



			static int MouseButtonToGLFW(MouseButtonE button)
			{
				switch (button)
				{
					case Amen::MouseButtonE::button_left:
						return GLFW_MOUSE_BUTTON_1;

					case Amen::MouseButtonE::button_right:
						return GLFW_MOUSE_BUTTON_2;

					case Amen::MouseButtonE::button_middle:
						return GLFW_MOUSE_BUTTON_3;

					case Amen::MouseButtonE::button_extra1:
						return GLFW_MOUSE_BUTTON_4;

					case Amen::MouseButtonE::button_extra2:
						return GLFW_MOUSE_BUTTON_5;

					default:
						return GLFW_KEY_UNKNOWN;
					}
			}
	};
}