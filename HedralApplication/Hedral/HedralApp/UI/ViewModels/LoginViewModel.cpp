#include "LoginViewModel.hpp"
using namespace Hedral::UI;


LoginViewModel::LoginViewModel(QObject* parent)
{

}

void LoginViewModel::LogIn()
{
    auto a = new Network::NetworkManagerImpl();
    connect(a, SIGNAL(ResponseArrived(QByteArray)), this, SLOT(UpdateResponse(QByteArray)));
    qDebug() << "Haciendo peticion...";
    a->Get();
}

bool LoginViewModel::VerifyData()
{
    return false;
}

[[nodiscard]]
QString LoginViewModel::Email() const
{
    return m_email;
}

void LoginViewModel::Email(const QString& email)
{
    if(email != m_email)
    {
        m_email = email;
        emit EmailChanged();
    }
}

[[nodiscard]]
QString LoginViewModel::Password() const
{
    return m_password;
}

void LoginViewModel::Password(const QString& password)
{
    if(password != m_password)
    {
        m_password = password;
        emit PasswordChanged();
    }
}

QByteArray LoginViewModel::Response() const
{
    return m_response;
}

void LoginViewModel::Response(const QByteArray &response)
{
    if(response != m_response)
    {
        m_response = response;
        emit ResponseChanged();
    }
}

void LoginViewModel::UpdateResponse(QByteArray response)
{
    qDebug() << "ha llegado! " << response;
    Response(response);
}
