#pragma once

#ifdef WIND_PLATFORM_WINDOWS
	#ifdef WIND_BUILD_DLL
		#define WIND_API __declspec( dllexport )
	#else
		#define WIND_API __declspec( dllimport )
	#endif
#else
	#error Wind only support windows
#endif