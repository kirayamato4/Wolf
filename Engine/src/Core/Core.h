#pragma once

#ifdef WIND_PLATFORM_WINDOWS
	#ifdef WIND_BUILD_DLL
		#define WIND_API __declspec( dllexport )
		#define DLLEXPORT_TEMPLATE
	#else
		#define WIND_API __declspec( dllimport )
		#define DLLEXPORT_TEMPLATE extern
	#endif
#else
	#error Wind only support windows
#endif