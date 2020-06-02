import QtQuick 2.11
import QtQuick.Window 2.11
import StyleSettings 1.0
import ContactsModule.Impl 1.0
import QtQuick.Controls 2.4

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("AddressBook")
//    flags: Qt.FramelessWindowHint
    ContactsView {
        id: _view
        anchors.fill: parent
    }

    Rectangle {
        id: _background
        z: -100
        anchors.fill: parent
        color: Style.backgroundColor
        opacity: Style.emphasisOpacity
    }
    RoundButton {
        id: _addButton
        width: 60
        height: 60
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        text: "+"
        font.pointSize: Style.bigSize
        highlighted: true
        onClicked: {
            _editDialog.show(false, "", "", "");
        }
    }

    EditDialog {
        id: _editDialog
        onAccepted: {
            _view.contactModel.addData(nameField.text, surnameField.text, phoneField.text);
        }
    }
}
