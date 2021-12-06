import QtQuick 2.7

Row
{
    anchors.right: parent.right
    spacing: 8
    anchors.rightMargin: 10
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
