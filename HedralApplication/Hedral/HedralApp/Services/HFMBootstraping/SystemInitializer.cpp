#include "SystemInitializer.hpp"

using namespace Hedral::Bootstraping;

HEDRAL_IMPLEMENT_CLASSFACTORY(SystemInitializer, SystemInitializerImpl, ISystemInitializer)


SystemInitializerImpl::SystemInitializerImpl()
{

}

SystemInitializerImpl::~SystemInitializerImpl()
{

}

void SystemInitializerImpl::Initialize()
{
    m_logger = Hedral::Log::Logger::CreateInstance();
    Hedral::Log::GlobalLogger::SetInstance(m_logger);

    m_NetworkManager = Hedral::Network::NetworkManager::CreateInstance();
    Hedral::Network::GlobalNetworkManager::SetInstance(m_NetworkManager);
}

QObject* SystemInitializerImpl::AsQtObject()
{
    return static_cast<QObject*>(this);
}

const QMetaObject* SystemInitializerImpl::MetaObject()
{
    return this->metaObject();
}
