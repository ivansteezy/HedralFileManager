import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

Text {
    id: controlIcon

    property alias icon: controlIcon.text

    font.pointSize: 14
    font.family: "fontawesome"
    color: mainAppColor
    anchors.left: parent.left
    anchors.verticalCenter: parent.verticalCenter
    leftPadding: 10
}
