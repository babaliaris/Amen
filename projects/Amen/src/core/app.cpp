#include "pch.h"
#include "app.h"
#include <platform/platform.h>
#include <core/logger.h>
#include <core/events/application_events.h>
#include <core/imgui/imguiLayer.h>
#include <core/events/Input.h>

#include <core/Render/Shader.h>
#include <core/Render/RendererCommand.h>
#include <core/Render/Buffer.h>
#include <core/Render/Renderer.h>
#include <core/Render/Cameras/OrthographicCamera.h>

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

	//Disable ImGui Demo Window.
	static_cast<ImguiLayer*>(m_ImGuiLayer)->SetShowDemoWindow(false);

	//Push the ImGui Layer.
	PushLayer(m_ImGuiLayer);
}




Amen::App::~App()
{
	//Delete all the layers.
	for (Layer* layer : m_layers)
		delete layer;
}



void Amen::App::Run()
{

	double currentTime = 0.0f;
	double prevTime = 0.0f;

	float vertexData[] =
	{
		//Positions				//Colors			//Texture Coordinates
		-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	0.0f, 0.0f,	//0
		 0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 0.0f,	//1
		 0.0f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f,	0.5f, 0.5f	//2
	};

	unsigned int indexData[] =
	{
		2, 1, 0
	};

	BufferLayout layout = {
		{"Positions", ShaderType::FLOAT3},
		{"Colors", ShaderType::FLOAT3},
		{"Texture Coordinates", ShaderType::FLOAT2}
	};

	Ref<VertexBuffer> vertexBuffer = VertexBuffer::Create(vertexData, sizeof(vertexData));
	vertexBuffer->SetLayout(layout);

	Ref<IndexBuffer> indexBuffer = IndexBuffer::Create(indexData, 3);
	Ref<ArrayBuffer> arrayBuffer = ArrayBuffer::Create(vertexBuffer, indexBuffer);

	Ref<Shader> shader = Shader::Create(AMEN_RELATIVE("resources/OpenGLShaders/mv_triangle.glsl"));

	Camera::OrthographicProps props = { 0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f };
	OrthographicCamera camera(props);
	camera.SetMovementSpeed(3.0f);
	camera.SetRotationSpeed(40.0f);

	//Set the Clear Color to dark gray.
	RendererCommand::SetClearColor(0.2, 0.2, 0.2, 1);

	//Set the viewport.
	RendererCommand::SetViewport(0, 0, m_window->GetWidth(), m_window->GetHeight());

	while (m_running)
	{
		//Calculate the delta time timesptep.
		currentTime = m_window->GetTime();
		Timestep deltaTime(currentTime - prevTime);
		prevTime = currentTime;

		//Clear the Color Buffer.
		RendererCommand::ClearColorBuffer();

		//Begin ImGUI Frame.
		static_cast<ImguiLayer *>(m_ImGuiLayer)->Begin();

		//Run all the layers.
		for (Layer *layer : m_layers)
		{
			//If the application if not paused.
			if (!m_paused)
			{
				layer->OnUpdate(deltaTime);
				layer->OnImGuiRender();
			}
		}

		//End ImGUI Frame.
		static_cast<ImguiLayer*>(m_ImGuiLayer)->End();

		if (Input::GetKeyDown(KeyboardE::k_up))
		{
			AMEN_INFO("Camera::MovementE::FORWARD");
			camera.Move(Camera::MovementE::FORWARD, deltaTime);
		}

		if (Input::GetKeyDown(KeyboardE::k_down))
		{
			AMEN_INFO("Camera::MovementE::BACKWARD");
			camera.Move(Camera::MovementE::BACKWARD, deltaTime);
		}

		if (Input::GetKeyDown(KeyboardE::k_left))
		{
			AMEN_INFO("Camera::MovementE::LEFT");
			camera.Move(Camera::MovementE::LEFT, deltaTime);
		}

		if (Input::GetKeyDown(KeyboardE::k_right))
		{
			AMEN_INFO("Camera::MovementE::RIGHT");
			camera.Move(Camera::MovementE::RIGHT, deltaTime);
		}

		if (Input::GetKeyDown(KeyboardE::kp_4))
		{
			AMEN_INFO("Camera::MovementE::ROLL_LEFT");
			camera.Move(Camera::MovementE::ROLL_LEFT, deltaTime);
		}

		if (Input::GetKeyDown(KeyboardE::kp_6))
		{
			AMEN_INFO("Camera::MovementE::ROLL_RIGHT");
			camera.Move(Camera::MovementE::ROLL_RIGHT, deltaTime);
		}

		Renderer::BeginScene(camera);
		Renderer::Submit(shader, arrayBuffer);
		Renderer::EndScene();

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
		return false;
	});


	//On WindowMinimizedEvent, pause the application.
	disp.Dispatch<WindowMinimizedEvent>([this](WindowMinimizedEvent event)
	{
		m_paused = true;
		AMEN_INFO("Amen Paused...");
		return false;
	});


	//On WindowRestoredEvent, resume the application.
	disp.Dispatch<WindowRestoredEvent>([this](WindowRestoredEvent event)
	{
		m_paused = false;
		AMEN_INFO("Amen Resumed...");
		return false;
	});


	//On WindowResizedEvent, set the viewport.
	disp.Dispatch<WindowResizedEvent>([this](WindowResizedEvent event)
	{
		RendererCommand::SetViewport(0, 0, event.GetWidth(), event.GetHeight());
		return false;
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
