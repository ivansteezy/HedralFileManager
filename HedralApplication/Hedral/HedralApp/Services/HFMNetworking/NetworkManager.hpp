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
            virtual bool Put() override;
            virtual bool Post() override;

            virtual QObject* AsQtObject() override;
            virtual const QMetaObject* MetaObject() override;

            virtual QByteArray GetResponse() const override;

        private:
            void SetResponse(const QByteArray& response);
            void SerializeResponse();

        public slots:
            void ReplyFinished(QNetworkReply* reply);
            void SlotError(QNetworkReply::NetworkError error);

        signals:

        private:
            QNetworkAccessManager* m_networkAccessManager;
            QString m_endpointPreffix;
            QByteArray m_response;
            QVariant m_responseMap;
            QString m_endpoint;
        };
    }
}

#endif
