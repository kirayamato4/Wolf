#include <Wind.h>

class CApp
	: public Wind::Application
{
public:
	CApp()
	{

	}

	virtual ~CApp()
	{

	}
};

Wind::Application* Wind::CreateApplication()
{
	return new CApp();
}