#ifndef HOMEPAGEVIEWMODEL_HPP
#define HOMEPAGEVIEWMODEL_HPP

#include <QObject>
#include <QString>
#include <qDebug>

#include "../../Services/HFMNetworking/NetworkManager.hpp"
#include "../../Services/HFMNetworking/Downloader.hpp"

namespace Hedral
{
    namespace UI
    {
        class HomePageViewModel : public QObject
        {
            Q_OBJECT;

            Q_PROPERTY(QString fileNameToUpload READ FileNameToUpload WRITE FileNameToUpload NOTIFY FileNameToUploadChanged);
            Q_PROPERTY(QString filePathToUpload READ FilePathToUpload WRITE FilePathToUpload NOTIFY FilePathToUploadChanged);
            Q_PROPERTY(QString fileNameToDownload READ FileNameToDownload WRITE FileNameToDownload NOTIFY FileNameToDownloadChanged);
            Q_PROPERTY(QString fileToDelete READ FileToDelete WRITE FileToDelete NOTIFY FileToDeleteChanged);
            Q_PROPERTY(QString level READ Level WRITE Level NOTIFY LevelChanged);
            Q_PROPERTY(QByteArray response READ Response WRITE Response NOTIFY ResponseChanged);
            Q_PROPERTY(QByteArray deleteResponse READ DeleteResponse WRITE DeleteResponse NOTIFY DeleteResponseChanged);
            Q_PROPERTY(int statusCode READ StatusCode WRITE StatusCode NOTIFY StatusCodeChanged);
            Q_PROPERTY(bool uploadFinished READ UploadFinished WRITE UploadFinished NOTIFY UploadFinishedChanged);

        public:
            explicit HomePageViewModel(QObject* parent = nullptr);

        public:
            Q_INVOKABLE void SearchFiles();
            Q_INVOKABLE void DeleteFile();
            Q_INVOKABLE void UploadFile();
            Q_INVOKABLE void DownloadFile();

        public:
            [[nodiscard]]
            QString FileNameToUpload() const;
            void FileNameToUpload(const QString& fileToUpload);

            [[nodiscard]]
            QString FileNameToDownload() const;
            void FileNameToDownload(const QString& fileNameToDownload);

            [[nodiscard]]
            QString FilePathToUpload() const;
            void FilePathToUpload(const QString& filePathToUpload);

            [[nodiscard]]
            QString FileToDelete() const;
            void FileToDelete(const QString& fileToDelete);

            [[nodiscard]]
            QString Level() const;
            void Level(const QString& level);

            [[nodiscard]]
            QByteArray Response() const;
            void Response(const QByteArray& response);

            [[nodiscard]]
            QByteArray DeleteResponse() const;
            void DeleteResponse(const QByteArray& deleteResponse);

            [[nodiscard]]
            int StatusCode() const;
            void StatusCode(const int& statusCode);

            [[nodiscard]]
            bool UploadFinished() const;
            void UploadFinished(const bool& uploadFinished);

        signals:
            void FileNameToUploadChanged();
            void FileNameToDownloadChanged();
            void FileToDeleteChanged();
            void FilePathToUploadChanged();
            void LevelChanged();
            void ResponseChanged();
            void StatusCodeChanged();
            void DeleteResponseChanged();
            void UploadFinishedChanged();

        public slots:
            void UpdateResponse(QByteArray response);
            void UpdateDeleteResponse(QByteArray response);
            void ImageDownload();

        private:
            QString BuildQueryAllEndpoint();
            QString BuildDeleteFileEndpoint();
            QString BuildUploadFileEndpoint();
            QString GetLevelCode();
            QByteArray FileIntoByteArray();

        private:
            QString m_fileNameToUpload;
            QString m_fileNameToDownload;
            QString m_fileToDelete;
            QString m_filePathToUpload;
            QString m_level;
            bool m_uploadFinished;
            QByteArray m_response;
            QByteArray m_deleteResponse;
            int m_statusCode;

            Network::NetworkManagerImpl* m_hedralManager;

        };
    }
}

#endif
