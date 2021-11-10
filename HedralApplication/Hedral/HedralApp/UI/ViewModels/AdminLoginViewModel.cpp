#include "AdminLoginViewModel.hpp"
using namespace Hedral::UI;

AdminLoginViewModel::AdminLoginViewModel(QObject* parent)
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
    qDebug() << "Boton clickeado";
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
