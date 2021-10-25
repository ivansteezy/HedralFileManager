QT += quick qml widgets core network charts gui quickcontrols2

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Services/HFMBootstraping/main.cpp

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
    UI/Views/CButton.qml \
    UI/Views/HdrlHomePage.qml \
    UI/Views/HdrlLoginPage.qml \
    UI/Views/HdrlSignUpPage.qml \
    UI/Views/HdrlStatisticsPage.qml \
    UI/Views/main.qml
