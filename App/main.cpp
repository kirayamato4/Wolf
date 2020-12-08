#include "pch.h"
#include "App.h"

int main( int argc, char* argv[] )
{
	App* pApp = new App();
	if( !pApp )
		return -1;

	if( !pApp->Initialize() )
		return -2;

	int exit_code = pApp->Run();

	pApp->Terminate();

	delete pApp;

	return exit_code;
}