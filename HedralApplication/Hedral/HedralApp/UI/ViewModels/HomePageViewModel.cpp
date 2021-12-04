#include "HomePageViewModel.hpp"
using namespace Hedral::UI;


HomePageViewModel::HomePageViewModel(QObject *parent)
{
    m_hedralManager = new Network::NetworkManagerImpl();
}

void HomePageViewModel::SearchFiles()
{
    qDebug() << "About to search files";
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

void HomePageViewModel::BuildEndpoint()
{

}
