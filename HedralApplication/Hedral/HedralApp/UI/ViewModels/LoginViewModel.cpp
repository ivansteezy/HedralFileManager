#include "LoginViewModel.hpp"
using namespace Hedral::UI;


LoginViewModel::LoginViewModel(QObject* parent)
{
    InitializeManager();
}

void LoginViewModel::InitializeManager()
{
    m_hedralManager = new Network::NetworkManagerImpl();
}

QString LoginViewModel::BuildEndpoint()
{
    QString endpoint = QString("https://q3pc77iipi.execute-api.us-east-2.amazonaws.com/dev/Login/Credentials?email=%1&password=%2")
            .arg(Email())
            .arg(Password());

    return endpoint;
}

void LoginViewModel::LogIn()
{
    connect(m_hedralManager, SIGNAL(ResponseArrived(QByteArray)), this, SLOT(UpdateResponse(QByteArray)));
    auto endpoint = BuildEndpoint();

    m_hedralManager->SetEndPoint(endpoint);
    m_hedralManager->Post();
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

int LoginViewModel::StatusCode() const
{
    return m_statusCode;
}

void LoginViewModel::StatusCode(const int &statusCode)
{
    if(statusCode != m_statusCode)
    {
        m_statusCode = statusCode;
        emit StatusCodeChanged();
    }
}

void LoginViewModel::UpdateResponse(QByteArray response)
{
    StatusCode(m_hedralManager->GetStatusCode());
    Response(response);
}
