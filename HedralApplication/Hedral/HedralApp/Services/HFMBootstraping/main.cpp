#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "../HFMCore/TestCore.h"
#include <QtWidgets/QApplication>
#include <QtNetwork>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    printHello();


    QApplication app(argc, argv);

//    QNetworkRequest req(QUrl("https://to6klngvgk.execute-api.us-east-2.amazonaws.com/dev/posts/ByNumber/%7Bnumber%7D"));
//    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
//    QNetworkAccessManager nam;
//    QNetworkReply* reply = nam.get(req);

//    qDebug() << "Bout to get!";
//    QObject::connect(reply, &QNetworkReply::finished, [&]() {
//        QByteArray responseData = reply->readAll();
//        qDebug() << "Got response: !!!!!!!!!!!!!!" << QJsonDocument::fromJson(responseData);
//        reply->close();
//        reply->deleteLater();
//     });



    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("../../Hedral/HedralApp/UI/Views/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
