#ifndef VERIFYACCOUNTVIEWMODEL_HPP
#define VERIFYACCOUNTVIEWMODEL_HPP

#include <QObject>
#include <QString>
#include <qDebug>

#include "../../Services/HFMNetworking/NetworkManager.hpp"

namespace Hedral
{
    namespace UI
    {
        class VerifyAccountViewModel : public QObject
        {
            Q_OBJECT;

            Q_PROPERTY(QString verificationCode READ VerificationCode WRITE VerificationCode NOTIFY VerificationCodeChanged);
            Q_PROPERTY(QByteArray response READ Response WRITE Response NOTIFY ResponseChanged);
            Q_PROPERTY(QString user READ User WRITE User NOTIFY UserChanged);
            Q_PROPERTY(int statusCode READ StatusCode WRITE StatusCode NOTIFY StatusCodeChanged);

        public:
            explicit VerifyAccountViewModel(QObject* parent = nullptr);

        public:
            Q_INVOKABLE void VerifyAccount();

        public:
            [[nodiscard]]
            QString VerificationCode() const;
            void VerificationCode(const QString& verificationCode);

            [[nodiscard]]
            QByteArray Response() const;
            void Response(const QByteArray& response);

            [[nodiscard]]
            int StatusCode() const;
            void StatusCode(const int& statusCode);

            [[nodiscard]]
            QString User() const;
            void User(const QString& user);

        private:
            QString BuildEndpoint();

        signals:
            void VerificationCodeChanged();
            void ResponseChanged();
            void StatusCodeChanged();
            void UserChanged();

        public slots:
            void UpdateResponse(QByteArray response);

        private:
            QString m_verificationCode;
            QString m_user;
            Network::NetworkManagerImpl* m_hedralManager;
            QByteArray m_response;
            int m_statusCode;
        };
    }
}

#endif
