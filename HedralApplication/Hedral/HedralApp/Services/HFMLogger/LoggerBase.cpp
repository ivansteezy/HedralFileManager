#include "LoggerBase.hpp"

using namespace Hedral::Log;

HEDRAL_IMPLEMENT_INTERFACE(ILogger);

static Hedral::Core::ComPtr<ILogger> g_globalLogger;

void GlobalLogger::SetInstance(Hedral::Core::ComPtr<ILogger> logger)
{
    g_globalLogger = logger;
}

ILogger* GlobalLogger::Instance()
{
    return g_globalLogger;
}
