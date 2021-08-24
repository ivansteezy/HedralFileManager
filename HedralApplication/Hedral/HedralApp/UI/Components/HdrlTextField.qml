import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

TextField {
    id: formTextField

    property alias placeHolder: formTextField.placeholderText
    property alias textType: formTextField.echoMode
    property alias fontSize: formTextField.font.pixelSize
    property alias icon: texFieldIcon.sourceComponent

    placeholderText: qsTr("Lorem")
    Layout.preferredWidth: parent.width - 20
    Layout.alignment: Qt.AlignHCenter
    color: mainTextCOlor
    font.pointSize: 14
    font.family: "fontawesome"
    leftPadding: 30
    background: Rectangle {
        implicitWidth: 200
        implicitHeight: 40
        radius: implicitHeight / 2
        color: "transparent"
        Loader { id: texFieldIcon }

        Rectangle {
            width: parent.width - 10
            height: 1
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            color: mainAppColor
        }
    }
}
