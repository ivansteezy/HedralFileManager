#ifndef VERIFYACCOUNTVIEWMODEL_HPP
#define VERIFYACCOUNTVIEWMODEL_HPP

#include <QObject>
#include <QString>

namespace Hedral
{
    namespace UI
    {
        class VerifyAccountViewModel : public QObject
        {
            Q_OBJECT;

            Q_PROPERTY(QString verificationCode READ VerificationCode WRITE VerificationCode NOTIFY VerificationCodeChanged);
            Q_PROPERTY(QByteArray response READ Response WRITE Response NOTIFY ResponseChanged);
            Q_PROPERTY(int statusCode READ StatusCode WRITE StatusCode NOTIFY StatusCodeChanged);

        public:
            explicit VerifyAccountViewModel(QObject* parent = nullptr);

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

        signals:
            void VerificationCodeChanged();
            void ResponseChanged();
            void StatusCodeChanged();

        public slots:

        private:
            QString m_verificationCode;
            QByteArray m_response;
            int m_statusCode;
        };
    }
}

#endif
