#include "testLayer.h"

void TestLayer::OnUpdate(Amen::Timestep deltaTime)
{
}

void TestLayer::OnEvent(Amen::Event& e)
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
