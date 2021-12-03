#include "VerifyAccountViewModel.hpp"
using namespace Hedral::UI;

VerifyAccountViewModel::VerifyAccountViewModel(QObject* parent)
{
    m_hedralManager = new Network::NetworkManagerImpl();
}

void VerifyAccountViewModel::VerifyAccount()
{
    connect(m_hedralManager, SIGNAL(ResponseArrived(QByteArray)), this, SLOT(UpdateResponse(QByteArray)));

    auto endpoint = BuildEndpoint();
    m_hedralManager->SetEndPoint(endpoint);

    m_hedralManager->Post();
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

QString VerifyAccountViewModel::User() const
{
    return m_user;
}

void VerifyAccountViewModel::User(const QString &user)
{
    if(user != m_user)
    {
        m_user = user;
        emit UserChanged();
    }
}

QString VerifyAccountViewModel::BuildEndpoint()
{
    QString user = User().mid(0, User().indexOf("@"));
    QString code = VerificationCode();
    QString endpoint = QString("https://q3pc77iipi.execute-api.us-east-2.amazonaws.com/dev/SignUp/VerifyAccount?code=%1&user=%2")
            .arg(code)
            .arg(user);

    qDebug() << "El endpoint es: " << endpoint;
    return endpoint;
}

void VerifyAccountViewModel::UpdateResponse(QByteArray response)
{
    StatusCode(m_hedralManager->GetStatusCode());
    Response(response);
}
