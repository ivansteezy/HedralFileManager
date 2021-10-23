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

//    HdrlButton {
//        text: "Ir a las stats"
//        mouseField.onClicked: {
//            hedarlStackView.push("HdrlStatisticsPage.qml")
//        }
//    }


    Column {
        anchors.fill: parent
//        Row {
//            width: parent.width
//            Layout.alignment: Qt.AlignHCenter
//            TextField {
//                //width: parent.width
//                height: 40
//                echoMode: TextInput.Password

//                background: Rectangle {
//                    color: "#EDEFF2"
//                    radius: 10
//                }
//                verticalAlignment: TextInput.AlignVCenter
//            }

//            HdrlButton {
//                text: "Buscar"
//                mouseField.onClicked: {
//                    console.log("Buscar el archivo!");
//                }
//            }
//        }
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
                leftPadding: 10
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

        Rectangle {
            color: "pink"
            width: parent.width
            height: parent.height / 1.255
        }
    }

//    ToolBar {
//        id: overlayHeader

//        z: 1
//        width: parent.width
//        parent: Overlay.overlay

//        Label {
//            id: label
//            anchors.centerIn: parent
//            text: "Qt Quick Controls"
//        }
//    }

//    Drawer {
//        id: drawer

//        y: overlayHeader.height
//        width: window.width / 2
//        height: window.height - overlayHeader.height

//        modal: inPortrait
//        interactive: inPortrait
//        position: inPortrait ? 0 : 1
//        visible: !inPortrait

//        ListView {
//            id: listView
//            anchors.fill: parent
//            height: parent.height

//            headerPositioning: ListView.OverlayHeader
//            header: Pane {
//                id: header
//                z: 2
//                width: parent.width

//                contentHeight: logo.height

//                Image {
//                    id: logo
//                    width: parent.width
//                    fillMode: implicitWidth > width ? Image.PreserveAspectFit : Image.Pad
//                }

//                MenuSeparator {
//                    parent: header
//                    width: parent.width
//                    anchors.verticalCenter: parent.bottom
//                    visible: !listView.atYBeginning
//                }
//            }

//            footer: ItemDelegate {
//                id: footer
//                text: qsTr("Footer")
//                width: parent.width

//                MenuSeparator {
//                    parent: footer
//                    width: parent.width
//                    anchors.verticalCenter: parent.top
//                }
//            }

//            model: 10

//            delegate: ItemDelegate {
//                text: qsTr("Title %1").arg(index + 1)
//                width: listView.width
//            }

//            ScrollIndicator.vertical: ScrollIndicator { }
//        }
//    }

}
