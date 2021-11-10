#include "VerifyAccountViewModel.hpp"
using namespace Hedral::UI;

VerifyAccountViewModel::VerifyAccountViewModel(QObject* parent)
{

}

[[nodiscard]]
QString VerifyAccountViewModel::VerificationCode() const
{
    return m_verificationCode;
}

void VerifyAccountViewModel::VerificationCode(const QString& verificationCode)
{
    if(verificationCode != m_verificationCode)
    {
        m_verificationCode = verificationCode;
        emit VerificationCodeChanged();
    }
}
