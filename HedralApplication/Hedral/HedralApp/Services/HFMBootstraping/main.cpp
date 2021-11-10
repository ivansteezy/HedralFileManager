#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWidgets/QApplication>
#include <QQmlContext>
#include <QtNetwork>

#include "../HFMLogger/Logger.hpp"
#include "SystemInitializer.hpp"

#include "../../UI/ViewModels/AdminLoginViewModel.hpp"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif


    QApplication app(argc, argv);

    QNetworkRequest req(QUrl("https://to6klngvgk.execute-api.us-east-2.amazonaws.com/dev/posts/ByNumber/%7Bnumber%7D"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager nam;
    QNetworkReply* reply = nam.get(req);

    qDebug() << "Bout to get!";
    QObject::connect(reply, &QNetworkReply::finished, [&]() {
        QByteArray responseData = reply->readAll();
        qDebug() << "Got response: !!!!!!!!!!!!!!" << QJsonDocument::fromJson(responseData);
        reply->close();
        reply->deleteLater();
     });

    auto systemInitializer = Hedral::Bootstraping::SystemInitializer::CreateInstance();
    systemInitializer->Initialize();

    auto logger = Hedral::Log::GlobalLogger::Instance();
    logger->WriteInfo("Initializing logger!");
    logger->WriteError("Initializing logger!");
    logger->WriteWarning("Initializing logger!");

    auto netManager = Hedral::Network::GlobalNetworkManager::Instance();
    netManager->SetEndPoint("/dev/posts/ByNumber/%7Bnumber%7D");
    netManager->MakeRequest(Hedral::Network::HTTPRequest::Get);
    auto res = netManager->GetResponse();

    QQmlApplicationEngine engine;

    //register viewmodels
    Hedral::UI::AdminLoginViewModel loginViewModel;
    engine.rootContext()->setContextProperty("loginViewModel", &loginViewModel);

    const QUrl url(QStringLiteral("../../Hedral/HedralApp/UI/Views/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
