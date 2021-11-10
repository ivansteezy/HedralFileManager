#ifndef RESTOREPASSWORDVEWMODEL_HPP
#define RESTOREPASSWORDVEWMODEL_HPP

#include <QObject>
#include <QString>

namespace Hedral
{
    namespace UI
    {
        class RestorePasswordViewModel : public QObject
        {
            Q_OBJECT;

            Q_PROPERTY(QString newPassword READ NewPassword WRITE NewPassword NOTIFY NewPasswordChanged);
            Q_PROPERTY(QString confirmNewPassword READ ConfirmNewPassword WRITE ConfirmNewPassword NOTIFY ConfirmNewPasswordChanged);
            Q_PROPERTY(QString verificationCode READ VerificationCode WRITE VerificationCode NOTIFY VerificationCodeChanged);

        public:
            explicit RestorePasswordViewModel(QObject* parent = nullptr);

        public:
            Q_INVOKABLE bool SendCode();
            Q_INVOKABLE bool VerifyCode();

            [[nodiscard]]
            QString NewPassword() const;
            void NewPassword(const QString& newPassword);

            [[nodiscard]]
            QString ConfirmNewPassword() const;
            void ConfirmNewPassword(const QString& confirmNewPassword);

            [[nodiscard]]
            QString VerificationCode() const;
            void VerificationCode(const QString& verificationCode);

        signals:
            void NewPasswordChanged();
            void ConfirmNewPasswordChanged();
            void VerificationCodeChanged();

        public slots:

        private:
            QString m_newPassword;
            QString m_confirmNewPassword;
            QString m_verificationCode;
        };
    }
}

#endif
