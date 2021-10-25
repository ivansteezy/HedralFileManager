import QtQuick 2.0
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.15
import QtCharts 2.3

import "../Components"

Page {
    id: loginPage
    background: Rectangle {
        color: backGroundColor
    }

    FontLoader {
        id: hdrlFontRegular
        source: "../../Resources/fonts/Inter-Regular.ttf"
    }

    FontLoader {
        id: hdrlFontBold
        source: "../../Resources/fonts/Inter-Bold.ttf"
    }



    ColumnLayout {
        anchors.fill: parent

        Label {
            Layout.alignment: Qt.AlignHCenter
            anchors.top: parent.top
            text: "Estadisticas del archivo"
            font.pointSize: 18
            font.letterSpacing: -1
            font.family: hdrlFontBold.name
            font.bold: Font.Bold
        }

        ChartView {
            Layout.alignment: Qt.AlignHCenter
            title: "Stacked Bar series"
            width: 700
            height: 550
            legend.alignment: Qt.AlignBottom
            antialiasing: true

            StackedBarSeries {
                id: mySeries
                axisX: BarCategoryAxis { categories: ["2007", "2008", "2009", "2010", "2011", "2012" ] }
                BarSet { label: "Bob"; values: [2, 2, 3, 4, 5, 6] }
                BarSet { label: "Susan"; values: [5, 1, 2, 4, 1, 7] }
                BarSet { label: "James"; values: [3, 5, 8, 13, 5, 8] }
            }
        }
    }
}
