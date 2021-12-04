#ifndef HOMEPAGEVIEWMODEL_HPP
#define HOMEPAGEVIEWMODEL_HPP

#include <QObject>
#include <QString>
#include <qDebug>

#include "../../Services/HFMNetworking/NetworkManager.hpp"

namespace Hedral
{
    namespace UI
    {
        class HomePageViewModel : public QObject
        {
            Q_OBJECT;


            Q_PROPERTY(QString fileToUpload READ FileToUpload WRITE FileToUpload NOTIFY FileToUploadChanged);
            Q_PROPERTY(QString fileToDelete READ FileToDelete WRITE FileToDelete NOTIFY FileToDeleteChanged);
            Q_PROPERTY(QString level READ Level WRITE Level NOTIFY LevelChanged);
            Q_PROPERTY(QByteArray response READ Response WRITE Response NOTIFY ResponseChanged);
            Q_PROPERTY(int statusCode READ StatusCode WRITE StatusCode NOTIFY StatusCodeChanged);

        public:
            explicit HomePageViewModel(QObject* parent = nullptr);

        public:
            Q_INVOKABLE void SearchFiles();
            Q_INVOKABLE void DeleteFile();
            Q_INVOKABLE void UploadFile();

        public:
            [[nodiscard]]
            QString FileToUpload() const;
            void FileToUpload(const QString& fileToUpload);

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
            int StatusCode() const;
            void StatusCode(const int& statusCode);

        signals:
            void FileToUploadChanged();
            void FileToDeleteChanged();
            void LevelChanged();
            void ResponseChanged();
            void StatusCodeChanged();

        public slots:
            void UpdateResponse(QByteArray response);

        private:
            QString BuildQueryAllEndpoint();
            QString BuildDeleteFileEndpoint();
            QString BuildUploadFileEndpoint();
            QString GetLevelCode();

        private:
            QString m_fileToUpload;
            QString m_fileToDelete;
            QString m_level;
            QByteArray m_response;
            int m_statusCode;

            Network::NetworkManagerImpl* m_hedralManager;

        };
    }
}

#endif
