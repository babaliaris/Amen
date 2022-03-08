#define AMEN_ENTRYPOINT
#include <Amen.h>
#include "layers/testLayer.h"

class Sandbox: public Amen::App
{
	public:
	Sandbox()
	{
		test_layer = new TestLayer();
		PushLayer(test_layer);
	}

	~Sandbox(){}

	private:
		Amen::Layer* test_layer;
};

Amen::App* Amen::CreateApp()
{
	return new Sandbox();
}