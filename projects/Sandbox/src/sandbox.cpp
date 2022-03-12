#define AMEN_ENTRYPOINT
#include <Hazel.h>
#include "layers/testLayer.h"

class Sandbox: public Hazel::App
{
	public:
	Sandbox()
	{
		//test_layer = new TestLayer();
		//PushLayer(test_layer);
	}

	~Sandbox(){}

	private:
		Hazel::Layer* test_layer;
};

Hazel::App* Hazel::CreateApp()
{
	return new Sandbox();
}