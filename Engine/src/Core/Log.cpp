#include "Log.h"

namespace Wind
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void InitLogger( std::shared_ptr<spdlog::logger>& logger, const char* name, const char* pattern, spdlog::level::level_enum level )
	{
		logger = spdlog::stdout_color_mt( name );
		logger->set_pattern( pattern );
		logger->set_level( level );
	}

	void Log::Init()
	{
		const char* pattern = "%^[%T] %8n : %v%$";

		InitLogger( s_CoreLogger, "Engine", pattern, spdlog::level::trace );
		InitLogger( s_ClientLogger, "App", pattern, spdlog::level::trace );
	}
}