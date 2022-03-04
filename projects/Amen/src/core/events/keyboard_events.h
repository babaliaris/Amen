#pragma once
#include <core/events/event.h>

/**
* Root namespace of Amen Engine.
*
*/
namespace Amen
{
	/**
	* Keyboard Event Class.
	*
	*/
	class AMEN_API KeyboardEvent : public Event
	{
		public:
		inline KeyboardE GetKey() const { return m_key; }

		protected:
		KeyboardEvent(KeyboardE key):m_key(key) {}
		KeyboardE m_key;
	};



	/**
	* Keyboard Key Press Event Class.
	*
	*/
	class AMEN_API KeyboardKeyPressEvent: public KeyboardEvent
	{
		public:
		KeyboardKeyPressEvent(KeyboardE key) : KeyboardEvent(key) {}

		EVENT_IMPLEMENTATION(
			EventTypeE::KeyPressed,
			GetKeyboardKeyMeaning(m_key)
		)
	};



	/**
	* Keyboard Key Repeat Event Class.
	*
	*/
	class AMEN_API KeyboardKeyRepeatEvent : public KeyboardEvent
	{
		public:
		KeyboardKeyRepeatEvent(KeyboardE key, int repeats) : KeyboardEvent(key), m_repeats(repeats) {}

		EVENT_IMPLEMENTATION(
			EventTypeE::KeyRepeat,
			GetKeyboardKeyMeaning(m_key) << " , " << m_repeats << " repeats."
		)

		private:
		int m_repeats;
	};



	/**
	* Keyboard Key Released Event Class.
	*
	*/
	class AMEN_API KeyboardKeyReleasedEvent : public KeyboardEvent
	{
		public:
		KeyboardKeyReleasedEvent(KeyboardE key) : KeyboardEvent(key) {}

		EVENT_IMPLEMENTATION(
			EventTypeE::KeyReleased,
			GetKeyboardKeyMeaning(m_key)
		)

	};
}