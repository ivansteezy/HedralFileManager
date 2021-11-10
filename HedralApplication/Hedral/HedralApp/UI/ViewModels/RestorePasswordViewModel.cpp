#include "RestorePasswordViewModel.hpp"
using namespace Hedral::UI;


RestorePasswordViewModel::RestorePasswordViewModel(QObject* parent)
{

}

bool RestorePasswordViewModel::SendCode()
{
    return false;
}

bool RestorePasswordViewModel::VerifyCode()
{
    return false;
}

[[nodiscard]]
QString RestorePasswordViewModel::NewPassword() const
{
    return m_newPassword;
}

void RestorePasswordViewModel::NewPassword(const QString& newPassword)
{
    if(newPassword != m_newPassword)
    {
        m_newPassword = newPassword;
        emit NewPasswordChanged();
    }
}

[[nodiscard]]
QString RestorePasswordViewModel::ConfirmNewPassword() const
{
    return m_confirmNewPassword;
}

void RestorePasswordViewModel::ConfirmNewPassword(const QString& confirmNewPassword)
{
    if(confirmNewPassword != m_confirmNewPassword)
    {
        m_confirmNewPassword = confirmNewPassword;
        emit ConfirmNewPasswordChanged();
    }
}


[[nodiscard]]
QString RestorePasswordViewModel::VerificationCode() const
{
    return m_verificationCode;
}

void RestorePasswordViewModel::VerificationCode(const QString& verificationCode)
{
    if(verificationCode != m_verificationCode)
    {
        m_verificationCode = verificationCode;
        emit VerificationCodeChanged();
    }
}
