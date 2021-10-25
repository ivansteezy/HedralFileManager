import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.15

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


    id: loginPage
    background: Rectangle {
        color: backGroundColor
    }

    anchors.fill: parent
    Component.onCompleted: {
        hedralWindow.width = 1200
        hedralWindow.height = 800

        hedralWindow.x = Screen.width / 2 - hedralWindow.width / 2
        hedralWindow.y = Screen.height / 2 - hedralWindow.height / 2
    }

    Column {
        anchors.fill: parent
        Row {
            width: parent.width
            height: parent.height / 10
            spacing: 10
            leftPadding: 10

            TextField {
                width: parent.width / 1.2
                height: 40
                echoMode: TextInput.Password

                background: Rectangle {
                    color: "#EDEFF2"
                    radius: 10
                }
                verticalAlignment: TextInput.AlignVCenter
            }

            HdrlButton {
                width: parent.width / 7
                text: "Buscar"
                mouseField.onClicked: {
                    console.log("Buscar el archivo!");
                }
            }
        }

        Row {
            width: parent.width
            height: parent.height / 10
            Column {
                width: parent.width / 3
                Layout.alignment: Qt.AlignHCenter
                leftPadding: 10
                Label {
                    text: "Texo"
                    font.pointSize: 18
                    font.letterSpacing: -1
                    font.family: hdrlFontBold.name
                    font.bold: Font.Bold
                }

                HdrlDropDown {
                    width: parent.width - 20
                    height: 40
                    model: ["Titulo", "Contenido"]
                    checkedColor: "#727CF5"
                    onCurrentIndexChanged: {
                        console.log("Se selecciono " + model[currentIndex])
                    }
                }
            }
            Column {
                width: parent.width / 3
                Layout.alignment: Qt.AlignHCenter
                leftPadding: 10
                Label {
                    text: "Tipo de archivo"
                    font.pointSize: 18
                    font.letterSpacing: -1
                    font.family: hdrlFontBold.name
                    font.bold: Font.Bold
                }

                HdrlDropDown {
                    width: parent.width - 20
                    height: 40
                    model: ["PDF", "Texto", "Docx"]
                    checkedColor: "#727CF5"
                    onCurrentIndexChanged: {
                        console.log("Se selecciono " + model[currentIndex])
                    }
                }
            }
            Column {
                width: parent.width / 3
                Layout.alignment: Qt.AlignHCenter
                Label {
                    text: "Nivel"
                    font.pointSize: 18
                    font.letterSpacing: -1
                    font.family: hdrlFontBold.name
                    font.bold: Font.Bold
                }

                HdrlDropDown {
                    width: parent.width - 20
                    height: 40
                    model: ["Nivel 1", "Nivel 2", "Nivel 3"]
                    checkedColor: "#727CF5"
                    onCurrentIndexChanged: {
                        console.log("Se selecciono el nivel" + model[currentIndex])
                    }
                }
            }
        }

        ListView {
            clip: true
            width: parent.width
            height: parent.height / 1.3
            leftMargin: 10
            flickableDirection: Flickable.AutoFlickDirection
            headerPositioning: ListView.OverlayHeader

            header: Row {
                width: parent.width
                bottomPadding: 20

                Text {
                    width: parent.width / 5
                    text: "Nombre"
                    font.bold: Font.Bold
                    font.pointSize: 16
                }

                Text {
                    width: parent.width / 5
                    text: "Fecha"
                    font.bold: Font.Bold
                    font.pointSize: 16
                }

                Text {
                    width: parent.width / 5
                    text: "Tipo"
                    font.bold: Font.Bold
                    font.pointSize: 16
                }

                Text {
                    width: parent.width / 5
                    text: "Tamaño"
                    font.bold: Font.Bold
                    font.pointSize: 16
                }
            }

            model: ListModel {
                ListElement {
                    fileName: "Reporte de inventario"
                    date: "12-10-2021"
                    type: "Texto"
                    size: "10mb"
                }

                ListElement {
                    fileName: "Reporte de inventario"
                    date: "12-10-2021"
                    type: "Texto"
                    size: "10mb"
                }

                ListElement {
                    fileName: "Reporte de inventario"
                    date: "12-10-2021"
                    type: "Texto"
                    size: "10mb"
                }
            }

            delegate: Row {
                width: parent.width
                Text {
                    width: parent.width / 5
                    font.pointSize: 16
                    text: model.fileName
                }
                Text {
                    width: parent.width / 5
                    font.pointSize: 16
                    text: model.date
                }
                Text {
                    width: parent.width / 5
                    font.pointSize: 16
                    text: model.type
                }
                Text {
                    width: parent.width / 5
                    font.pointSize: 16
                    text: model.size
                }
            }

            ScrollBar.vertical: ScrollBar {
                active: true
            }
        }

        HdrlButton {
            text: "Ir a las stats"
            mouseField.onClicked: {
                hedarlStackView.push("HdrlStatisticsPage.qml")
            }
        }
    }
}
