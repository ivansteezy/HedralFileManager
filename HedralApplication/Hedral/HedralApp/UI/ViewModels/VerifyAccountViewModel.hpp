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

        public:
            explicit VerifyAccountViewModel(QObject* parent = nullptr);

        public:
            [[nodiscard]]
            QString VerificationCode() const;
            void VerificationCode(const QString& verificationCode);

        signals:
            void VerificationCodeChanged();

        public slots:

        private:
            QString m_verificationCode;
        };
    }
}

#endif
