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

            virtual void SetEndPoint() = 0;
            virtual void MakeRequest(const HTTPRequest& requestType) = 0;
            // virtual QNetworkReply GetNetworkReply() const = 0;
        };
        HEDRAL_DECLARE_CLASSFACTORY(NetworkManager, INetworkManager);

        struct GlobalNetworkManager
        {
            static void SetInstance(Hedral::Core::ComPtr<INetworkManager> networkManager);
            static INetworkManager* Instance();
        };
    }
}

#endif
