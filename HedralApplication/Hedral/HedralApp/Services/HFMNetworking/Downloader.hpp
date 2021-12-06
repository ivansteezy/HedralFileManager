#ifndef DOWNLOADER_HPP
#define DOWNLOADER_HPP

#include <QObject>
#include <QString>
#include <QtNetwork>
#include <QUrl>
#include <QNetworkRequest>
#include <QFile>
#include <QDebug>

namespace Hedral
{
    namespace Network
    {
        class QtDownload : public QObject
        {
            Q_OBJECT
        public:
            explicit QtDownload();
            ~QtDownload();

            void setTarget(const QString& t);

        private:
            QNetworkAccessManager* manager;
            QString target;

        signals:
            void done();

        public slots:
            void download();
            void downloadFinished(QNetworkReply* data);
            void downloadProgress(qint64 recieved, qint64 total);
        };
    }
}

#endif
