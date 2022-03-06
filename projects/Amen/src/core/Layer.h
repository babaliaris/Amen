#pragma once
#include <string>
#include <core/events/event.h>

/**
* Root namespace of Amen Engine.
*
*/
namespace Amen
{

	/**
	* To use a layer you have
	* 
	*/
	class Layer
	{
		public:

			/**
			* Deconstructor.
			*
			*/
			virtual ~Layer(){}

			/**
			* It's been called every frame.
			*
			*/
			virtual void OnUpdate() {};

			/**
			* It's been called when an event is triggered.
			*
			*/
			virtual void OnEvent(Event& e) {};

			/**
			* It's been called only once.
			*
			*/
			virtual void OnAttach() {};

			/**
			* It's been called only once.
			*
			*/
			virtual void OnDetach() {};



			/**
			* Render Dear ImGui stuff here.
			*
			*/
			virtual void OnImGuiRender() {}

			/**
			* Get a debug layer name.
			*
			* @return A debug string (name) of this layer.
			*/
			inline const std::string& GetDebugName() const { return m_debugName; }

		protected:
			Layer(const std::string& debugName = "Layer") : m_debugName(debugName) {}

		private:
			std::string m_debugName;

	};
}