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
            success: true
            text: "Hola"
        }

        HdrlTextField {
            success: true
        }

        Item {
            height: 50
        }

        HdrlButton {

        }

        HdrlButton {
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
