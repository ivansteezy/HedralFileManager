import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.12

Window {
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
}
