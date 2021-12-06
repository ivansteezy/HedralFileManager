import QtQuick 2.7

Row
{
    id: root
    //anchors.right: parent.right
    spacing: 8
    //anchors.rightMargin: 10
    z: 100
    width: parent.width
    height: parent.height
    anchors.verticalCenter: parent.Center
    anchors.horizontalCenter: parent.horizontalCenter
    // Rotating icon
    Text
    {
        id: loadingSpinner
        font.family: fontAwesome.name
        text: "\uf021"
        font.pixelSize: 18
        color: "#0091f8";

        NumberAnimation on rotation {
            from: 0; to: 360; running: loadingSpinner.visible == true;
            loops: Animation.Infinite; duration: 700;
        }
    }

    // Text explaining whats happening
    Text {
        text: "Cargando"
        font.family: "Lato"
        font.pixelSize: 16
    }
}
