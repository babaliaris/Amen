#include "pch.h"
#include "app.h"
#include <platform/platform.h>
#include <core/logger.h>
#include <core/events/application_events.h>




Amen::App::App() : m_window(nullptr)
{
	Platform::Init();

	m_window = Window::Create();

	m_window->SetEventCallback(AMEN_BIND(Amen::App::OnEvent));
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
	while (m_running)
	{
		//Run all the layers.
		for (Layer *layer : m_layers)
		{
			if (!m_paused)
				layer->OnUpdate();
		}

		//Must be last.
		//Polls the events and swaps the buffers.
		m_window->Update();
	}

	AMEN_INFO("Amen closes...");
}





void Amen::App::PushLayer(Layer* layer)
{
	m_layers.push_back(layer);

	layer->OnAttach();

	AMEN_INFO("Amen::App::m_layers size: %d", m_layers.size());
}





void Amen::App::RemoveLayer(Layer* layer)
{
	m_layers.erase( std::remove(m_layers.begin(), m_layers.end(), layer), m_layers.end() );

	layer->OnDetach();

	AMEN_INFO("Amen::App::m_layers size: %d", m_layers.size());
	AMEN_WARN("You removed a layer. Do not forget to DELETE it, unlesh you push it back!!!");
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
