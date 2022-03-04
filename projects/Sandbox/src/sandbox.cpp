#define AMEN_ENTRYPOINT
#include <Amen.h>

class Sandbox: public Amen::App
{
	public:
	Sandbox()
	{
	}

	~Sandbox(){}
};

Amen::App* Amen::CreateApp()
{
	return new Sandbox();
}