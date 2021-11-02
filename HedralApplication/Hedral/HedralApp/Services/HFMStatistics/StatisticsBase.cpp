#include "StatisticsBase.hpp"

using namespace Hedral::Stats;

HEDRAL_IMPLEMENT_INTERFACE(IStatisticsManager);

static Hedral::Core::ComPtr<IStatisticsManager> g_globalStatisticsManager;

void GlobalStatisticsManager::SetInstance(Hedral::Core::ComPtr<IStatisticsManager> logger)
{
    g_globalStatisticsManager = logger;
}

IStatisticsManager* GlobalStatisticsManager::Instance()
{
    return g_globalStatisticsManager;
}
