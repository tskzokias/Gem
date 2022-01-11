#pragma once

#include "Event.h"

namespace Gem {

	class GEM_API KeyEvent : public Event // Abstract class
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(const int keycode) // protected constructor, followed up in derived classes, can't create object
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class GEM_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class GEM_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	//class KeyTypedEvent : public KeyEvent
	//{
	//public:
	//	KeyTypedEvent(const int keycode)
	//		: KeyEvent(keycode) {}
	//
	//	std::string ToString() const override
	//	{
	//		std::stringstream ss;
	//		ss << "KeyTypedEvent: " << m_KeyCode;
	//		return ss.str();
	//	}
	//
	//	EVENT_CLASS_TYPE(KeyTyped)
	//};
}