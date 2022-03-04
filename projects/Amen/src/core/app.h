#pragma once
#include "core.h"
#include <core/events/event.h>
#include <core/window.h>

/**
* Root namespace of Amen Engine.
* 
*/
namespace Amen
{
	/**
	* The "Main" class for the clients.You have to inherit this class in order
	* to create an application.Then you must implement Amen::CreateApp() to return
	* a new instance of your app.
	*
	* 
	*/
	class AMEN_API App
	{
		protected:

			/**
			* Constructor of Amen::App.
			* 
			*/
			App();

		public:

			/**
			* Deconstructor of Amen::App.
			* 
			*/
			virtual ~App();

			/**
			* Runs the application. You MUST NOT call this.
			* 
			*/
			void Run();

			/**
			* Executes when an event occurs. You MUST NOT call this.
			*
			*/
			void OnEvent(Event& e);

			/**
			* Get the Amen::Window instance.
			*
			* @returns the Amen::Window instance of the application.
			*/
			inline Window& GetWindow() { return *m_window; }

		private:
			bool m_running = true;
			bool m_paused = false;
			Window* m_window;
	};

	/**
	* You must implement this method to return an instance of your own Amen::App subclass.
	* 
	* @returns an Amen::App
	*/
	App* CreateApp();
}