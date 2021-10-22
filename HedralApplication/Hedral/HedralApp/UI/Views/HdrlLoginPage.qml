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
        spacing: 10


        Label {
            text: "Contraseña"
            font.pointSize: 20
            font.family: hdrlFontBold.name
            font.bold: Font.Bold
        }

        TextField {
            Layout.preferredWidth: 300
            Layout.preferredHeight: 50
            placeholderText: qsTr("Enter name")
            background: Rectangle {
                color: "#EDEFF2"
                radius: 10
            }
            verticalAlignment: TextInput.AlignVCenter
        }

        Label {
            text: "Email"
            font.pointSize: 20
            //font.family: hdrlFontRegular.name
            font.bold: Font.Bold
        }


        Item {
            height: 50
        }

        HdrlButton {
            text: "Syro"
            mouseField.onClicked: {
                console.log("Hola mundo!");
            }
        }

        HdrlDropDown {
            model: ["First", "Second", "Third"]
            checkedColor: "#727CF5"
            onCurrentIndexChanged: {
                console.log("Se selecciono " + model[currentIndex])
            }
        }

        Text {
            id: name
            text: 'Hola mundo'
            linkColor: mainTextCOlor
            Layout.alignment: Qt.AlignHCenter
            font.pointSize: 10
            font.underline: true
            color: "#000000"
            Layout.margins: 10
            onLinkActivated: forgotPassword()
        }
    }
}
