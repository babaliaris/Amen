#include "testLayer.h"

void TestLayer::OnUpdate(Hazel::Timestep deltaTime)
{
}

void TestLayer::OnEvent(Hazel::Event& e)
{
}

void TestLayer::OnAttach()
{
	AMEN_WARN("OnAttach");
}

void TestLayer::OnDetach()
{
	AMEN_WARN("OnDetach");
}
