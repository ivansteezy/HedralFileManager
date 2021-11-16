#include "NetworkManager.hpp"

using namespace Hedral::Network;

HEDRAL_IMPLEMENT_CLASSFACTORY(NetworkManager, NetworkManagerImpl, INetworkManager);

NetworkManagerImpl::NetworkManagerImpl(QObject *parent) :
    QObject(parent),
    m_endpointPreffix("https://to6klngvgk.execute-api.us-east-2.amazonaws.com"),
    m_endpoint("")
{
    m_networkAccessManager = new QNetworkAccessManager(this);
}

NetworkManagerImpl::~NetworkManagerImpl()
{

}

void NetworkManagerImpl::SetEndPoint(const QString& endpoint)
{
    Logger->WriteInfo("Setting endpoint: " + endpoint);
    m_endpoint = m_endpointPreffix + endpoint;
}

void NetworkManagerImpl::ReplyFinished(QNetworkReply* reply)
{
    qDebug("replyFinished");
    QByteArray responseData = reply->readAll();
    qDebug() << "Response: " << QJsonDocument::fromJson(responseData);
}

void NetworkManagerImpl::SlotError(QNetworkReply::NetworkError error)
{
    qDebug("slotError");
}

void NetworkManagerImpl::MakeRequest()
{
    connect(m_networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ReplyFinished(QNetworkReply*)));

    QNetworkRequest request;
    request.setUrl(QUrl("https://to6klngvgk.execute-api.us-east-2.amazonaws.com/dev/posts/ByNumber/%7Bnumber%7D"));

    QNetworkReply *reply = m_networkAccessManager->get(request);
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(SlotError(QNetworkReply::NetworkError)));
}

void NetworkManagerImpl::Get()
{

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
