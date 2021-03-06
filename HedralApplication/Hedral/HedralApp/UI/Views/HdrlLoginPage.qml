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

    Spinner{
        id: spinner
        visible: false
    }

    property var dataJson;

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
        spacing: 5

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
                onTextChanged: {
                    loginViewModel.email = text
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
                onTextChanged: {
                    loginViewModel.password = text
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
                    //hedarlStackView.push("HdrlHomePage.qml", {name: "Ivan Ayala", email: "network.9961@gmail.com", level: "3"})
                    loginPage.opacity = 0.5
                    spinner.visible = true
                    loginViewModel.LogIn();
                }
            }

            HdrlButton {
                text: "Registro"
                mouseField.onClicked: {
                    hedarlStackView.push("HdrlSignUpPage.qml")
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
                text: '¿Has olvidado la contraseña?'
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
                        console.log("Adios mundo")
                        hedarlStackView.push("HdrlRestorePage.qml")
                    }
                }
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
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        //hedarlStackView.push("HdrlAdminLoginPage.qml")
                        console.log("Adios mundo")
                        spinner.visible = true
                    }
                }
            }
        }
    }

    Connections {
        target: loginViewModel

        onResponseChanged: {
            if(loginViewModel.statusCode === 200) {
                spinner.visible = false
                var jsonString = JSON.stringify(JSON.parse(loginViewModel.response));
                var sessionObject = JSON.parse(jsonString);

                hedarlStackView.push("HdrlHomePage.qml", {name: sessionObject.idToken.payload["name"] + " " +sessionObject.idToken.payload["family_name"], email: loginViewModel.email, level: sessionObject.idToken.payload["custom:level"]})
            }
            else {
                console.log("Error with the code!!!")
            }
        }
    }
}
