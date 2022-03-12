#pragma once
#include <Hazel.h>

class TestLayer: public Hazel::Layer
{
	public:

		virtual void OnUpdate(Hazel::Timestep deltaTime) override;


		virtual void OnEvent(Hazel::Event& e) override;


		virtual void OnAttach()override;


		virtual void OnDetach() override;
};

