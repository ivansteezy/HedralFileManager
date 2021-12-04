import QtQuick 2.7
import Qt.labs.platform 1.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.15

import "../Components"

Page {

    property string email: ""
    property string name: ""
    property string level: ""
    property var levels: []
    property var files: []

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


    function generateLevels() {
        switch(level) {
            case "1": levels = ["Nivel 1"];                       break;
            case "2": levels = ["Nivel 1", "Nivel 2"];            break;
            case "3": levels = ["Nivel 1", "Nivel 2", "Nivel 3"]; break;
        }
    }

    Component.onCompleted: {
        hedralWindow.width = 1200
        hedralWindow.height = 800

        hedralWindow.x = Screen.width / 2 - hedralWindow.width / 2
        hedralWindow.y = Screen.height / 2 - hedralWindow.height / 2

        this.generateLevels()
    }

    HdrlSideMenu {
        displayEmail: email
        displayName:  name
        displayLevel:  level
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
                    homePageViewModel.SearchFiles()
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
                    model: levels
                    checkedColor: "#727CF5"
                    onCurrentIndexChanged: {
                        homePageViewModel.level = model[currentIndex];
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

//        HdrlButton {
//            text: "Ir a las stats"
//            mouseField.onClicked: {
//                hedarlStackView.push("HdrlStatisticsPage.qml")
//            }
//        }

        HdrlButton {
            text: "Open Modal"
            mouseField.onClicked: {
                // fileDialog.open()
                popup.open()
            }
        }

        Popup {
            id: popup
            x: hedralWindow.width / 4
            y: hedralWindow.height / 4
            width: hedralWindow.width / 2
            height: hedralWindow.height / 2
            modal: true
            focus: true
            closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

            Column {
                anchors.fill: parent

                Column {
                    topPadding: 30
                    width: parent.width - 50
                    anchors.horizontalCenter: parent.horizontalCenter
                    bottomPadding: 30
                    Label {
                        text: "Nombre del archivo"
                        font.pointSize: 18
                        font.letterSpacing: -1
                        font.family: hdrlFontBold.name
                        font.bold: Font.Bold
                    }

                    TextField {
                        width: parent.width
                        height: 40

                        background: Rectangle {
                            color: "#e3e3e3"
                            radius: 10
                        }
                        verticalAlignment: TextInput.AlignVCenter
                    }
                }


                Column {
                    width: parent.width - 50
                    anchors.horizontalCenter: parent.horizontalCenter
                    Label {
                        text: "Ruta del archivo"
                        font.pointSize: 18
                        font.letterSpacing: -1
                        font.family: hdrlFontBold.name
                        font.bold: Font.Bold
                    }

                    TextField {
                        width: parent.width
                        height: 40

                        background: Rectangle {
                            color: "#e3e3e3"
                            radius: 10
                        }
                        verticalAlignment: TextInput.AlignVCenter
                    }
                }


                Item {
                    width: parent.width - 50
                    anchors.horizontalCenter: parent.horizontalCenter

                    height: 80
                }

                RowLayout {
                    width: parent.width - 50
                    anchors.horizontalCenter: parent.horizontalCenter
                    HdrlButton {
                        text: "Examinar..."
                        Layout.alignment: Qt.AlignLeft
                        mouseField.onClicked: {
                            fileDialog.open()
                        }
                    }

                    HdrlButton {
                        text: "Subir archivo"
                        Layout.alignment: Qt.AlignRight
                        mouseField.onClicked: {
                            console.log("Subiendo archivo")
                        }
                    }
                }
            }
        }

        FileDialog {
            id: fileDialog
            fileMode: FileDialog.OpenFile
            folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
            nameFilters: ["Text files (*.txt)", "Pdf files(*.pdf)" ,"Docx files (*.docx)"]
            onAccepted: {
                console.log("You choose: " + fileDialog.currentFile);
            }
            onRejected: {
                console.log("Cancelado");
            }
        }
    }

    Connections {
        target: homePageViewModel

        onResponseChanged: {
            if(homePageViewModel.statusCode === 200) {
                var jsonString = JSON.stringify(JSON.parse(homePageViewModel.response)); //json as string
                var jsonObject = JSON.parse(jsonString);

                for(var i = 0; i < jsonObject.Contents.length; i++) {
                    var fileName = jsonObject.Contents[i].Key
                    var date = jsonObject.Contents[i].LastModified
                    var fileType = jsonObject.Contents[i].Key.split('.')[1];
                    var size = jsonObject.Contents[i].Size;

                    console.log("File name: ", fileName)
                    console.log("Fecha: ", date)
                    console.log("Tamanio: ", size)
                    console.log("Tipo: ", fileType)
                }
            }
            else {
                console.log("Error requesting files");
            }
        }
    }
}
