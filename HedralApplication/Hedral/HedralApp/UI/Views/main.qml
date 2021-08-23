import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.12
import QtQuick.Window 2.1

Window {
    property color backGroundColor : "#394454"
    property color mainAppColor: "#9c6af7"
    property color mainTextCOlor: "#f0f0f0"
    property color popupBackGroundColor: "#b44"
    property color popupTextCOlor: "#ffffff"

    flags: Qt.FramelessWindowHint | Qt.WindowMinimized
    id: window
    width: 350
    height: 600
    visible: true
    title: qsTr("Hello World")
    color: backGroundColor

    FontLoader {
        id: fontAwesome
        source: "../../Resources/fonts/fontawesome-webfont.ttf"
    }

    GridLayout {
        id: mainGrid
        anchors.fill: parent

        rows: 20
        columns: 15

        property double colMulti: mainGrid.width  / mainGrid.columns
        property double rowMulti: mainGrid.height / mainGrid.rows
        function prefWidth(item)  { return colMulti * item.Layout.columnSpan }
        function prefHeight(item) { return rowMulti * item.Layout.rowSpan    }


        Rectangle {
            id : greenRect
            Layout.rowSpan : 1
            Layout.columnSpan : 15
            Layout.preferredWidth  : mainGrid.prefWidth(this)
            Layout.preferredHeight : mainGrid.prefHeight(this)
            color: backGroundColor
            Row {
                Layout.topMargin: 5
                Layout.rightMargin: 5
                anchors.right: parent.right
                spacing: 3

                Text {
                    id: minimize
                    text: qsTr("\uf2d1")
                    font.pointSize: 15
                    font.family: "fontawesome"
                    color: mainAppColor
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            console.log('Minimize')
                            window.visibility = Window.Minimized
                        }
                    }
                }

                Text {
                    id: close
                    text: qsTr("\uf00d")
                    font.pointSize: 15
                    font.family: "fontawesome"
                    color: mainAppColor
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            Qt.quit()
                        }
                    }
                }
            }
        }
        Rectangle {
            Layout.rowSpan   : 19
            Layout.columnSpan: 15
            Layout.preferredWidth  : mainGrid.prefWidth(this)
            Layout.preferredHeight : mainGrid.prefHeight(this)

            StackView {
                id: hedarlStackView
                focus: true
                anchors.fill: parent
            }

            Component.onCompleted: {
                hedarlStackView.push("HdrlLoginPage.qml")
            }
        }
    }

    //Popup to show messages or warnings on the bottom position of the screen
    Popup {
        id: popup
        property alias popMessage: message.text
        background: Rectangle {
            //implicitWidth: rootWindow.width
            implicitHeight: 60
            color: "#b44"
        }
        //y: rootWindow.height
        modal: true
        focus: true
        closePolicy: Popup.CloseOnPressOutside

        Text {
            id: message
            anchors.centerIn: parent
            font.pointSize: 12
            color: "#ffffff"
        }
        onOpened: popupClose.start()
    }

    // Popup will be closed automatically in 2 seconds after its opened
    Timer {
        id: popupClose
        interval: 2000
        onTriggered: popup.close()
    }
}
