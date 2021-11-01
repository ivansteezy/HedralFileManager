import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.15

Drawer {
    id: sideMenu
    width: 0.3 * hedralWindow.width
    height: hedralWindow.height
    background: Rectangle {
        anchors.fill: parent
        color: "#971ADB"
    }

    ColumnLayout {
        width: parent.width
        height: parent.height
        Label {
            Layout.alignment: Qt.AlignLeft
            anchors.top: parent.top
            text: "Ivan Ayala"
            font.pointSize: 18
            font.letterSpacing: -1
            font.family: hdrlFontBold.name
            font.bold: Font.Bold
            color: "white"
            leftPadding: 10
        }


        Label {
            Layout.alignment: Qt.AlignLeft
            text: "network.9961@gmail.com"
            font.pointSize: 14
            font.letterSpacing: -1
            font.family: hdrlFontRegular.name
            font.bold: Font.Light
            color: "white"
            leftPadding: 10
        }

        Label {
            Layout.alignment: Qt.AlignLeft
            text: "Nivel 3"
            font.pointSize: 14
            font.letterSpacing: -1
            font.family: hdrlFontRegular.name
            font.bold: Font.Light
            color: "white"
            leftPadding: 10

        }

        Rectangle {
            Layout.alignment: Qt.AlignCenter
            Layout.preferredWidth: parent.width - 20
            Layout.preferredHeight: 1
            color: "white"

        }

        Item {
            Layout.fillHeight: true
        }

        Label {
            Layout.alignment: Qt.AlignLeft
            text: 'Cerrar sesion'
            font.pointSize: 14
            font.letterSpacing: -1
            font.family: hdrlFontRegular.name
            font.bold: Font.Light
            font.underline: true
            anchors.bottom: parent.bottom
            color: "white"
            leftPadding: 10
            bottomPadding: 10
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    hedarlStackView.pop()

                    hedralWindow.width = 350
                    hedralWindow.height = 650

                    hedralWindow.x = Screen.width / 2 - hedralWindow.width / 2
                    hedralWindow.y = Screen.height / 2 - hedralWindow.height / 2
                }
            }
        }
    }
}
