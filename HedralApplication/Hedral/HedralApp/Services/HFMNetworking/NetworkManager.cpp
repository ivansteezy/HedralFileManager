#include "NetworkManager.hpp"

using namespace Hedral::Network;


HEDRAL_IMPLEMENT_CLASSFACTORY(NetworkManager, NetworkManagerImpl, INetworkManager);


NetworkManagerImpl::NetworkManagerImpl()
{

}

NetworkManagerImpl::~NetworkManagerImpl()
{

}

void NetworkManagerImpl::SetEndPoint()
{
    Logger->WriteInfo("Settin endpoint");
}

void NetworkManagerImpl::MakeRequest(const HTTPRequest& requestType)
{

}

//QNetworkReply NetworkManagerImpl::GetNetworkReply() const
//{

//}

QObject* NetworkManagerImpl::AsQtObject()
{
    return static_cast<QObject*>(this);
}

const QMetaObject* NetworkManagerImpl::MetaObject()
{
    return this->metaObject();
}
