import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 2.2

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Drawer {
        id: drawer
        width: 0.66 * window.width
        height: window.height
        //dragMargin: 100

        Label {
            text: "Content goes here!"
            anchors.centerIn: parent
        }
    }

    ChartView {
        id: chart
        title: "Top-5 car brand shares in Finland"
        anchors.fill: parent
        legend.alignment: Qt.AlignBottom
        antialiasing: true

        PieSeries {
            id: pieSeries
            PieSlice { label: "Volkswagen"; value: 13.5 }
            PieSlice { label: "Toyota"; value: 10.9 }
            PieSlice { label: "Ford"; value: 8.6 }
            PieSlice { label: "Skoda"; value: 8.2 }
            PieSlice { label: "Volvo"; value: 6.8 }
        }
    }

    Component.onCompleted: {
        othersSlice = pieSeries.append("Others", 52.0);
        pieSeries.find("Volkswagen").exploded = true;
    }

    Button {
        text: "Menu"
        onClicked: {
            drawer.open()
            console.log("Hola")
        }
    }
}
