#include "pch.h"
#include "App.h"

#include <wind/wind.hpp>

App::App()
{
}

App::~App()
{
}

bool App::Initialize()
{
	if( !wind::log::Initialize() )
		return false;
	WRITE_LOG( wind::log::Level::info, "logger initialized" );

	return true;
}

void App::Terminate()
{
	wind::log::Terminate();
	WRITE_LOG( wind::log::Level::info, "logger terminated" );
}

int App::Run()
{
	while( true );

	return 0;
}
