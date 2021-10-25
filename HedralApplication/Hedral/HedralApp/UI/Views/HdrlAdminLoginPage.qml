import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

import "../Components"

Page {
    id: loginPage
    background: Rectangle {
        color: backGroundColor
    }

    FontLoader {
        id: hdrlFontRegular
        source: "../../Resources/fonts/Inter-Regular.ttf"
    }

    FontLoader {
        id: hdrlFontBold
        source: "../../Resources/fonts/Inter-Bold.ttf"
    }

    ColumnLayout {
        width: parent.width
        spacing: 5
        Label {
            text: "Bienvenido Administrador!"
            font.pointSize: 20
            font.letterSpacing: -1
            font.family: hdrlFontBold.name
            font.bold: Font.Bold
            Layout.alignment: Qt.AlignHCenter
        }
        Item { height: 40 }
        Column {
            width: parent.width
            Layout.alignment: Qt.AlignHCenter
            Label {
                text: "Email"
                font.pointSize: 18
                font.letterSpacing: -1
                font.family: hdrlFontBold.name
                font.bold: Font.Bold
            }

            TextField {
                width: 320
                height: 40
                background: Rectangle {
                    color: "#EDEFF2"
                    radius: 10
                }
                verticalAlignment: TextInput.AlignVCenter
            }
        }


        Column {
            width: parent.width
            Layout.alignment: Qt.AlignHCenter
            Label {
                text: "Contraseña"
                font.pointSize: 18
                font.letterSpacing: -1
                font.family: hdrlFontBold.name
                font.bold: Font.Bold
            }

            TextField {
                width: 320
                height: 40
                echoMode: TextInput.Password

                background: Rectangle {
                    color: "#EDEFF2"
                    radius: 10
                }
                verticalAlignment: TextInput.AlignVCenter
            }
        }

        Item { height: 150 }
        Column {
            width: parent.width
            Layout.alignment: Qt.AlignHCenter
            spacing: 10
            HdrlButton {
                text: "Iniciar Sesion"
                mouseField.onClicked: {
                    console.log("Hola mundo!");
                }
            }
        }

        Item { height: 100 }

        Column {
            Layout.alignment: Qt.AlignRight
            spacing: 5
            rightPadding: 10

            Text {
                id: nameLink
                text: '¿Eres un Usuario?'
                linkColor: mainTextCOlor
                Layout.alignment: Qt.AlignHCenter
                font.pointSize: 10
                font.underline: true
                color: "#000000"
                Layout.margins: 10
                onLinkActivated: forgotPassword()
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        hedarlStackView.pop()
                    }
                }
            }

        }
    }
}
