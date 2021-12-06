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
    connect(m_hedralManager, SIGNAL(ResponseArrived(QByteArray)), this, SLOT(ImageWasUploaded()));
    qDebug() << "Uploading file: " << FileNameToUpload();
    qDebug() << "with path: " << FilePathToUpload();

    auto file = FileIntoByteArray();
    auto endpoint = BuildUploadFileEndpoint();

    qDebug() << "El endpoint es: ";
    qDebug() << endpoint;

    m_hedralManager->SetEndPoint(endpoint);
    m_hedralManager->Put(file);
}

void HomePageViewModel::DownloadFile()
{
    qDebug() << "Downloading...";
    connect(m_hedralManager, SIGNAL(ResponseArrived(QByteArray)), this, SLOT(UpdateResponse(QByteArray)));
    auto endpoint = QString("https://%1.s3.us-east-2.amazonaws.com/%2")
            .arg(GetLevelCode())
            .arg(FileNameToDownload());

    m_hedralManager->SetEndPoint(endpoint);
    m_hedralManager->DownloadFile();
}

QString HomePageViewModel::FileNameToUpload() const
{
    return m_fileNameToUpload;
}

void HomePageViewModel::FileNameToUpload(const QString &fileNameToUpload)
{
    if(fileNameToUpload != m_fileNameToUpload)
    {
        m_fileNameToUpload = fileNameToUpload;
        emit FileNameToUploadChanged();
    }
}

QString HomePageViewModel::FileNameToDownload() const
{
    return m_fileNameToDownload;
}

void HomePageViewModel::FileNameToDownload(const QString &fileNameToDownload)
{
    if(fileNameToDownload != m_fileNameToDownload)
    {
        m_fileNameToDownload = fileNameToDownload;
        emit FileNameToDownloadChanged();
    }
}

QString HomePageViewModel::FilePathToUpload() const
{
    return m_filePathToUpload;
}

void HomePageViewModel::FilePathToUpload(const QString &filePathToUpload)
{
    if(filePathToUpload != m_filePathToUpload)
    {
        m_filePathToUpload = filePathToUpload;
        emit FilePathToUploadChanged();
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

bool HomePageViewModel::UploadFinished() const
{
    return m_uploadFinished;
}

void HomePageViewModel::UploadFinished(const bool &uploadFinished)
{
    if(uploadFinished)
    {
        emit UploadFinishedChanged();
    }
    m_uploadFinished = false;
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

void HomePageViewModel::ImageWasUploaded()
{
    UploadFinished(true);
}

void HomePageViewModel::ImageDownload()
{
    qDebug() << "IMAGE FINISHED DOWNLOADING";
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
    auto levelCode = GetLevelCode();
    auto endpoint = QString("https://xm2tijowg9.execute-api.us-east-2.amazonaws.com/dev/%1/%2")
            .arg(GetLevelCode())
            .arg(FileNameToUpload());

    return endpoint;
}

QString HomePageViewModel::GetLevelCode()
{
    if(Level() == "Nivel 1") return "hedral-level1";
    if(Level() == "Nivel 2") return "hedral-level2";
    if(Level() == "Nivel 3") return "hedral-level3";
    return "";
}

QByteArray HomePageViewModel::FileIntoByteArray()
{
    auto filepath = FilePathToUpload().mid(8, FilePathToUpload().size());
    QFile file(filepath);
    if(!file.open(QIODevice::ReadOnly))
        qDebug() << "Error reading file: " << filepath;

    auto data = file.readAll();
    file.close();
    return data;

}
