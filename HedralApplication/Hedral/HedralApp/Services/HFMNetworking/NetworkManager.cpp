#include "NetworkManager.hpp"

using namespace Hedral::Network;

HEDRAL_IMPLEMENT_CLASSFACTORY(NetworkManager, NetworkManagerImpl, INetworkManager);

NetworkManagerImpl::NetworkManagerImpl(QObject *parent) :
    QObject(parent),
    m_endpointPreffix(""),
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

    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug() << "Status code: " << statusCode.toInt();

    // reply->abort();
    SetStatusCode(statusCode.toInt());
    SetResponse(responseData);
    emit ResponseArrived(m_response);

    m_networkAccessManager->disconnect();
}

void NetworkManagerImpl::SlotError(QNetworkReply::NetworkError error)
{
    qDebug("slotError");
}

void NetworkManagerImpl::Progress(qint64 sent, qint64 total)
{
    qDebug() << "Enviados " << sent;
    qDebug() << "Total " << total;
}

void NetworkManagerImpl::TimeOut()
{
    qDebug() << "Timer finishes";
}

bool NetworkManagerImpl::Get()
{
    qDebug() << "Making get...";
    connect(m_networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ReplyFinished(QNetworkReply*)));

    QNetworkRequest request;
    request.setUrl(QUrl(m_endpoint));

    QNetworkReply *reply = m_networkAccessManager->get(request);
    // connect(reply, SIGNAL(SlotError(QNetworkReply::NetworkError)), this, SLOT(SlotError(QNetworkReply::NetworkError)));

    return true;
}

bool NetworkManagerImpl::Delete()
{
    qDebug() << "Making delete...";
    connect(m_networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ReplyFinished(QNetworkReply*)));
    QNetworkRequest request;
    request.setUrl(QUrl(m_endpoint));

    QNetworkReply *reply = m_networkAccessManager->deleteResource(request);

    return true;
}

bool NetworkManagerImpl::Post()
{
    QNetworkRequest request;
    request.setUrl(QUrl(m_endpoint));
    qDebug() << "Making post...";
    qDebug() << m_endpoint;
    connect(m_networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ReplyFinished(QNetworkReply*)));
    QNetworkReply *reply = m_networkAccessManager->post(request, QByteArray());
    return true;
}

bool NetworkManagerImpl::Put(QByteArray data)
{
    QNetworkRequest request;
    request.setUrl(QUrl(m_endpoint));
    qDebug() << "Making put...";
    qDebug() << m_endpoint;
    connect(m_networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ReplyFinished(QNetworkReply*)));

    QNetworkReply *reply = m_networkAccessManager->put(request, data);
    return true;
}



void NetworkManagerImpl::SetResponse(const QByteArray& response)
{
    m_response = response;
    emit ResponseArrived(response);
}

void NetworkManagerImpl::SetStatusCode(const int& statusCode)
{
    m_statusCode = statusCode;
}

void NetworkManagerImpl::SerializeResponse()
{

}

QByteArray NetworkManagerImpl::GetResponse() const
{
    return m_response;
}

int NetworkManagerImpl::GetStatusCode() const
{
    return m_statusCode;
}

QObject* NetworkManagerImpl::AsQtObject()
{
    return static_cast<QObject*>(this);
}

const QMetaObject* NetworkManagerImpl::MetaObject()
{
    return this->metaObject();
}
