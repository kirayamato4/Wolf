#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Wind
{
	DLLEXPORT_TEMPLATE template class WIND_API std::shared_ptr<spdlog::logger>;

	class WIND_API Log
	{
	public:
		static void Init();

		__forceinline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		__forceinline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define WIND_CORE_TRACE( ... )		::Wind::Log::GetCoreLogger()->trace( __VA_ARGS__ )
#define WIND_CORE_INFO( ... )		::Wind::Log::GetCoreLogger()->info( __VA_ARGS__ )
#define WIND_CORE_WARN( ... )		::Wind::Log::GetCoreLogger()->warn( __VA_ARGS__ )
#define WIND_CORE_ERROR( ... )		::Wind::Log::GetCoreLogger()->error( __VA_ARGS__ )
#define WIND_CORE_CRITICAL( ... )	::Wind::Log::GetCoreLogger()->critical( __VA_ARGS__ )

#define WIND_APP_TRACE( ... )		::Wind::Log::GetClientLogger()->trace( __VA_ARGS__ )
#define WIND_APP_INFO( ... )		::Wind::Log::GetClientLogger()->info( __VA_ARGS__ )
#define WIND_APP_WARN( ... )		::Wind::Log::GetClientLogger()->warn( __VA_ARGS__ )
#define WIND_APP_ERROR( ... )		::Wind::Log::GetClientLogger()->error( __VA_ARGS__ )
#define WIND_APP_CRITICAL( ... )	::Wind::Log::GetClientLogger()->critical( __VA_ARGS__ )