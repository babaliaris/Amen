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
	delete m_window;
}




void Amen::App::Run()
{
	while (m_running)
	{
		m_window->Update();
	}

	AMEN_INFO("Amen closes...");
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
}
