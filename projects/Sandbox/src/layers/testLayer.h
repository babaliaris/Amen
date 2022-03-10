#pragma once
#include <Amen.h>

class TestLayer: public Amen::Layer
{
	public:

		virtual void OnUpdate(Amen::Timestep deltaTime) override;


		virtual void OnEvent(Amen::Event& e) override;


		virtual void OnAttach()override;


		virtual void OnDetach() override;
};

