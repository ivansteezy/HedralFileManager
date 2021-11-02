#ifndef SYSTEMINITIALIZER_HPP
#define SYSTEMINITIALIZER_HPP

#include "SystemInitializerBase.hpp"
#include "../HFMLogger/LoggerBase.hpp"
#include "../HFMNetworking/NetworkingBase.hpp"

namespace Hedral
{
    namespace Bootstraping
    {
        class SystemInitializerImpl : public QObject, public Core::Implements<ISystemInitializer, Hedral::Core::IQtObjectSupport>
        {
            Q_OBJECT;

        public:
            SystemInitializerImpl();
            virtual ~SystemInitializerImpl();

            virtual void Initialize() override;

            virtual QObject* AsQtObject() override;
            virtual const QMetaObject* MetaObject() override;

        private:
            Hedral::Core::ComPtr<Hedral::Log::ILogger> m_logger;
            Hedral::Core::ComPtr<Hedral::Network::IJsonSerializer> m_jsonSerializer;
            Hedral::Core::ComPtr<Hedral::Network::INetworkManager> m_NetworkManager;
        };
    }
}

#endif
