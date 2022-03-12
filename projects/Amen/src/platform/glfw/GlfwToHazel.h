#pragma once
#include <core/logger.h>
#include <core/core.h>
#include <core/events/event.h>
#include <GLFW/glfw3.h>

namespace Hazel
{
	class GlfwToHazel
	{
		public:

			static KeyboardE KeyToHazel(int glfw_key)
			{
				switch (glfw_key)
				{
					case GLFW_KEY_ESCAPE:
					{
						return Hazel::KeyboardE::k_escape;
					}

					case GLFW_KEY_F1:
					{
						return Hazel::KeyboardE::k_f1;
					}

					case GLFW_KEY_F2:
					{
						return Hazel::KeyboardE::k_f2;
					}

					case GLFW_KEY_F3:
					{
						return Hazel::KeyboardE::k_f3;
					}

					case GLFW_KEY_F4:
					{
						return Hazel::KeyboardE::k_f4;
					}

					case GLFW_KEY_F5:
					{
						return Hazel::KeyboardE::k_f5;
					}

					case GLFW_KEY_F6:
					{
						return Hazel::KeyboardE::k_f6;
					}

					case GLFW_KEY_F7:
					{
						return Hazel::KeyboardE::k_f7;
					}

					case GLFW_KEY_F8:
					{
						return Hazel::KeyboardE::k_f8;
					}

					case GLFW_KEY_F9:
					{
						return Hazel::KeyboardE::k_f9;
					}

					case GLFW_KEY_F10:
					{
						return Hazel::KeyboardE::k_f10;
					}

					case GLFW_KEY_F11:
					{
						return Hazel::KeyboardE::k_f11;
					}

					case GLFW_KEY_F12:
					{
						return Hazel::KeyboardE::k_f12;
					}

					case GLFW_KEY_GRAVE_ACCENT:
					{
						return Hazel::KeyboardE::k_tilde;
					}

					case GLFW_KEY_1:
					{
						return Hazel::KeyboardE::k_1;
					}

					case GLFW_KEY_2:
					{
						return Hazel::KeyboardE::k_2;
					}

					case GLFW_KEY_3:
					{
						return Hazel::KeyboardE::k_3;
					}

					case GLFW_KEY_4:
					{
						return Hazel::KeyboardE::k_4;
					}

					case GLFW_KEY_5:
					{
						return Hazel::KeyboardE::k_5;
					}

					case GLFW_KEY_6:
					{
						return Hazel::KeyboardE::k_6;
					}

					case GLFW_KEY_7:
					{
						return Hazel::KeyboardE::k_7;
					}

					case GLFW_KEY_8:
					{
						return Hazel::KeyboardE::k_8;
					}

					case GLFW_KEY_9:
					{
						return Hazel::KeyboardE::k_9;
					}

					case GLFW_KEY_0:
					{
						return Hazel::KeyboardE::k_0;
					}

					case GLFW_KEY_MINUS:
					{
						return Hazel::KeyboardE::k_minus;
					}

					case GLFW_KEY_EQUAL:
					{
						return Hazel::KeyboardE::k_plus;
					}

					case GLFW_KEY_BACKSPACE:
					{
						return Hazel::KeyboardE::k_backspace;
					}

					case GLFW_KEY_INSERT:
					{
						return Hazel::KeyboardE::k_insert;
					}

					case GLFW_KEY_HOME:
					{
						return Hazel::KeyboardE::k_home;
					}

					case GLFW_KEY_PAGE_UP:
					{
						return Hazel::KeyboardE::k_pageup;
					}

					case GLFW_KEY_TAB:
					{
						return Hazel::KeyboardE::k_tab;
					}

					case GLFW_KEY_Q:
					{
						return Hazel::KeyboardE::k_q;
					}

					case GLFW_KEY_W:
					{
						return Hazel::KeyboardE::k_w;
					}

					case GLFW_KEY_E:
					{
						return Hazel::KeyboardE::k_e;
					}

					case GLFW_KEY_R:
					{
						return Hazel::KeyboardE::k_r;
					}

					case GLFW_KEY_T:
					{
						return Hazel::KeyboardE::k_t;
					}

					case GLFW_KEY_Y:
					{
						return Hazel::KeyboardE::k_y;
					}

					case GLFW_KEY_U:
					{
						return Hazel::KeyboardE::k_u;
					}

					case GLFW_KEY_I:
					{
						return Hazel::KeyboardE::k_i;
					}

					case GLFW_KEY_O:
					{
						return Hazel::KeyboardE::k_o;
					}

					case GLFW_KEY_P:
					{
						return Hazel::KeyboardE::k_p;
					}

					case GLFW_KEY_LEFT_BRACKET:
					{
						return Hazel::KeyboardE::k_left_bracket;
					}

					case GLFW_KEY_RIGHT_BRACKET:
					{
						return Hazel::KeyboardE::k_right_bracket;
					}

					case GLFW_KEY_BACKSLASH:
					{
						return Hazel::KeyboardE::k_backslash;
					}

					case GLFW_KEY_DELETE:
					{
						return Hazel::KeyboardE::k_delet;
					}

					case GLFW_KEY_END:
					{
						return Hazel::KeyboardE::k_end;
					}

					case GLFW_KEY_PAGE_DOWN:
					{
						return Hazel::KeyboardE::k_pagedown;
					}

					case GLFW_KEY_CAPS_LOCK:
					{
						return Hazel::KeyboardE::k_caps;
					}

					case GLFW_KEY_A:
					{
						return Hazel::KeyboardE::k_a;
					}

					case GLFW_KEY_S:
					{
						return Hazel::KeyboardE::k_s;
					}

					case GLFW_KEY_D:
					{
						return Hazel::KeyboardE::k_d;
					}

					case GLFW_KEY_F:
					{
						return Hazel::KeyboardE::k_f;
					}

					case GLFW_KEY_G:
					{
						return Hazel::KeyboardE::k_g;
					}

					case GLFW_KEY_H:
					{
						return Hazel::KeyboardE::k_h;
					}

					case GLFW_KEY_J:
					{
						return Hazel::KeyboardE::k_j;
					}

					case GLFW_KEY_K:
					{
						return Hazel::KeyboardE::k_k;
					}

					case GLFW_KEY_L:
					{
						return Hazel::KeyboardE::k_l;
					}

					case GLFW_KEY_SEMICOLON:
					{
						return Hazel::KeyboardE::k_semicolon;
					}

					case GLFW_KEY_APOSTROPHE:
					{
						return Hazel::KeyboardE::k_quotes;
					}

					case GLFW_KEY_ENTER:
					{
						return Hazel::KeyboardE::k_enter;
					}

					case GLFW_KEY_LEFT_SHIFT:
					{
						return Hazel::KeyboardE::k_left_shift;
					}

					case GLFW_KEY_Z:
					{
						return Hazel::KeyboardE::k_z;
					}

					case GLFW_KEY_X:
					{
						return Hazel::KeyboardE::k_x;
					}

					case GLFW_KEY_C:
					{
						return Hazel::KeyboardE::k_c;
					}

					case GLFW_KEY_V:
					{
						return Hazel::KeyboardE::k_v;
					}

					case GLFW_KEY_B:
					{
						return Hazel::KeyboardE::k_b;
					}

					case GLFW_KEY_N:
					{
						return Hazel::KeyboardE::k_n;
					}

					case GLFW_KEY_M:
					{
						return Hazel::KeyboardE::k_m;
					}

					case GLFW_KEY_COMMA:
					{
						return Hazel::KeyboardE::k_less;
					}

					case GLFW_KEY_PERIOD:
					{
						return Hazel::KeyboardE::k_greater;
					}

					case GLFW_KEY_SLASH:
					{
						return Hazel::KeyboardE::k_question;
					}

					case GLFW_KEY_RIGHT_SHIFT:
					{
						return Hazel::KeyboardE::k_right_shift;
					}

					case GLFW_KEY_UP:
					{
						return Hazel::KeyboardE::k_up;
					}

					case GLFW_KEY_LEFT_CONTROL:
					{
						return Hazel::KeyboardE::k_left_control;
					}

					case GLFW_KEY_LEFT_SUPER:
					{
						return Hazel::KeyboardE::k_super;
					}

					case GLFW_KEY_LEFT_ALT:
					{
						return Hazel::KeyboardE::k_left_alt;
					}

					case GLFW_KEY_SPACE:
					{
						return Hazel::KeyboardE::k_space;
					}

					case GLFW_KEY_RIGHT_ALT:
					{
						return Hazel::KeyboardE::k_right_alt;
					}

					case GLFW_KEY_RIGHT_CONTROL:
					{
						return Hazel::KeyboardE::k_right_control;
					}

					case GLFW_KEY_LEFT:
					{
						return Hazel::KeyboardE::k_left;
					}

					case GLFW_KEY_DOWN:
					{
						return Hazel::KeyboardE::k_down;
					}

					case GLFW_KEY_RIGHT:
					{
						return Hazel::KeyboardE::k_right;
					}

					case GLFW_KEY_KP_DIVIDE:
					{
						return Hazel::KeyboardE::kp_slash;
					}

					case GLFW_KEY_KP_MULTIPLY:
					{
						return Hazel::KeyboardE::kp_asterisk;
					}

					case GLFW_KEY_KP_SUBTRACT:
					{
						return Hazel::KeyboardE::kp_minus;
					}

					case GLFW_KEY_KP_ADD:
					{
						return Hazel::KeyboardE::kp_plus;
					}

					case GLFW_KEY_KP_ENTER:
					{
						return Hazel::KeyboardE::kp_enter;
					}

					case GLFW_KEY_KP_DECIMAL:
					{
						return Hazel::KeyboardE::kp_comma;
					}

					case GLFW_KEY_KP_0:
					{
						return Hazel::KeyboardE::kp_0;
					}

					case GLFW_KEY_KP_1:
					{
						return Hazel::KeyboardE::kp_1;
					}

					case GLFW_KEY_KP_2:
					{
						return Hazel::KeyboardE::kp_2;
					}

					case GLFW_KEY_KP_3:
					{
						return Hazel::KeyboardE::kp_3;
					}

					case GLFW_KEY_KP_4:
					{
						return Hazel::KeyboardE::kp_4;
					}

					case GLFW_KEY_KP_5:
					{
						return Hazel::KeyboardE::kp_5;
					}

					case GLFW_KEY_KP_6:
					{
						return Hazel::KeyboardE::kp_6;
					}

					case GLFW_KEY_KP_7:
					{
						return Hazel::KeyboardE::kp_7;
					}

					case GLFW_KEY_KP_8:
					{
						return Hazel::KeyboardE::kp_8;
					}

					case GLFW_KEY_KP_9:
					{
						return Hazel::KeyboardE::kp_9;
					}


					default:
					{
						return Hazel::KeyboardE::k_uknown;
					}
				}
			}



