#include "AdminLoginViewModel.hpp"
using namespace Hedral::UI;

AdminLoginViewModel::AdminLoginViewModel(QObject* parent) : QObject(parent)
{

}

[[nodiscard]]
QString AdminLoginViewModel::Email() const
{
    return m_email;
}

void AdminLoginViewModel::Email(const QString& email)
{
    if(email != m_email)
    {
        m_email = email;
        emit EmailChanged();
    }
}

void AdminLoginViewModel::Login()
{

}

[[nodiscard]]
QString AdminLoginViewModel::Password() const
{
    return m_password;
}

void AdminLoginViewModel::Password(const QString& password)
{
    if(password != m_password)
    {
        m_password = password;
        emit PasswordChanged();
    }
}

QByteArray AdminLoginViewModel::Response() const
{
    return m_response;
}

void AdminLoginViewModel::Response(const QByteArray &response)
{
    if(response != m_response)
    {
        m_response = response;
        emit ResponseChanged();
    }
}

int AdminLoginViewModel::StatusCode() const
{
    return m_statusCode;
}

void AdminLoginViewModel::StatusCode(const int &statusCode)
{
    if(statusCode != m_statusCode)
    {
        m_statusCode = statusCode;
        emit StatusCodeChanged();
    }
}
