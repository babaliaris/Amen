#pragma once
#include <core/events/event.h>

namespace Amen
{
	/**
	* Mouse Button Event Class.
	*
	*/
	class AMEN_API MouseButtonEvent: public Event
	{
		public:
			inline MouseButtonE GetButton() const { return m_button; }


		protected:
			MouseButtonEvent(MouseButtonE btn): m_button(btn){}
			MouseButtonE m_button;
	};



	/**
	* Mouse Button Pressed Event Class.
	*
	*/
	class AMEN_API MouseButonPressedEvent: public MouseButtonEvent
	{
		public:
			MouseButonPressedEvent(MouseButtonE btn): MouseButtonEvent(btn){}

			EVENT_IMPLEMENTATION(EventTypeE::MouseButtonPressed, GetMouseButtonMeaning(m_button))

	};



	/**
	* Mouse Button Released Event Class.
	*
	*/
	class AMEN_API MouseButonReleasedEvent : public MouseButtonEvent
	{
		public:
			MouseButonReleasedEvent(MouseButtonE btn) : MouseButtonEvent(btn) {}

			EVENT_IMPLEMENTATION(EventTypeE::MouseButtonReleased, GetMouseButtonMeaning(m_button))

	};



	/**
	* Mouse Button Scrolled Event Class.
	*
	*/
	class AMEN_API MouseScrolledEvent: public Event
	{
		public:
			MouseScrolledEvent(double xoffset, double yoffset):m_xOffsset(xoffset), m_yOffset(yoffset) {}

			inline double GetXOffset() const { return m_xOffsset; }
			inline double GetYOffset() const { return m_yOffset; }

			EVENT_IMPLEMENTATION(EventTypeE::MouseScrolled, "xoffset: " << m_xOffsset << " , yoffset: " << m_yOffset)

		private:
			double m_xOffsset, m_yOffset;
	};



	/**
	* Mouse Button Moved Event Class.
	*
	*/
	class AMEN_API MouseMovedEvent : public Event
	{
		public:
			MouseMovedEvent(double xoffset, double yoffset) :m_xOffsset(xoffset), m_yOffset(yoffset) {}

			inline double GetXOffset() const { return m_xOffsset; }
			inline double GetYOffset() const { return m_yOffset; }

			EVENT_IMPLEMENTATION(EventTypeE::MouseMoved, "xpos: " << m_xOffsset << " , ypos: " << m_yOffset)

		private:
			double m_xOffsset, m_yOffset;
	};
}