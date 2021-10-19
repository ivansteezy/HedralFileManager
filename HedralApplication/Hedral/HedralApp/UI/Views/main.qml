import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.12
import QtQuick.Window 2.1

Window {
    property color backGroundColor : "#ffffff"
    property color mainAppColor: "#9c6af7"
    property color mainTextCOlor: "#f0f0f0"
    property color popupBackGroundColor: "#b44"
    property color popupTextCOlor: "#ffffff"
    property Window hedralWindow: window
    id: window

    width: 350
    height: 650
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

    Popup {
        id: popup
        modal: true
        focus: true
        closePolicy: Popup.CloseOnPressOutside

        property alias popMessage: message.text
        background: Rectangle {
            implicitHeight: 60
            color: "#b44"
        }

        Text {
            id: message
            anchors.centerIn: parent
            font.pointSize: 12
            color: "#ffffff"
        }
        onOpened: popupClose.start()
    }

    Timer {
        id: popupClose
        interval: 2000
        onTriggered: popup.close()
    }
}
