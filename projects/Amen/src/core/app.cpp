#include "pch.h"
#include "app.h"
#include <platform/platform.h>
#include <core/logger.h>
#include <core/events/application_events.h>
#include <core/imgui/imguiLayer.h>
#include <core/events/Input.h>
#include <core/Render/Renderer.h>

//-------------------------------Static Initializations-------------------------------//

//s_instance (singleton).
Amen::App* Amen::App::s_instance = nullptr;

//-------------------------------Static Initializations-------------------------------//


Amen::App::App() : m_window(nullptr)
{
	//Get the instance of the app.
	AMEN_ASSERT(s_instance == nullptr, "You can only have one app at a time (singleton).");
	s_instance = this;

	//Initialize the platform.
	Platform::Init();

	//Create the window.
	m_window = Window::Create();

	//Init Input.
	Input::Init();

	//Set the event callback.
	m_window->SetEventCallback(AMEN_BIND(Amen::App::OnEvent));

	//Create the ImGuiLayer.
	m_ImGuiLayer = ImguiLayer::Create();

	//Push the ImGui Layer.
	PushLayer(m_ImGuiLayer);
}




Amen::App::~App()
{
	//Delete the Window.
	delete m_window;

	//Delete all the layers.
	for (Layer* layer : m_layers)
		delete layer;
}




void Amen::App::Run()
{
	//Set the Clear Color to dark gray.
	Renderer::Get().SetClearColor(0.2, 0.2, 0.2, 1);

	while (m_running)
	{
		//Clear the Color Buffer.
		Renderer::Get().ClearColorBuffer();

		//Begin ImGUI Frame.
		static_cast<ImguiLayer *>(m_ImGuiLayer)->Begin();

		//Run all the layers.
		for (Layer *layer : m_layers)
		{
			//If the application if not paused.
			if (!m_paused)
			{
				layer->OnUpdate();
				layer->OnImGuiRender();
			}
		}

		//End ImGUI Frame.
		static_cast<ImguiLayer*>(m_ImGuiLayer)->End();

		//Must be last.
		//Poll the events and swap the buffers.
		m_window->Update();
	}
}





void Amen::App::PushLayer(Layer* layer)
{
	m_layers.push_back(layer);

	layer->OnAttach();
}





void Amen::App::RemoveLayer(Layer* layer)
{
	m_layers.erase( std::remove(m_layers.begin(), m_layers.end(), layer), m_layers.end() );

	layer->OnDetach();
}




void Amen::App::OnEvent(Event& e)
{
	
	EventDispatcher disp(e);

	//On WindowClosedEvent, stop the application.
	disp.Dispatch<WindowClosedEvent>([this](WindowClosedEvent event)
	{	
		m_running = false;
		return true;
	});


	//On WindowMinimizedEvent, pause the application.
	disp.Dispatch<WindowMinimizedEvent>([this](WindowMinimizedEvent event)
	{
		m_paused = true;
		AMEN_INFO("Amen Paused...");
		return true;
	});


	//On WindowRestoredEvent, resume the application.
	disp.Dispatch<WindowRestoredEvent>([this](WindowRestoredEvent event)
	{
		m_paused = false;
		AMEN_INFO("Amen Resumed...");
		return true;
	});


	//Loop through the layers, backwards.
	std::vector<Layer*>::iterator it;
	for (it = m_layers.end(); it != m_layers.begin();)
	{
		//Remember, in the first iteration it=m_layers.end() which
		//does not contain any actual Layer *. I must reduce the iterator
		//first before trying to access a Layer *.
		it--;

		//Propagate the event to that layer.
		(*it)->OnEvent(e);
	}
}
