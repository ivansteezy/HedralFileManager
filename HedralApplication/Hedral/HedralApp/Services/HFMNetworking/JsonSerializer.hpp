#ifndef JSONSERIALIZER_HPP
#define JSONSERIALIZER_HPP

#include <QtNetwork>
#include <QJsonDocument>

#include "NetworkingBase.hpp"
#include "../HFMLogger/LoggerBase.hpp"

namespace Hedral
{
    namespace Network
    {
        class JsonSerializerImpl : public QObject, public Core::Implements<IJsonSerializer, Hedral::Core::IQtObjectSupport>
        {
            Q_OBJECT;

        public:
            JsonSerializerImpl();
            virtual ~JsonSerializerImpl();

            virtual QJsonDocument ByteArrayToJson(const QByteArray& jsonByteArray) override;
            virtual QVariantMap JsonAsMap(const QJsonDocument& jsonDocument) override;
            virtual QByteArray JsonByteArray(const QJsonDocument& jsonDocument) override;

            virtual QObject* AsQtObject() override;
            virtual const QMetaObject* MetaObject() override;
        };
    }
}

#endif