			static int KeyToGLFW(KeyboardE key)
			{
				switch (key)
				{
					case Hazel::KeyboardE::k_uknown:
						return GLFW_KEY_U;
					case Hazel::KeyboardE::k_escape:
						return GLFW_KEY_ESCAPE;
					case Hazel::KeyboardE::k_f1:
						return GLFW_KEY_F1;
					case Hazel::KeyboardE::k_f2:
						return GLFW_KEY_F2;
					case Hazel::KeyboardE::k_f3:
						return GLFW_KEY_F3;
					case Hazel::KeyboardE::k_f4:
						return GLFW_KEY_F4;
					case Hazel::KeyboardE::k_f5:
						return GLFW_KEY_F5;
					case Hazel::KeyboardE::k_f6:
						return GLFW_KEY_F6;
					case Hazel::KeyboardE::k_f7:
						return GLFW_KEY_F7;
					case Hazel::KeyboardE::k_f8:
						return GLFW_KEY_F8;
					case Hazel::KeyboardE::k_f9:
						return GLFW_KEY_F9;
					case Hazel::KeyboardE::k_f10:
						return GLFW_KEY_F10;
					case Hazel::KeyboardE::k_f11:
						return GLFW_KEY_F11;
					case Hazel::KeyboardE::k_f12:
						return GLFW_KEY_F12;
					case Hazel::KeyboardE::k_tilde:
						return GLFW_KEY_GRAVE_ACCENT;
					case Hazel::KeyboardE::k_1:
						return GLFW_KEY_1;
					case Hazel::KeyboardE::k_2:
						return GLFW_KEY_2;
					case Hazel::KeyboardE::k_3:
						return GLFW_KEY_3;
					case Hazel::KeyboardE::k_4:
						return GLFW_KEY_4;
					case Hazel::KeyboardE::k_5:
						return GLFW_KEY_5;
					case Hazel::KeyboardE::k_6:
						return GLFW_KEY_6;
					case Hazel::KeyboardE::k_7:
						return GLFW_KEY_7;
					case Hazel::KeyboardE::k_8:
						return GLFW_KEY_8;
					case Hazel::KeyboardE::k_9:
						return GLFW_KEY_9;
					case Hazel::KeyboardE::k_0:
						return GLFW_KEY_0;
					case Hazel::KeyboardE::k_minus:
						return GLFW_KEY_MINUS;
					case Hazel::KeyboardE::k_plus:
						return GLFW_KEY_EQUAL;
					case Hazel::KeyboardE::k_backspace:
						return GLFW_KEY_BACKSPACE;
					case Hazel::KeyboardE::k_insert:
						return GLFW_KEY_INSERT;
					case Hazel::KeyboardE::k_home:
						return GLFW_KEY_HOME;
					case Hazel::KeyboardE::k_pageup:
						return GLFW_KEY_PAGE_UP;
					case Hazel::KeyboardE::k_tab:
						return GLFW_KEY_TAB;
					case Hazel::KeyboardE::k_q:
						return GLFW_KEY_Q;
					case Hazel::KeyboardE::k_w:
						return GLFW_KEY_W;
					case Hazel::KeyboardE::k_e:
						return GLFW_KEY_E;
					case Hazel::KeyboardE::k_r:
						return GLFW_KEY_R;
					case Hazel::KeyboardE::k_t:
						return GLFW_KEY_T;
					case Hazel::KeyboardE::k_y:
						return GLFW_KEY_Y;
					case Hazel::KeyboardE::k_u:
						return GLFW_KEY_U;
					case Hazel::KeyboardE::k_i:
						return GLFW_KEY_I;
					case Hazel::KeyboardE::k_o:
						return GLFW_KEY_O;
					case Hazel::KeyboardE::k_p:
						return GLFW_KEY_P;
					case Hazel::KeyboardE::k_left_bracket:
						return GLFW_KEY_LEFT_BRACKET;
					case Hazel::KeyboardE::k_right_bracket:
						return GLFW_KEY_RIGHT_BRACKET;
					case Hazel::KeyboardE::k_backslash:
						return GLFW_KEY_BACKSLASH;
					case Hazel::KeyboardE::k_delet:
						return GLFW_KEY_DELETE;
					case Hazel::KeyboardE::k_end:
						return GLFW_KEY_END;
					case Hazel::KeyboardE::k_pagedown:
						return GLFW_KEY_PAGE_DOWN;
					case Hazel::KeyboardE::k_caps:
						return GLFW_KEY_CAPS_LOCK;
					case Hazel::KeyboardE::k_a:
						return GLFW_KEY_A;
					case Hazel::KeyboardE::k_s:
						return GLFW_KEY_S;
					case Hazel::KeyboardE::k_d:
						return GLFW_KEY_D;
					case Hazel::KeyboardE::k_f:
						return GLFW_KEY_F;
					case Hazel::KeyboardE::k_g:
						return GLFW_KEY_G;
					case Hazel::KeyboardE::k_h:
						return GLFW_KEY_H;
					case Hazel::KeyboardE::k_j:
						return GLFW_KEY_J;
					case Hazel::KeyboardE::k_k:
						return GLFW_KEY_K;
					case Hazel::KeyboardE::k_l:
						return GLFW_KEY_L;
					case Hazel::KeyboardE::k_semicolon:
						return GLFW_KEY_SEMICOLON;
					case Hazel::KeyboardE::k_quotes:
						return GLFW_KEY_APOSTROPHE;
					case Hazel::KeyboardE::k_enter:
						return GLFW_KEY_ENTER;
					case Hazel::KeyboardE::k_left_shift:
						return GLFW_KEY_LEFT_SHIFT;
					case Hazel::KeyboardE::k_z:
						return GLFW_KEY_Z;
					case Hazel::KeyboardE::k_x:
						return GLFW_KEY_X;
					case Hazel::KeyboardE::k_c:
						return GLFW_KEY_C;
					case Hazel::KeyboardE::k_v:
						return GLFW_KEY_V;
					case Hazel::KeyboardE::k_b:
						return GLFW_KEY_B;
					case Hazel::KeyboardE::k_n:
						return GLFW_KEY_N;
					case Hazel::KeyboardE::k_m:
						return GLFW_KEY_M;
					case Hazel::KeyboardE::k_less:
						return GLFW_KEY_COMMA;
					case Hazel::KeyboardE::k_greater:
						return GLFW_KEY_PERIOD;
					case Hazel::KeyboardE::k_question:
						return GLFW_KEY_SLASH;
					case Hazel::KeyboardE::k_right_shift:
						return GLFW_KEY_RIGHT_SHIFT;
					case Hazel::KeyboardE::k_up:
						return GLFW_KEY_UP;
					case Hazel::KeyboardE::k_left_control:
						return GLFW_KEY_LEFT_CONTROL;
					case Hazel::KeyboardE::k_super:
						return GLFW_KEY_LEFT_SUPER;
					case Hazel::KeyboardE::k_left_alt:
						return GLFW_KEY_LEFT_ALT;
					case Hazel::KeyboardE::k_space:
						return GLFW_KEY_SPACE;
					case Hazel::KeyboardE::k_right_alt:
						return GLFW_KEY_RIGHT_ALT;
					case Hazel::KeyboardE::k_right_control:
						return GLFW_KEY_RIGHT_CONTROL;
					case Hazel::KeyboardE::k_left:
						return GLFW_KEY_LEFT;
					case Hazel::KeyboardE::k_down:
						return GLFW_KEY_DOWN;
					case Hazel::KeyboardE::k_right:
						return GLFW_KEY_RIGHT;
					case Hazel::KeyboardE::kp_slash:
						return GLFW_KEY_KP_DIVIDE;
					case Hazel::KeyboardE::kp_asterisk:
						return GLFW_KEY_KP_MULTIPLY;
					case Hazel::KeyboardE::kp_minus:
						return GLFW_KEY_KP_SUBTRACT;
					case Hazel::KeyboardE::kp_plus:
						return GLFW_KEY_KP_ADD;
					case Hazel::KeyboardE::kp_enter:
						return GLFW_KEY_KP_ENTER;
					case Hazel::KeyboardE::kp_comma:
						return GLFW_KEY_KP_DECIMAL;
					case Hazel::KeyboardE::kp_1:
						return GLFW_KEY_KP_1;
					case Hazel::KeyboardE::kp_2:
						return GLFW_KEY_KP_2;
					case Hazel::KeyboardE::kp_3:
						return GLFW_KEY_KP_3;
					case Hazel::KeyboardE::kp_4:
						return GLFW_KEY_KP_4;
					case Hazel::KeyboardE::kp_5:
						return GLFW_KEY_KP_5;
					case Hazel::KeyboardE::kp_6:
						return GLFW_KEY_KP_6;
					case Hazel::KeyboardE::kp_7:
						return GLFW_KEY_KP_7;
					case Hazel::KeyboardE::kp_8:
						return GLFW_KEY_KP_8;
					case Hazel::KeyboardE::kp_9:
						return GLFW_KEY_KP_9;
					case Hazel::KeyboardE::kp_0:
						return GLFW_KEY_KP_0;
					default:
					{
						AMEN_ASSERT(false, "This line should not be reached...");
						return GLFW_KEY_UNKNOWN;
					}
				}
			}



