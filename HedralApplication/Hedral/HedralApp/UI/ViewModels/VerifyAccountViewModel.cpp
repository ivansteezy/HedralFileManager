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

QByteArray VerifyAccountViewModel::Response() const
{
    return m_response;
}

void VerifyAccountViewModel::Response(const QByteArray &response)
{
    if(response != m_response)
    {
        m_response = response;
        emit ResponseChanged();
    }
}

int VerifyAccountViewModel::StatusCode() const
{
    return m_statusCode;
}

void VerifyAccountViewModel::StatusCode(const int &statusCode)
{
    if(statusCode != m_statusCode)
    {
        m_statusCode = statusCode;
        emit StatusCodeChanged();
    }
}
