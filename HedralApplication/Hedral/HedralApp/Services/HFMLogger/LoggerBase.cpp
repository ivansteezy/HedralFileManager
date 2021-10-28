#include "LoggerBase.hpp"

using namespace Hedral::Log;

HEDRAL_IMPLEMENT_INTERFACE(ILogger);

static Hedral::Core::ComPtr<ILogger> m_globalLogger;

void GlobalLogger::SetInstance(Hedral::Core::ComPtr<ILogger> logger)
{
    m_globalLogger = logger;
}

ILogger* GlobalLogger::Instance()
{
    return m_globalLogger;
}
