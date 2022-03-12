#pragma once
#include <core/events/event.h>

/**
* Root namespace of Hazel Engine.
*
*/
namespace Hazel
{
	/**
	* Window Resized Event Class.
	*
	*/
	class AMEN_API WindowResizedEvent : public Event
	{
		public:
			WindowResizedEvent(int width, int height): m_width(width), m_height(height) {}

			inline int GetWidth() const { return m_width; }
			inline int GetHeight() const { return m_height; }

			EVENT_IMPLEMENTATION(EventTypeE::WindowResized, m_width << " , " << m_height)

		private:
			int m_width, m_height;
	};



	/**
	* Window Moved Event Class.
	*
	*/
	class AMEN_API WindowMovedEvent : public Event
	{
		public:
			WindowMovedEvent(int x, int y) : m_xpos(x), m_ypos(y) {}

			inline int GetX() const { return m_xpos; }
			inline int GetY() const { return m_ypos; }

			EVENT_IMPLEMENTATION(EventTypeE::WindowMoved, m_xpos << " , " << m_ypos)

		private:
			int m_xpos, m_ypos;
	};



	/**
	* Window Focused Event Class.
	*
	*/
	class AMEN_API WindowFocusedEvent: public Event
	{
		public:
			EVENT_IMPLEMENTATION(EventTypeE::WindowFocused, "")
	};


	/**
	* Window Lost Focus Event Class.
	*
	*/
	class AMEN_API WindowLostFocusEvent : public Event
	{
		public:
			EVENT_IMPLEMENTATION(EventTypeE::WindowLostFocus, "")
	};


	/**
	* Window Closed Event Class.
	*
	*/
	class AMEN_API WindowClosedEvent : public Event
	{
		public:
			EVENT_IMPLEMENTATION(EventTypeE::WindowClosed, "")
	};



	/**
	* Window Minimized Event Class.
	*
	*/
	class AMEN_API WindowMinimizedEvent : public Event
	{
		public:
			EVENT_IMPLEMENTATION(EventTypeE::WindowMinimized, "")
	};


	/**
	* Window Restored (after being minimized) Event Class.
	*
	*/
	class AMEN_API WindowRestoredEvent : public Event
	{
		public:
			EVENT_IMPLEMENTATION(EventTypeE::WindowRestored, "")
	};



	/**
	* Window Maximized Event Class.
	*
	*/
	class AMEN_API WindowMaximizedEvent : public Event
	{
		public:
			EVENT_IMPLEMENTATION(EventTypeE::WindowMaximized, "")
	};



	/**
	* Window Titled Changed Event Class.
	*
	*/
	class AMEN_API WindowTitleChangedEvent : public Event
	{
		public:
			WindowTitleChangedEvent(const std::string& title): m_title(title) {}

			inline const std::string& GetTitle() const { return m_title; }

			EVENT_IMPLEMENTATION(EventTypeE::WindowTitleChanged, m_title)

		private:
			std::string m_title;
	};
}