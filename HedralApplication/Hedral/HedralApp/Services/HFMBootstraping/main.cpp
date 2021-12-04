#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWidgets/QApplication>
#include <QQmlContext>
#include <QtNetwork>

#include "../HFMLogger/Logger.hpp"
#include "SystemInitializer.hpp"

#include "../../UI/ViewModels/LoginViewModel.hpp"
#include "../../UI/ViewModels/SignUpViewModel.hpp"
#include "../../UI/ViewModels/VerifyAccountViewModel.hpp"
#include "../../UI/ViewModels/HomePageViewModel.hpp"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication app(argc, argv);

    auto systemInitializer = Hedral::Bootstraping::SystemInitializer::CreateInstance();
    systemInitializer->Initialize();

    //Test logger
    auto logger = Hedral::Log::GlobalLogger::Instance();
    logger->WriteInfo("Initializing logger!");
    logger->WriteError("Initializing logger!");
    logger->WriteWarning("Initializing logger!");

    QQmlApplicationEngine engine;

    //register viewmodels
    Hedral::UI::LoginViewModel loginViewModel;
    engine.rootContext()->setContextProperty("loginViewModel", &loginViewModel);

    Hedral::UI::SignUpViewModel signUpViewModel;
    engine.rootContext()->setContextProperty("signUpViewModel", &signUpViewModel);

    Hedral::UI::VerifyAccountViewModel verifyAccountViewModel;
    engine.rootContext()->setContextProperty("verifyAccountViewModel", &verifyAccountViewModel);

    Hedral::UI::HomePageViewModel homePageViewModel;
    engine.rootContext()->setContextProperty("homePageViewModel", &homePageViewModel);

    const QUrl url(QStringLiteral("../../Hedral/HedralApp/UI/Views/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
