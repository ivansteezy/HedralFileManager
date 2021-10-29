#ifndef NETWORKMANAGER_HPP
#define NETWORKMANAGER_HPP

#include "NetworkManagerBase.hpp"
#include "../HFMLogger/LoggerBase.hpp"

namespace Hedral
{
    namespace Network
    {
        class NetworkManagerImpl : public QObject, public Core::Implements<INetworkManager, Hedral::Core::IQtObjectSupport>
        {
            Q_OBJECT;

        public:
            NetworkManagerImpl();
            virtual ~NetworkManagerImpl();

            virtual void SetEndPoint() override;
            virtual void MakeRequest(const HTTPRequest& requestType) override;
            // virtual QNetworkReply GetNetworkReply() const override;

            virtual QObject* AsQtObject() override;
            virtual const QMetaObject* MetaObject() override;

        private:
            Log::ILogger* x;
        };
    }
}

#endif
