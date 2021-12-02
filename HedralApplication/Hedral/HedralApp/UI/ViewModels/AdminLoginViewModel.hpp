#ifndef ADMINLOGINVIEWMODEL_HPP
#define ADMINLOGINVIEWMODEL_HPP

#include <QObject>
#include <QString>
#include <qDebug>

#include <QtNetwork>

#include "../../Services/HFMNetworking/NetworkingBase.hpp"

namespace Hedral
{
    namespace UI
    {
        class AdminLoginViewModel : public QObject
        {
            Q_OBJECT;

            Q_PROPERTY(QString email READ Email WRITE Email NOTIFY EmailChanged);
            Q_PROPERTY(QString password READ Password WRITE Password NOTIFY PasswordChanged);
            Q_PROPERTY(QByteArray response READ Response WRITE Response NOTIFY ResponseChanged);
            Q_PROPERTY(int statusCode READ StatusCode WRITE StatusCode NOTIFY StatusCodeChanged);

            HEDRAL_DEPENDENCY(Network::INetworkManager*, NetworkManager, Network, NetworkManager);

        public:
            explicit AdminLoginViewModel(QObject* parent = nullptr);

            Q_INVOKABLE void Login();
        public:
            [[nodiscard]]
            QString Email() const;
            void Email(const QString& email);

            [[nodiscard]]
            QString Password() const;
            void Password(const QString& email);

            [[nodiscard]]
            QByteArray Response() const;
            void Response(const QByteArray& response);

            [[nodiscard]]
            int StatusCode() const;
            void StatusCode(const int& statusCode);

        signals:
            void EmailChanged();
            void PasswordChanged();
            void ResponseChanged();
            void StatusCodeChanged();

        public slots:

        private:
            QByteArray m_response;
            QString m_email;
            QString m_password;
            int m_statusCode;
        };
    }
}

#endif
