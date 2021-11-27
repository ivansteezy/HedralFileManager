#ifndef LOGINVIEWMODEL_HPP
#define LOGINVIEWMODEL_HPP

#include <QObject>
#include <QString>
#include <QByteArray>

#include "../../Services/HFMNetworking/NetworkingBase.hpp"

namespace Hedral
{
    namespace UI
    {
        class LoginViewModel : public QObject
        {
            Q_OBJECT;

            Q_PROPERTY(QString email READ Email WRITE Email NOTIFY EmailChanged);
            Q_PROPERTY(QString password READ Password WRITE Password NOTIFY PasswordChanged);
            Q_PROPERTY(QByteArray response READ Response WRITE Response NOTIFY ResponseChanged);

            HEDRAL_DEPENDENCY(Network::INetworkManager*, NetworkManager, Network, NetworkManager);

        public:
            explicit LoginViewModel(QObject* parent = nullptr);

        public:
            Q_INVOKABLE void LogIn();
            Q_INVOKABLE bool VerifyData();

            [[nodiscard]]
            QString Email() const;
            void Email(const QString& email);

            [[nodiscard]]
            QString Password() const;
            void Password(const QString& email);

            [[nodiscard]]
            QByteArray Response() const;
            void Response(const QByteArray& response);

        signals:
            void EmailChanged();
            void PasswordChanged();
            void ResponseChanged();

        public slots:

        private:
            QString m_email;
            QString m_password;
            QByteArray m_response;

            bool m_isCorrectlyLogged;
        };
    }
}

#endif
