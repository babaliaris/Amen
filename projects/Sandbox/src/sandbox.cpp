#define AMEN_ENTRYPOINT
#include <Amen.h>
#include "layers/testLayer.h"

class Sandbox: public Amen::App
{
	public:
	Sandbox()
	{
	}

	~Sandbox(){}

	private:
		Amen::Layer* test_layer;
};

Amen::App* Amen::CreateApp()
{
	return new Sandbox();
}