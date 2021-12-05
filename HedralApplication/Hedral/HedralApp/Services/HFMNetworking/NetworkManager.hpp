#ifndef NETWORKMANAGER_HPP
#define NETWORKMANAGER_HPP

#include <QUrl>
#include <QtNetwork>
#include <QJsonDocument>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>

#include "NetworkingBase.hpp"
#include "../HFMLogger/LoggerBase.hpp"

#include "ReplyTimeOut.hpp"

namespace Hedral
{
    namespace Network
    {
        class NetworkManagerImpl : public QObject, public Core::Implements<INetworkManager, Hedral::Core::IQtObjectSupport>
        {
            Q_OBJECT;

            HEDRAL_DEPENDENCY(Log::ILogger*, Logger, Log, Logger);
            HEDRAL_DEPENDENCY(Network::IJsonSerializer*, JsonSerializer, Network, JsonSerializer);

        public:
            explicit NetworkManagerImpl(QObject* parent = 0);
            virtual ~NetworkManagerImpl();

            virtual void SetEndPoint(const QString& endpoint) override;
            virtual bool Get() override;
            virtual bool Delete() override;
            virtual bool Post() override;
            virtual bool Put() override;

            virtual QObject* AsQtObject() override;
            virtual const QMetaObject* MetaObject() override;

            virtual QByteArray GetResponse() const override;
            virtual int GetStatusCode() const override;

        private:
            void SetResponse(const QByteArray& response);
            void SetStatusCode(const int& statusCode);
            void SerializeResponse();

        public slots:
            void ReplyFinished(QNetworkReply* reply);
            void SlotError(QNetworkReply::NetworkError error);
            void Progress(qint64 sent, qint64 total);
            void TimeOut();

        signals:
            void ResponseArrived(QByteArray response);

        private:
            QNetworkAccessManager* m_networkAccessManager;
            QString m_endpointPreffix;
            QByteArray m_response;
            QVariant m_responseMap;
            QString m_endpoint;
            int m_statusCode;
        };
    }
}

#endif
