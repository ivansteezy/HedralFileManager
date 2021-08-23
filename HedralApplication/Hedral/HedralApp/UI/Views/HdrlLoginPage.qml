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

        TextField {
            id: loginUsername
            placeholderText: qsTr("User name")
            Layout.preferredWidth: parent.width - 20
            Layout.alignment: Qt.AlignHCenter
            color: mainTextCOlor
            font.pointSize: 14
            leftPadding: 30
            background: Rectangle {
                implicitWidth: 200
                implicitHeight: 40
                radius: implicitHeight / 2
                color: "transparent"

                Text {
                    text: "\uf007"
                    font.pointSize: 14
                    font.family: "fontawesome"
                    color: mainAppColor
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    leftPadding: 10
                }

                Rectangle {
                    width: parent.width - 10
                    height: 1
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    color: mainAppColor
                }
            }
        }

        TextField {
            id: loginPassword
            placeholderText: qsTr("Password")
            Layout.preferredWidth: parent.width - 20
            Layout.alignment: Qt.AlignHCenter
            color: mainTextCOlor
            font.pointSize: 14
            font.family: "fontawesome"
            leftPadding: 30
            echoMode: TextField.Password
            background: Rectangle {
                implicitWidth: 200
                implicitHeight: 40
                radius: implicitHeight / 2
                color: "transparent"
                Text {
                    text: "\uf023"
                    font.pointSize: 14
                    font.family: "fontawesome"
                    color: mainAppColor
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    leftPadding: 10
                }

                Rectangle {
                    width: parent.width - 10
                    height: 1
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    color: mainAppColor
                }
            }
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
            // onClicked: stackView.push("qrc:/RegisterScreen.qml", {"uname": "arun", "pword": "some"}) //registerClicked()
            onClicked: {
                console.log('sign up button clicked')
                popup.popMessage = "Has presionado el boton de Signup"
                popup.open()
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
