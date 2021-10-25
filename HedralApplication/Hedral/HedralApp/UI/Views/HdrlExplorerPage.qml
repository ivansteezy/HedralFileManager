import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

import "../Components"

Page {
    id: explorerPage
    height: 600
    width: 820
    background: Rectangle{
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


    ColumnLayout{
        width: parent.width
        height: 600
        spacing: 5
    }


}
