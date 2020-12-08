#pragma once

#include <wind/dll.hpp>

namespace wind 
{

	namespace log 
	{

		enum class Target
		{
			engine = 0,
			app,
		};

		enum class Level
		{
			trace = 0,
			info,
			warning,
			error,
			critical,
		};

		bool WIND_API Initialize();
		void WIND_API Terminate();
		void WIND_API write( Target target, Level level, std::string str );

	}

}

#ifdef WIND_DLL_BUILD
#define LOG_TARGET wind::log::Target::engine
#elif WIND_CLIENT_BUILD
#define LOG_TARGET wind::log::Target::app
#else
#error LOG NEED BUILD PREDEFINE
#endif

#define WRITE_LOG( level, str ) wind::log::write( LOG_TARGET, level, str )