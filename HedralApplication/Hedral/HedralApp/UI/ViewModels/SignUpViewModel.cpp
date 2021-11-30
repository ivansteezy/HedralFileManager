#include "SignUpViewModel.hpp"
using namespace Hedral::UI;

SignUpViewModel::SignUpViewModel(QObject* parent)
{

}

void SignUpViewModel::SignUp()
{
    qDebug() << "Email: " << m_email;
    qDebug() << "Name: " << m_name;
    qDebug() << "Last name: " << m_lastName;
    qDebug() << "Level: " << m_level;
    qDebug() << "Password: " << m_password;
    qDebug() << "Confirm Password: " << m_confirmPassword;

    auto endpoint = BuildEndpoint();
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

QString SignUpViewModel::Email() const
{
    return m_email;
}

void SignUpViewModel::Email(const QString &email)
{
    if(email != m_email)
    {
        m_email = email;
        emit EmailChanged();
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

QString SignUpViewModel::BuildEndpoint()
{
    QString endpoint = QString("https://q3pc77iipi.execute-api.us-east-2.amazonaws.com/dev/SignUp/proxy?email=%1&password=%2&name=%3&familyName=%4&level=%5")
            .arg(Email())
            .arg(Password())
            .arg(Name())
            .arg(LastName())
            .arg(Level());

    qDebug() << endpoint;
    return endpoint;
}
