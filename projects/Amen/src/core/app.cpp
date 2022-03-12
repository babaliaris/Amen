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
#include <core/Render/Texture.h>

//-------------------------------Static Initializations-------------------------------//

//s_instance (singleton).
Hazel::App* Hazel::App::s_instance = nullptr;

//-------------------------------Static Initializations-------------------------------//


Hazel::App::App() : m_window(nullptr)
{
	//Get the instance of the app.
	AMEN_ASSERT(s_instance == nullptr, "You can only have one app at a time (singleton).");
	s_instance = this;

	//Initialize the platform.
	Platform::Init();

	//Create the window.
	m_window = Window::Create();

	//Initialize the Renderer.
	RendererCommand::Init();

	//Init Input.
	Input::Init();

	//Set the event callback.
	m_window->SetEventCallback(AMEN_BIND(Hazel::App::OnEvent));

	//Create the ImGuiLayer.
	m_ImGuiLayer = ImguiLayer::Create();

	//Disable ImGui Demo Window.
	static_cast<ImguiLayer*>(m_ImGuiLayer)->SetShowDemoWindow(false);

	//Push the ImGui Layer.
	PushLayer(m_ImGuiLayer);
}




Hazel::App::~App()
{
	//Delete all the layers.
	for (Layer* layer : m_layers)
		delete layer;
}



void Hazel::App::Run()
{

	double currentTime = 0.0f;
	double prevTime = 0.0f;

	float triangleData[] =
	{
		//Positions				//Colors			//Texture Coordinates
		-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	0.0f, 0.0f,	//0
		 0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 0.0f,	//1
		 0.0f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f,	0.5f, 0.5f	//2
	};

	unsigned int triangleIndexData[] =
	{
		2, 1, 0
	};


	float quadData[] =
	{
		//Positions				//Texture Coordinates
		-0.5f,  0.5f, 0.0f,		0.0f, 1.0f,	//0 (Top Left)
		 0.5f,  0.5f, 0.0f,		1.0f, 1.0f,	//1 (Top Right)
		 0.5f, -0.5f, 0.0f,		1.0f, 0.0f,	//2 (Bottom Right)
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f	//3 (Bottom Left)
	};

	unsigned int quadIndexData[] =
	{
		0, 2, 3,
		0, 1, 2
	};




	BufferLayout triangleLayout = {
		{"Positions", ShaderType::FLOAT3},
		{"Colors", ShaderType::FLOAT3},
		{"Texture Coordinates", ShaderType::FLOAT2}
	};

	Ref<VertexBuffer> triangleVertexBuffer = VertexBuffer::Create(triangleData, sizeof(triangleData));
	triangleVertexBuffer->SetLayout(triangleLayout);

	Ref<IndexBuffer> triangleIndexBuffer = IndexBuffer::Create(triangleIndexData, 3);
	Ref<ArrayBuffer> triangleArrayBuffer = ArrayBuffer::Create(triangleVertexBuffer, triangleIndexBuffer);

	Ref<Shader> triangleShader = Shader::Create(AMEN_RELATIVE("resources/OpenGLShaders/mvp_triangle_textured.glsl"));



	BufferLayout quadLayout = {
		{"Positions", ShaderType::FLOAT3},
		{"Texture Coordinates", ShaderType::FLOAT2}
	};

	Ref<VertexBuffer> quadVertexBuffer = VertexBuffer::Create(quadData, sizeof(quadData));
	quadVertexBuffer->SetLayout(quadLayout);

	Ref<IndexBuffer> quadIndexBuffer = IndexBuffer::Create(quadIndexData, 6);
	Ref<ArrayBuffer> quadArrayBuffer = ArrayBuffer::Create(quadVertexBuffer, quadIndexBuffer);

	Ref<Shader> quadShader = Shader::Create(AMEN_RELATIVE("resources/OpenGLShaders/mvp_quad_textured.glsl"));
	quadShader->UploadInt("u_Texture", 0);

	Ref<Texture2D> checkerboardTexture = Texture2D::Create(AMEN_RELATIVE("resources/textures/Checkerboard.png"));
	Ref<Texture2D> chernoLogoTexture = Texture2D::Create(AMEN_RELATIVE("resources/textures/ChernoLogo.png"));



	Camera::OrthographicProps props = { 0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f };
	OrthographicCamera camera(props);
	camera.SetMovementSpeed(3.0f);
	camera.SetRotationSpeed(40.0f);

	glm::mat4 triangleTransform(1.0f);
	glm::mat4 quadTransform = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 0.0f));
	glm::mat4 chernoLogoTransform = glm::translate(glm::mat4(1.0f), glm::vec3(0.6f, 0.4f, 0.0f));

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
			camera.Move(Camera::MovementE::FORWARD, deltaTime);
		}

		if (Input::GetKeyDown(KeyboardE::k_down))
		{
			camera.Move(Camera::MovementE::BACKWARD, deltaTime);
		}

		if (Input::GetKeyDown(KeyboardE::k_left))
		{
			camera.Move(Camera::MovementE::LEFT, deltaTime);
		}

		if (Input::GetKeyDown(KeyboardE::k_right))
		{
			camera.Move(Camera::MovementE::RIGHT, deltaTime);
		}

		if (Input::GetKeyDown(KeyboardE::kp_4))
		{
			camera.Move(Camera::MovementE::ROLL_LEFT, deltaTime);
		}

		if (Input::GetKeyDown(KeyboardE::kp_6))
		{
			camera.Move(Camera::MovementE::ROLL_RIGHT, deltaTime);
		}

		if (Input::GetKeyDown(KeyboardE::k_j))
		{
			triangleTransform = glm::translate(triangleTransform, glm::vec3(-deltaTime.GetTimeSeconds() * 2, 0.0f, 0.0f));
		}

		if (Input::GetKeyDown(KeyboardE::k_l))
		{
			triangleTransform = glm::translate(triangleTransform, glm::vec3(deltaTime.GetTimeSeconds() * 2, 0.0f, 0.0f));
		}

		if (Input::GetKeyDown(KeyboardE::k_i))
		{
			triangleTransform = glm::translate(triangleTransform, glm::vec3(0.0f, deltaTime.GetTimeSeconds() * 2, 0.0f));
		}

		if (Input::GetKeyDown(KeyboardE::k_k))
		{
			triangleTransform = glm::translate(triangleTransform, glm::vec3(0.0f, -deltaTime.GetTimeSeconds() * 2, 0.0f));
		}

		Renderer::BeginScene(camera);

		Renderer::Submit(triangleShader, triangleArrayBuffer, triangleTransform);

		checkerboardTexture->Bind();
		Renderer::Submit(quadShader, quadArrayBuffer, quadTransform);

		chernoLogoTexture->Bind();
		Renderer::Submit(quadShader, quadArrayBuffer, chernoLogoTransform);

		Renderer::EndScene();

		//Must be last.
		//Poll the events and swap the buffers.
		m_window->Update();
	}
}





void Hazel::App::PushLayer(Layer* layer)
{
	m_layers.push_back(layer);

	layer->OnAttach();
}





void Hazel::App::RemoveLayer(Layer* layer)
{
	m_layers.erase( std::remove(m_layers.begin(), m_layers.end(), layer), m_layers.end() );

	layer->OnDetach();
}




void Hazel::App::OnEvent(Event& e)
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
		AMEN_INFO("Hazel Paused...");
		return false;
	});


	//On WindowRestoredEvent, resume the application.
	disp.Dispatch<WindowRestoredEvent>([this](WindowRestoredEvent event)
	{
		m_paused = false;
		AMEN_INFO("Hazel Resumed...");
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
