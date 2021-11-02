#include "NetworkManager.hpp"

using namespace Hedral::Network;

HEDRAL_IMPLEMENT_CLASSFACTORY(NetworkManager, NetworkManagerImpl, INetworkManager);

NetworkManagerImpl::NetworkManagerImpl() :
    m_endpointPreffix("https://to6klngvgk.execute-api.us-east-2.amazonaws.com"),
    m_endpoint("")
{

}

NetworkManagerImpl::~NetworkManagerImpl()
{

}

void NetworkManagerImpl::SetEndPoint(const QString& endpoint)
{
    Logger->WriteInfo("Setting endpoint: " + endpoint);
    m_endpoint = m_endpointPreffix + endpoint;
}

void NetworkManagerImpl::MakeRequest(const HTTPRequest& requestType)
{
    QUrl url(m_endpoint);
    m_networkRequest.setUrl(url);
    m_networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    switch (requestType)
    {
        case HTTPRequest::Get:  Get();  break;
        case HTTPRequest::Post: Put();  break;
        case HTTPRequest::Put:  Post(); break;
    }
}

void NetworkManagerImpl::Get()
{
    QNetworkReply* reply = m_networkAccessManager.get(m_networkRequest);
    Logger->WriteInfo("Sending a GET request to: " + m_endpoint);

    QObject::connect(reply, &QNetworkReply::finished, [=]() {
       QByteArray responseData = reply->readAll();
       auto json = JsonSerializer->ByteArrayToJson(responseData);
       m_response = JsonSerializer->JsonAsMap(json);
    });
}

void NetworkManagerImpl::Put()
{

}

void NetworkManagerImpl::Post()
{

}

QVariant NetworkManagerImpl::GetResponse() const
{
    return m_response;
}

QObject* NetworkManagerImpl::AsQtObject()
{
    return static_cast<QObject*>(this);
}

const QMetaObject* NetworkManagerImpl::MetaObject()
{
    return this->metaObject();
}
