#include "NetworkManager.hpp"

using namespace Hedral::Network;

HEDRAL_IMPLEMENT_CLASSFACTORY(NetworkManager, NetworkManagerImpl, INetworkManager);

NetworkManagerImpl::NetworkManagerImpl(QObject *parent) :
    QObject(parent),
    m_endpointPreffix("https://q3pc77iipi.execute-api.us-east-2.amazonaws.com/dev/Files/hedral-level3"),
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
    QByteArray responseData = reply->readAll();
    m_response = responseData;

    emit ResponseArrived(m_response);

    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug() << "Status code: " << statusCode;

    SetResponse(responseData);
}

void NetworkManagerImpl::SlotError(QNetworkReply::NetworkError error)
{
    qDebug("slotError");
}

bool NetworkManagerImpl::Get()
{
    connect(m_networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ReplyFinished(QNetworkReply*)));

    QNetworkRequest request;
    request.setUrl(QUrl("https://q3pc77iipi.execute-api.us-east-2.amazonaws.com/dev/Files/hedral-level3"));

    QNetworkReply *reply = m_networkAccessManager->get(request);
    // connect(reply, SIGNAL(SlotError(QNetworkReply::NetworkError)), this, SLOT(SlotError(QNetworkReply::NetworkError)));

    return true;
}

bool NetworkManagerImpl::Put()
{
    return false;
}

bool NetworkManagerImpl::Post()
{
    return false;
}

void NetworkManagerImpl::SetResponse(const QByteArray& response)
{
    m_response = response;
    emit ResponseArrived(response);
}

void NetworkManagerImpl::SerializeResponse()
{

}

QByteArray NetworkManagerImpl::GetResponse() const
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
