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

//    Rectangle {
//        id: iconRect
//        width: parent.width
//        height: parent.height / 3
//        color: backGroundColor

//        Text {
//            id: icontext
//            text: qsTr("\uf216")
//            anchors.centerIn: parent
//            font.pointSize: 100
//            font.family: "fontawesome"
//            color: mainAppColor
//        }
//    }

    ColumnLayout {
        width: parent.width
        anchors.top: iconRect.bottom
        spacing: 5

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
                placeholderText: qsTr("Enter name")
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
                placeholderText: qsTr("Enter name")
                background: Rectangle {
                    color: "#EDEFF2"
                    radius: 10
                }
                verticalAlignment: TextInput.AlignVCenter
            }
        }

        Item { height: 200 }
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

            HdrlButton {
                text: "Registro"
                mouseField.onClicked: {
                    console.log("Hola mundo!");
                }
            }
        }


//        HdrlDropDown {
//            model: ["First", "Second", "Third"]
//            checkedColor: "#727CF5"
//            onCurrentIndexChanged: {
//                console.log("Se selecciono " + model[currentIndex])
//            }
//        }

        Column {

        }

        Text {
            id: nameLink
            text: '¿Has olvidado la contraseña?'
            linkColor: mainTextCOlor
            Layout.alignment: Qt.AlignHCenter
            font.pointSize: 10
            font.underline: true
            color: "#000000"
            Layout.margins: 10
            onLinkActivated: forgotPassword()
        }

        Text {
            id: isAdminLink
            text: '¿Es un administrador?'
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
