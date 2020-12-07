#include "Log.h"

namespace Wind
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		s_CoreLogger = spdlog::stdout_color_mt( "Engine" );
		s_CoreLogger->set_pattern( "%^[%T] %8n : %v%$" );
		s_CoreLogger->set_level( spdlog::level::trace );

		s_ClientLogger = spdlog::stdout_color_mt( "App" );
		s_ClientLogger->set_pattern( "%^[%T] %8n : %v%$" );
		s_ClientLogger->set_level( spdlog::level::trace );
	}
}