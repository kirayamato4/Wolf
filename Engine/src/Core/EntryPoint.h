#pragma once


#ifdef WIND_PLATFORM_WINDOWS

extern Wind::Application* Wind::CreateApplication();

int main( int argc, char** argv )
{
	auto app = Wind::CreateApplication();
	app->Run();
	delete app;
}

#endif