#include "NetworkManagerBase.hpp"

using namespace Hedral::Network;

HEDRAL_IMPLEMENT_INTERFACE(INetworkManager);

static Hedral::Core::ComPtr<INetworkManager> g_globalNetworkManager;

void GlobalNetworkManager::SetInstance(Hedral::Core::ComPtr<INetworkManager> networkManager)
{
    g_globalNetworkManager = networkManager;
}

INetworkManager* GlobalNetworkManager::Instance()
{
    return g_globalNetworkManager;
}
