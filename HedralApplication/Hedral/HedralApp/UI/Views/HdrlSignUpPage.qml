import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

import "../Components"

Page {

    property alias emailForm: textFieldEmail.text
    property alias passwordForm: textFieldPassword.text

    id: registerPage
    background: Rectangle {
        color: backGroundColor
    }

    Item { height: 50 }

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
            placeHolder: "Apellidos"
            textType: TextField.text

            icon: HdrlIcon { icon: "\uf023" }
        }

        HdrlTextField {
            id: textFieldEmail
            fontSize: 14
            placeHolder: "E-mail"
            textType: TextField.text

            icon: HdrlIcon { icon: "\uf023" }
        }

        HdrlTextField {
            id: textFieldPassword
            fontSize: 14
            placeHolder: "Contraseña"
            textType: TextField.Password
            icon: HdrlIcon { icon: "\uf023" }
        }

        HdrlTextField {
            fontSize: 14
            placeHolder: "Confirmar contraseña"
            textType: TextField.Password

            icon: HdrlIcon { icon: "\uf023" }
        }

        Item { height: 50 }

        HdrlButton {
            height: 50
            Layout.preferredWidth: registerPage.width - 20
            Layout.alignment: Qt.AlignHCenter
            name: "Registrarte"
            baseColor: "transparent"
            borderColor: mainAppColor
            onClicked: {
                console.log("La contra es: " + passwordForm + "el user es: " + emailForm)
            }
        }

        Text {
            id: name
            text: '<html><style type="text/css"></style><a href="http://google.com">Ya tienes una cuenta?</a></html>' //qsTr("Forgot password?")
            linkColor: mainTextCOlor
            Layout.alignment: Qt.AlignHCenter
            font.pointSize: 14
            color: mainTextCOlor
            Layout.margins: 10
            onLinkActivated: forgotPassword()
        }
    }
}
