#ifndef NETWORKMANAGER_HPP
#define NETWORKMANAGER_HPP

#include <QUrl>
#include <QtNetwork>
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

        public:
            NetworkManagerImpl();
            virtual ~NetworkManagerImpl();

            virtual void SetEndPoint(const QString& endpoint) override;
            virtual void MakeRequest(const HTTPRequest& requestType) override;

            virtual QObject* AsQtObject() override;
            virtual const QMetaObject* MetaObject() override;

        public:
            void Get();
            void Put();
            void Post();

            //QJsonDocument GetResponseAsJson();
            //QVariantMap GetResponseAsMap();

        private:
            QNetworkAccessManager m_networkAccessManager;
            QNetworkRequest m_networkRequest;
            QString m_endpointPreffix;
            QString m_endpoint;
        };
    }
}

#endif
