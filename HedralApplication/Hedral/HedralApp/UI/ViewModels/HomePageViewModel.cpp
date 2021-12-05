#include "HomePageViewModel.hpp"
using namespace Hedral::UI;


HomePageViewModel::HomePageViewModel(QObject *parent)
{
    m_hedralManager = new Network::NetworkManagerImpl();
}

void HomePageViewModel::SearchFiles()
{
    qDebug() << "About to search files";
    connect(m_hedralManager, SIGNAL(ResponseArrived(QByteArray)), this, SLOT(UpdateResponse(QByteArray)));
    auto endpoint = BuildQueryAllEndpoint();
    m_hedralManager->SetEndPoint(endpoint);
    m_hedralManager->Get();
}

void HomePageViewModel::DeleteFile()
{
    connect(m_hedralManager, SIGNAL(ResponseArrived(QByteArray)), this, SLOT(UpdateDeleteResponse(QByteArray)));
    auto endpoint = BuildDeleteFileEndpoint();
    qDebug() << "El endpoint es: ";
    qDebug() << endpoint;
    m_hedralManager->SetEndPoint(endpoint);
    m_hedralManager->Delete();
}

void HomePageViewModel::UploadFile()
{
    qDebug() << "Uploading file";
}

QString HomePageViewModel::FileToUpload() const
{
    return m_fileToUpload;
}

void HomePageViewModel::FileToUpload(const QString &fileToUpload)
{
    if(fileToUpload != m_fileToUpload)
    {
        m_fileToUpload = fileToUpload;
        emit FileToUploadChanged();
    }
}

QString HomePageViewModel::FileToDelete() const
{
    return m_fileToDelete;
}

void HomePageViewModel::FileToDelete(const QString &fileToDelete)
{
    if(fileToDelete != m_fileToDelete)
    {
        m_fileToDelete = fileToDelete;
        emit FileToDeleteChanged();
    }
}

QString HomePageViewModel::Level() const
{
    return m_level;
}

void HomePageViewModel::Level(const QString &level)
{
    if(level != m_level)
    {
        m_level = level;
        emit LevelChanged();
    }
}

QByteArray HomePageViewModel::Response() const
{
    return m_response;
}

void HomePageViewModel::Response(const QByteArray &response)
{
    if(response != m_response)
    {
        m_response = response;
        emit ResponseChanged();
    }
}

QByteArray HomePageViewModel::DeleteResponse() const
{
    return m_deleteResponse;
}

void HomePageViewModel::DeleteResponse(const QByteArray &deleteResponse)
{
    if(deleteResponse != m_deleteResponse)
    {
        m_deleteResponse = deleteResponse;
        emit DeleteResponseChanged();
    }
}

int HomePageViewModel::StatusCode() const
{
    return m_statusCode;
}

void HomePageViewModel::StatusCode(const int &statusCode)
{
    if(statusCode != m_statusCode)
    {
        m_statusCode = statusCode;
        emit StatusCodeChanged();
    }
}

void HomePageViewModel::UpdateResponse(QByteArray response)
{
    StatusCode(m_hedralManager->GetStatusCode());
    Response(response);
}

void HomePageViewModel::UpdateDeleteResponse(QByteArray response)
{
    StatusCode(m_hedralManager->GetStatusCode());
    DeleteResponse(response);
}

QString HomePageViewModel::BuildQueryAllEndpoint()
{
    auto levelCode = GetLevelCode();
    auto endpoint = QString("https://q3pc77iipi.execute-api.us-east-2.amazonaws.com/dev/Files/%1")
            .arg(levelCode);

    return endpoint;
}

QString HomePageViewModel::BuildDeleteFileEndpoint()
{
    auto levelCode = GetLevelCode();
    auto endpoint = QString("https://q3pc77iipi.execute-api.us-east-2.amazonaws.com/dev/Files/%1?fileName=%2")
            .arg(levelCode)
            .arg(FileToDelete());

    return endpoint;
}

QString HomePageViewModel::BuildUploadFileEndpoint()
{
    return QString();
}

QString HomePageViewModel::GetLevelCode()
{
    if(Level() == "Nivel 1") return "hedral-level1";
    if(Level() == "Nivel 2") return "hedral-level2";
    if(Level() == "Nivel 3") return "hedral-level3";
    return "";
}
