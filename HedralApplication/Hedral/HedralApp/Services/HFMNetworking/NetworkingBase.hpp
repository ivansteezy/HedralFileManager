#ifndef NETWORKMANAGERBASE_HPP
#define NETWORKMANAGERBASE_HPP

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "../HFMCore/HedralCore.hpp"

namespace Hedral
{
    namespace Network
    {
        enum class HTTPRequest
        {
            Get = 0x00,
            Post = 0x01,
            Put = 0x10
        };

        struct INetworkManager : Hedral::Core::IContract
        {
            HEDRAL_DECLARE_INTERFACE(INetworkManager, "INetworkManager")

            virtual QByteArray GetResponse() const = 0;
            virtual int GetStatusCode() const = 0;

            virtual void SetEndPoint(const QString& endpoint) = 0;
            virtual bool Post() = 0;
            virtual bool Put(QByteArray data) = 0;
            virtual bool Get() = 0;
            virtual bool Delete() = 0;

        };
        HEDRAL_DECLARE_CLASSFACTORY(NetworkManager, INetworkManager);


        struct IJsonSerializer : Hedral::Core::IContract
        {
            HEDRAL_DECLARE_INTERFACE(IJsonSerializer, "IJsonSerializer")
            virtual QJsonDocument ByteArrayToJson(const QByteArray& jsonByteArray) = 0;
            virtual QVariant JsonAsMap(const QJsonDocument& jsonDocument) = 0;
            virtual QByteArray JsonByteArray(const QJsonDocument& jsonDocument) = 0;

        };
        HEDRAL_DECLARE_CLASSFACTORY(JsonSerializer, IJsonSerializer);

        struct GlobalNetworkManager
        {
            static void SetInstance(Hedral::Core::ComPtr<INetworkManager> networkManager);
            static INetworkManager* Instance();
        };

        struct GlobalJsonSerializer
        {
            static void SetInstance(Hedral::Core::ComPtr<IJsonSerializer> jsonSerializer);
            static IJsonSerializer* Instance();
        };
    }
}

#endif
