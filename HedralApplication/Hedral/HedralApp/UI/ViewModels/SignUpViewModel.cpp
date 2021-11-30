#include "SignUpViewModel.hpp"
using namespace Hedral::UI;



SignUpViewModel::SignUpViewModel(QObject* parent)
{

}

[[nodiscard]]
QString SignUpViewModel::Name() const
{
    return m_name;
}


void SignUpViewModel::Name(const QString& name)
{
    if(name != m_name)
    {
        m_name = name;
        emit NameChanged();
    }
}

[[nodiscard]]
QString SignUpViewModel::LastName() const
{
    return m_lastName;
}

void SignUpViewModel::LastName(const QString& lastName)
{
    if(lastName != m_lastName)
    {
        m_lastName = lastName;
        emit LastNameChanged();
    }
}

[[nodiscard]]
QString SignUpViewModel::Password() const
{
    return m_password;
}

void SignUpViewModel::Password(const QString& password)
{
    if(password != m_password)
    {
        m_password = password;
        emit PasswordChanged();
    }
}

[[nodiscard]]
QString SignUpViewModel::ConfirmPassword() const
{
    return m_confirmPassword;
}

void SignUpViewModel::ConfirmPassword(const QString& confirmPassword)
{
    if(confirmPassword != m_confirmPassword)
    {
        m_confirmPassword = confirmPassword;
        emit ConfirmPasswordChanged();
    }
}

[[nodiscard]]
QString SignUpViewModel::Level() const
{
    return m_level;
}

void SignUpViewModel::Level(const QString& level)
{
    if(level != m_level)
    {
        m_level = level;
        emit LevelChanged();
    }
}

QByteArray SignUpViewModel::Response() const
{
    return m_response;
}

void SignUpViewModel::Response(const QByteArray &response)
{
    if(response != m_response)
    {
        m_response = response;
        emit ResponseChanged();
    }
}

int SignUpViewModel::StatusCode() const
{
    return m_statusCode;
}

void SignUpViewModel::StatusCode(const int &statusCode)
{
    if(statusCode != m_statusCode)
    {
        m_statusCode = statusCode;
        emit StatusCodeChanged();
    }
}
