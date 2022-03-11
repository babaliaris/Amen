#pragma once
#include <core/core.h>
#include <iostream>
#include <core/events/event.h>

/**
* Root namespace of Amen Engine.
*
*/
namespace Amen
{
	/**
	* The Window Properties.
	* 
	*/
	struct WindowProps
	{
		std::string m_title;
		int m_width;
		int m_height;

		WindowProps(const std::string& title = "Amen Engine", int width = 1024, int height = 720)
			: m_title(title), m_width(width), m_height(height)
		{
		}
	};

	/**
	* Window event callback. Is being used by Amen to propagate the events to the Amen::App class.
	* 
	*/
	using WindowEventCallback = std::function<void(Event&)>;


	/**
	* The Window class.
	* 
	*/
	class AMEN_API Window
	{
		friend class App;

		public:
		virtual ~Window(){}

		/**
		* Set the Window title.
		* 
		* @param title The new title of the Window.
		*/
		virtual void SetTitle(const std::string& title) = 0;

		/**
		* Set the Window width.
		*
		* @param width The new width of the Window.
		*/
		virtual void SetWidth(int width) = 0;

		/**
		* Set the Window height.
		*
		* @param height The new height of the Window.
		*/
		virtual void SetHeight(int height) = 0;

		/**
		* Set the Window size.
		*
		* @param width The new width of the Window.
		* @param height The new height of the Window.
		*/
		virtual void SetSize(int width, int height) = 0;

		/**
		* Set the Window vsync.
		*
		* @param enabled true if enabled, false otherwise.
		*/
		virtual void SetVSync(bool enabled) = 0;


		
		/**
		* Get the width of the Window.
		*
		* @return the Window width.
		*/
		virtual int GetWidth() const = 0;

		/**
		* Get the height of the Window.
		*
		* @return the Window height.
		*/
		virtual int GetHeight() const = 0;

		/**
		* Get the title of the Window.
		*
		* @return the Window title.
		*/
		virtual const std::string& GetTitle() const = 0;


		/**
		* Get the time in seconds.
		*
		* @return the time since the creation in seconds.
		*/
		virtual double GetTime() const = 0;


		/**
		* Get the native window.
		*
		* @return the native window as void *.
		*/
		virtual void* GetNativeWindow() const = 0;

		/**
		* Check if vsync is enabled.
		*
		* @return true if enabled, false otherwise.
		*/
		virtual bool IsVSynced() const = 0;

	protected:
		virtual void Update() = 0;
		virtual void SetEventCallback(WindowEventCallback callback) = 0;
		static Scope<Window> Create(const WindowProps& props = WindowProps());

	protected:
		WindowEventCallback m_eventCallback;
	};
}
