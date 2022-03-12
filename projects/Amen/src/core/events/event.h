#pragma once
#include <iostream>
#include <sstream>
#include <core/core.h>
#include <functional>


/**
* Root namespace of Hazel Engine.
*
*/
namespace Hazel
{

	/**
	* This enum describes the different kind of Events that Hazel can handle.
	*
	*/
	enum class EventTypeE
	{
		UknownEvent,
		WindowResized, WindowMoved, WindowFocused, WindowLostFocus, WindowClosed, WindowTitleChanged,
		WindowMinimized, WindowRestored, WindowMaximized,
		KeyPressed, KeyReleased, KeyRepeat,
		MouseButtonPressed, MouseButtonReleased,
		MouseMoved, MouseScrolled
	};

	/**
	* This enum contains all the different keyboard keys.
	*
	*/
	enum class KeyboardE
	{
		k_uknown,
		k_escape,k_f1, k_f2, k_f3, k_f4, k_f5, k_f6, k_f7, k_f8, k_f9, k_f10, k_f11, k_f12,
		k_tilde, k_1, k_2, k_3, k_4, k_5, k_6, k_7, k_8, k_9, k_0, k_minus, k_plus, k_backspace, k_insert, k_home, k_pageup,
		k_tab, k_q, k_w, k_e, k_r, k_t, k_y, k_u, k_i, k_o, k_p, k_left_bracket, k_right_bracket, k_backslash, k_delet, k_end, k_pagedown,
		k_caps, k_a, k_s, k_d, k_f, k_g, k_h, k_j, k_k, k_l, k_semicolon, k_quotes, k_enter,
		k_left_shift, k_z, k_x, k_c, k_v, k_b, k_n, k_m, k_less, k_greater, k_question, k_right_shift, k_up,
		k_left_control, k_super, k_left_alt, k_space, k_right_alt, k_right_control, k_left, k_down, k_right,
		kp_slash,kp_asterisk,kp_minus,kp_plus,kp_enter,kp_comma,kp_1,kp_2,kp_3,kp_4,kp_5,kp_6,kp_7,kp_8,kp_9,kp_0

	};


	/**
	* This enum contains all the different mouse buttons.
	*
	*/
	enum class MouseButtonE
	{
		button_uknown,
		button_left, button_middle, button_right,
		button_extra1, button_extra2
	};



	/**
	* This macro implements the basic Hazel::Event methods for each subclass.
	* 
	*/
	#define EVENT_IMPLEMENTATION(event_type, debug_sstream)\
		inline static EventTypeE GetStaticType() { return event_type; }\
		inline EventTypeE GetType() const override { return GetStaticType(); };\
		std::string ToString() const override\
		{\
			std::stringstream stream;\
			stream << "(" << AMEN_TOSTRING(event_type) << ") " << debug_sstream;\
			return stream.str();\
		}




	/**
	* This is the base class for all kinds of events.
	*
	*/
	class AMEN_API Event
	{
		friend class EventDispatcher;

		public:

			/**
			* Get the type of this event.
			* 
			* @return the Hazel::EventTypeE of the event.
			* 
			*/
			virtual EventTypeE GetType() const = 0;

			/**
			* Get a string representing this event.
			* 
			* @return the a debug representation of the event.
			*
			*/
			virtual std::string ToString() const = 0;

			/**
			* See if this event was handled.
			* 
			* @return true if this event was handled.
			*
			*/
			inline bool WasHandled() const { return m_handled; }

		protected:

			/**
			* true means that this event will not be propagated further down.
			* 
			*/
			bool m_handled = false; 
	};


	/**
	* Use this class to catch different kind of events.
	* Example usage: EventDispatcher disp(event); disp<WindowClosedEvent>( [this](WindowClosedEvent& event){ //your code here; return handled; } )
	* 
	*/
	class EventDispatcher
	{
		
		public:

			/**
			* Dispatch callback function. This is what you need to pass
			* into the EventDispatcher::Dispatch(DispatchCallback<T>) method.
			* 
			* @return true if this event was handled (This will stop the event propagation).
			*/
			template<typename T>
			using DispatchCallback = std::function<bool(T&)>;

			/**
			* Call this to catch a specific event. The EventDispatcher::DispatchCallback that you provide
			* will be called if the event you are trying to catch has been triggered.
			* 
			*/
			template<typename T>
			void Dispatch(DispatchCallback<T> callback)
			{
				if ( m_event.GetType() == T::GetStaticType() )
				{
					m_event.m_handled = callback(  *(T*)&m_event );
				}
			}

			/**
			* Constructor.
			*/
			EventDispatcher(Event& e):m_event(e){}

		private:
			Event& m_event;
	};

	/**
	* Get the meaning of a Hazel::KeyboardE key.
	* 
	* @return The std::string representation of the Hazel::KeyboardE key.
	*/
	std::string GetKeyboardKeyMeaning(KeyboardE key);

	/**
	* Get the meaning of a Hazel::MouseButtonE button.
	*
	* @return The std::string representation of the Hazel::MouseButtonE button.
	*/
	std::string GetMouseButtonMeaning(MouseButtonE button);
}