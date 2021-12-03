QT += quick qml widgets core network charts gui quickcontrols2

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Services/HFMBootstraping/SystemInitializer.cpp \
        Services/HFMBootstraping/SystemInitializerBase.cpp \
        Services/HFMBootstraping/main.cpp \
        Services/HFMCore/HedralCore.cpp \
        Services/HFMLogger/Logger.cpp \
        Services/HFMLogger/LoggerBase.cpp \
        Services/HFMNetworking/JsonSerializer.cpp \
        Services/HFMNetworking/NetworkManager.cpp \
        Services/HFMNetworking/NetworkingBase.cpp \
        Services/HFMStatistics/StatisticsBase.cpp \
        Services/HFMStatistics/StatisticsManager.cpp \
        UI/ViewModels/AdminLoginViewModel.cpp \
        UI/ViewModels/LoginViewModel.cpp \
        UI/ViewModels/RestorePasswordViewModel.cpp \
        UI/ViewModels/SignUpViewModel.cpp \
        UI/ViewModels/VerifyAccountViewModel.cpp

RESOURCES += Resources/qml.qrc \

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    UI/Components/Constants.qml \
    UI/Components/HdrlDropDown.qml \
    UI/Components/HdrlIcon.qml \
    UI/Components/HdrlPopUp.qml \
    UI/Components/HdrlTextField.qml \
    UI/Components/SideMenu.qml \
    UI/Views/CButton.qml \
    UI/Views/HdrlAdminLoginPage.qml \
    UI/Views/HdrlHomePage.qml \
    UI/Views/HdrlLoginPage.qml \
    UI/Views/HdrlRestorePage.qml \
    UI/Views/HdrlSignUpPage.qml \
    UI/Views/HdrlStatisticsPage.qml \
    UI/Views/HdrlVerifyAccountPage.qml \
    UI/Views/main.qml

HEADERS += \
    Services/HFMBootstraping/SystemInitializer.hpp \
    Services/HFMBootstraping/SystemInitializerBase.hpp \
    Services/HFMCore/TestCore.h \
    Services/HFMCore/HedralCore.hpp \
    Services/HFMCore/HedralCoreMacros.hpp \
    Services/HFMLogger/Logger.hpp \
    Services/HFMLogger/LoggerBase.hpp \
    Services/HFMNetworking/JsonSerializer.hpp \
    Services/HFMNetworking/NetworkManager.hpp \
    Services/HFMNetworking/NetworkingBase.hpp \
    Services/HFMNetworking/ReplyTimeOut.hpp \
    Services/HFMStatistics/StatisticsBase.hpp \
    Services/HFMStatistics/StatisticsManager.hpp \
    UI/ViewModels/AdminLoginViewModel.hpp \
    UI/ViewModels/Foundation.hpp \
    UI/ViewModels/LoginViewModel.hpp \
    UI/ViewModels/RestorePasswordViewModel.hpp \
    UI/ViewModels/SignUpViewModel.hpp \
    UI/ViewModels/VerifyAccountViewModel.hpp
