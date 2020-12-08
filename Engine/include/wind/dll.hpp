#pragma once

#ifndef __WIND_DLL_H__
#define __WIND_DLL_H__

#ifdef WIND_PLATFORM_WINDOWS
#ifdef WIND_DLL_BUILD
#define WIND_API __declspec( dllexport )
#define DLLEXPORT_TEMPLATE
#else
#define WIND_API __declspec( dllimport )
#define DLLEXPORT_TEMPLATE extern
#endif
#else
#error Wind only support windows
#endif

#endif