			static MouseButtonE MouseButtonToHazel(int glfw_button)
			{
				switch (glfw_button)
				{
					case GLFW_MOUSE_BUTTON_1:
						return Hazel::MouseButtonE::button_left;

					case GLFW_MOUSE_BUTTON_2:
						return Hazel::MouseButtonE::button_right;

					case GLFW_MOUSE_BUTTON_3:
						return Hazel::MouseButtonE::button_middle;

					case GLFW_MOUSE_BUTTON_4:
						return Hazel::MouseButtonE::button_extra1;

					case GLFW_MOUSE_BUTTON_5:
						return Hazel::MouseButtonE::button_extra2;

					default:
					{
						AMEN_ASSERT(false, "This line should not be reached...");
						return Hazel::MouseButtonE::button_uknown;
					}
				}
			}



			static int MouseButtonToGLFW(MouseButtonE button)
			{
				switch (button)
				{
					case Hazel::MouseButtonE::button_left:
						return GLFW_MOUSE_BUTTON_1;

					case Hazel::MouseButtonE::button_right:
						return GLFW_MOUSE_BUTTON_2;

					case Hazel::MouseButtonE::button_middle:
						return GLFW_MOUSE_BUTTON_3;

					case Hazel::MouseButtonE::button_extra1:
						return GLFW_MOUSE_BUTTON_4;

					case Hazel::MouseButtonE::button_extra2:
						return GLFW_MOUSE_BUTTON_5;

					default:
					{
						AMEN_ASSERT(false, "This line should not be reached...");
						return GLFW_KEY_UNKNOWN;
					}
				}
			}
	};
}