#include "NetworkingBase.hpp"

using namespace Hedral::Network;

HEDRAL_IMPLEMENT_INTERFACE(INetworkManager);
HEDRAL_IMPLEMENT_INTERFACE(IJsonSerializer);

static Hedral::Core::ComPtr<INetworkManager> g_globalNetworkManager;
static Hedral::Core::ComPtr<IJsonSerializer> g_globalJsonSerializer;

void GlobalNetworkManager::SetInstance(Hedral::Core::ComPtr<INetworkManager> networkManager)
{
    g_globalNetworkManager = networkManager;
}

INetworkManager* GlobalNetworkManager::Instance()
{
    return g_globalNetworkManager;
}


void GlobalJsonSerializer::SetInstance(Hedral::Core::ComPtr<IJsonSerializer> jsonSerializer)
{
    g_globalJsonSerializer = jsonSerializer;
}

IJsonSerializer* GlobalJsonSerializer::Instance()
{
    return g_globalJsonSerializer;
}
