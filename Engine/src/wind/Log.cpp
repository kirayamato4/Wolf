#include <wind/pch.hpp>
#include <wind/Log.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace wind
{
	
	namespace log
	{
		std::shared_ptr<spdlog::logger> engine_logger;
		std::shared_ptr<spdlog::logger> app_logger;

		bool init_logger( std::shared_ptr<spdlog::logger>& logger, const char* name, const char* pattern, spdlog::level::level_enum level )
		{
			logger = spdlog::stdout_color_mt( name );
			if( !logger )
			{
				return false;
			}

			logger->set_pattern( pattern );
			logger->set_level( level );

			return true;
		}


		bool Initialize()
		{
			const char* pattern = "%^[%T] %8n : %v%$";

			if( !init_logger( engine_logger, "Engine", pattern, spdlog::level::level_enum::trace ) )
			{
				return false;
			}

			if( !init_logger( app_logger, "App", pattern, spdlog::level::level_enum::trace ) )
			{
				return false;
			}

			return true;
		}

		void Terminate()
		{
		}

		void write( Target target, Level level, std::string str )
		{
			static std::shared_ptr<spdlog::logger> logger = nullptr;
			switch( target )
			{
				case Target::engine:
					logger = engine_logger;
					break;

				case Target::app:
					logger = app_logger;
					break;

				default:
					return;
			}

			switch( level ) {
				case Level::trace:
					logger->trace( str );
					break;

				case Level::info:
					logger->info( str );
					break;

				case Level::warning:
					logger->warn( str );
					break;

				case Level::error:
					logger->error( str );
					break;

				case Level::critical:
					logger->critical( str );
					break;
			}
		}
	}
}

