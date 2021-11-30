#ifndef SIGNUPVIEWMODEL_HPP
#define SIGNUPVIEWMODEL_HPP

#include <QObject>
#include <QString>
#include <qDebug>

#include "../../Services/HFMNetworking/NetworkManager.hpp"

namespace Hedral
{
    namespace UI
    {
        class SignUpViewModel : public QObject
        {
            Q_OBJECT;

            Q_PROPERTY(QString name READ Name WRITE Name NOTIFY NameChanged);
            Q_PROPERTY(QString email READ Email WRITE Email NOTIFY EmailChanged);
            Q_PROPERTY(QString lastName READ LastName WRITE LastName NOTIFY LastNameChanged);
            Q_PROPERTY(QString password READ Password WRITE Password NOTIFY PasswordChanged);
            Q_PROPERTY(QString confirmPassword READ ConfirmPassword WRITE ConfirmPassword NOTIFY ConfirmPasswordChanged);
            Q_PROPERTY(QString level READ Level WRITE Level NOTIFY LevelChanged);
            Q_PROPERTY(QByteArray response READ Response WRITE Response NOTIFY ResponseChanged);
            Q_PROPERTY(int statusCode READ StatusCode WRITE StatusCode NOTIFY StatusCodeChanged);

        public:
            explicit SignUpViewModel(QObject* parent = nullptr);

        public:
            Q_INVOKABLE void SignUp();

        public:
            [[nodiscard]]
            QString Name() const;
            void Name(const QString& name);

            [[nodiscard]]
            QString LastName() const;
            void LastName(const QString& lastName);

            [[nodiscard]]
            QString Password() const;
            void Password(const QString& password);

            [[nodiscard]]
            QString ConfirmPassword() const;
            void ConfirmPassword(const QString& confirmPassword);

            [[nodiscard]]
            QString Email() const;
            void Email(const QString& email);

            [[nodiscard]]
            QString Level() const;
            void Level(const QString& level);

            [[nodiscard]]
            QByteArray Response() const;
            void Response(const QByteArray& response);

            [[nodiscard]]
            int StatusCode() const;
            void StatusCode(const int& statusCode);

        private:
            QString BuildEndpoint();

        signals:
            void NameChanged();
            void LastNameChanged();
            void PasswordChanged();
            void ConfirmPasswordChanged();
            void LevelChanged();
            void ResponseChanged();
            void StatusCodeChanged();
            void EmailChanged();

        public slots:

        private:
            QString m_name;
            QString m_lastName;
            QString m_password;
            QString m_email;
            int m_statusCode;
            QByteArray m_response;
            QString m_confirmPassword;
            // Network::NetworkManagerImpl* m_hedralManager;
            QString m_level;
        };
    }
}

#endif
