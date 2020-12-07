#pragma once

#ifdef WIND_PLATFORM_WINDOWS

extern Wind::Application* Wind::CreateApplication();

int main( int argc, char** argv )
{
	Wind::Log::Init();

	WIND_CORE_INFO( "Initialize Core Logger" );
	WIND_APP_INFO( "Initialize App Logger" );

	auto app = Wind::CreateApplication();
	app->Run();
	delete app;
}

#endif