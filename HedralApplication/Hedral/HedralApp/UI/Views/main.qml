import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.12

Window {
    property color backGroundColor : "#394454"
    property color mainAppColor: "#6fda9c"
    property color mainTextCOlor: "#f0f0f0"
    property color popupBackGroundColor: "#b44"
    property color popupTextCOlor: "#ffffff"

    flags: Qt.FramelessWindowHint | Qt.WindowMinimized
    id: window
    width: 350
    height: 600
    visible: true
    title: qsTr("Hello World")



    GridLayout {
        width: parent.width

        Row {
            width: parent.width
            Layout.alignment: Qt.AlignRight
            Layout.topMargin: 5
            Layout.rightMargin: 5
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
        interval: 1000
        onTriggered: popup.close()
    }

    StackView {
        id: hedarlStackView
        focus: true
        anchors.fill: parent
    }

    Component.onCompleted: {
        hedarlStackView.push("Login.qml")
    }
}
