import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

import "../Components"

Page {
    FontLoader {
        id: hdrlFontRegular
        source: "../../Resources/fonts/Inter-Regular.ttf"
    }

    FontLoader {
        id: hdrlFontBold
        source: "../../Resources/fonts/Inter-Bold.ttf"
    }

    id: registerPage
    background: Rectangle {
        color: backGroundColor
    }

    ColumnLayout {
        width: parent.width
        spacing: 5

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
                    signUpViewModel.email = text;
                }

                verticalAlignment: TextInput.AlignVCenter
            }
        }

        Column {
            width: parent.width
            Layout.alignment: Qt.AlignHCenter
            Label {
                text: "Nombre"
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
                    signUpViewModel.name = text;
                }
                verticalAlignment: TextInput.AlignVCenter
            }
        }

        Column {
            width: parent.width
            Layout.alignment: Qt.AlignHCenter
            Label {
                text: "Apellido"
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
                    signUpViewModel.lastName = text;
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
                    signUpViewModel.password = text;
                }
                verticalAlignment: TextInput.AlignVCenter
            }
        }

        Column {
            width: parent.width
            Layout.alignment: Qt.AlignHCenter
            Label {
                text: "Confirma contraseña"
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
                    signUpViewModel.confirmPassword = text;
                }
                verticalAlignment: TextInput.AlignVCenter
            }
        }

        Column {
            width: parent.width
            Layout.alignment: Qt.AlignHCenter
            Label {
                text: "Nivel"
                font.pointSize: 18
                font.letterSpacing: -1
                font.family: hdrlFontBold.name
                font.bold: Font.Bold
            }

            HdrlDropDown {
                width: 320
                height: 40
                model: ["Nivel 1", "Nivel 2", "Nivel 3"]
                checkedColor: "#727CF5"
                onCurrentIndexChanged: {
                    const level = model[currentIndex];
                    signUpViewModel.level = level.substr(level.length - 1);
                }
            }
        }

        Item { height: 10 }

        HdrlButton {
            Layout.alignment: Qt.AlignHCenter
            text: "Registrarse"
            mouseField.onClicked: {
                signUpViewModel.SignUp();
            }
        }

        Item { height: 10 }

        Text {
            id: isAdminLink
            text: '¿Ya tienes una cuenta?'
            linkColor: mainTextCOlor
            Layout.alignment: Qt.AlignRight
            font.pointSize: 10
            font.underline: true
            color: "#000000"
            Layout.margins: 10
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    hedarlStackView.pop()
                    console.log("Adios mundo")
                }
            }
        }
    }

    Connections {
        target: signUpViewModel

        onStatusCodeChanged: {
            if(signUpViewModel.statusCode === 200) {
                hedarlStackView.push("HdrlVerifyAccountPage.qml", {user: signUpViewModel.email})
            }
            else {
                console.log('Error creating your account')
            }
        }
    }
}
