import QtQuick 2.3
import QtQuick.Controls

TextField {
    id: textField
    height: 40;
    width: 175;

    Constants {
        id: constants;
    }

    // TODO
    // Change text color on Error and Success

    property string borderColor: focus ? constants.emerald : constants.silver;
    property string backgroundColor: disabled ? "#f7f9f9" : "white";
    property int pointSize: 11;
    property bool disabled: false;
    property bool error: false;
    property bool success: false;

    onDisabledChanged: {
        if (disabled) {
            textField.borderColor = "#e1e6e6";
            textField.textColor = "#e1e6e6";
        }

        else {
            textField.textColor = "black";
        }
    }

    onSuccessChanged: {
        if (success) {
            textField.textColor = constants.emerald;
            textField.borderColor = constants.emerald;
        }

        else {
            textField.textColor = "black";
            textField.borderColor = focus ? constants.emerald : constants.silver;
        }
    }

    onErrorChanged: {
        if (error) {
            textField.textColor = constants.alizarin;
            textField.borderColor = constants.alizarin;
        }

        else {
            textField.textColor = "black";
            textField.borderColor = focus ? constants.emerald : constants.silver;
        }

    }


    MouseArea {
        anchors.fill: parent;
        enabled: textField.disabled;
    }

    placeholderText: "Input";

}
