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

                Image {
                    width: 20
                    height: 20
                    source: "qrc:/img/inside.png"
                    anchors.leftMargin: 2
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            console.log('Minimize')
                            window.visibility = Window.Minimized
                        }
                    }
                }

                Image {
                    width: 20
                    height: 20
                    source: "qrc:/img/cancel.png"
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

            //should i put pop up here?
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
}
