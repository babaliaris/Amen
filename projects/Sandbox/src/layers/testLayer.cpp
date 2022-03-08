#include "testLayer.h"

void TestLayer::OnUpdate()
{
	if (Amen::Input::GetButtonDown(Amen::MouseButtonE::button_middle))
	{
		AMEN_INFO("Middle mouse is down");
	}
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
