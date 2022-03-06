#pragma once
#include "core.h"
#include <core/events/event.h>
#include <core/window.h>
#include <vector>
#include <core/Layer.h>

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
			* Pushes a layer into the layers stack.
			*
			* @param layer The Amen::Layer to be inserted.
			*/
			void PushLayer(Layer *layer);



			/**
			* Removes a layer from the layers stack.Once you removed it, you are now responsible
			* for it's lifetime.Unless you push it back using Amen::App::PushLayer(Layer *), then you
			* must delete it.
			*
			* @param layer The Amen::Layer to be removed.
			*/
			void RemoveLayer(Layer* layer);


			/**
			* Get the Amen::Window instance.
			*
			* @return the Amen::Window instance of the application.
			*/
			inline Window& GetWindow() { return *m_window; }


			/**
			* Get the Amen::App singleton instance.
			*
			* @return the Amen::App instance.
			*/
			inline static App& Get() { return *s_instance; }


		private:

			/**
			* Executes when an event occurs.
			*
			*/
			void OnEvent(Event& e);


		private:
			bool m_running = true;
			bool m_paused = false;
			Window* m_window;
			std::vector<Layer*> m_layers;

		private:
			static App* s_instance;
	};

	/**
	* You must implement this method to return an instance of your own Amen::App subclass.
	* 
	* @return an Amen::App instance.
	*/
	App* CreateApp();
}