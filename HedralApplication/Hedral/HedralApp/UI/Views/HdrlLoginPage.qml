import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

import "../Components"

Page {
    id: loginPage
    background: Rectangle {
        color: backGroundColor
    }

    Rectangle {
        id: iconRect
        width: parent.width
        height: parent.height / 3
        color: backGroundColor

        Text {
            id: icontext
            text: qsTr("\uf216")
            anchors.centerIn: parent
            font.pointSize: 100
            font.family: "fontawesome"
            color: mainAppColor
        }
    }

    ColumnLayout {
        width: parent.width
        anchors.top: iconRect.bottom
        spacing: 15

        HdrlTextField {
            fontSize: 14
            placeHolder: "Nombre"
            textType: TextField.text

            icon: HdrlIcon { icon: "\uf023" }
        }

        HdrlTextField {
            fontSize: 14
            placeHolder: "Contraseña"
            textType: TextField.Password

            icon: HdrlIcon { icon: "\uf023" }
        }

        Item {
            height: 50
        }

        HdrlButton {
            height: 50
            Layout.preferredWidth: loginPage.width - 20
            Layout.alignment: Qt.AlignHCenter
            name: "Log In"
            baseColor: mainAppColor
            borderColor: mainAppColor
            onClicked: {
                console.log('Login button clicked!');
            }
        }

        HdrlButton {
            height: 50
            Layout.preferredWidth: loginPage.width - 20
            Layout.alignment: Qt.AlignHCenter
            name: "Sign Up"
            baseColor: "transparent"
            borderColor: mainAppColor
            onClicked: {
                console.log('sign up button clicked')
                popup.popMessage = "Has presionado el boton de Signup"
                popup.open()
                hedarlStackView.push("HdrlSignUpPage.qml")
            }
        }

        Text {
            id: name
            text: '<html><style type="text/css"></style><a href="http://google.com">Forgot password?</a></html>' //qsTr("Forgot password?")
            linkColor: mainTextCOlor
            Layout.alignment: Qt.AlignHCenter
            font.pointSize: 14
            color: mainTextCOlor
            Layout.margins: 10
            onLinkActivated: forgotPassword()
        }
    }
}
