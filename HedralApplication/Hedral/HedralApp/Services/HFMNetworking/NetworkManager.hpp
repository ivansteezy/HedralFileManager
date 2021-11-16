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
            virtual void MakeRequest() override;
            virtual QVariant GetResponse() const override;

            virtual QObject* AsQtObject() override;
            virtual const QMetaObject* MetaObject() override;

        public slots:
            void ReplyFinished(QNetworkReply* reply);
            void SlotError(QNetworkReply::NetworkError error);

        signals:

        public:
            void Get();
            void Put();
            void Post();

        private:
            QNetworkAccessManager* m_networkAccessManager;
            QNetworkRequest m_networkRequest;
            QString m_endpointPreffix;
            QVariant m_response;
            QString m_endpoint;
        };
    }
}

#endif
