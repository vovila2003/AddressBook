import QtQuick 2.0
import ContactsModule.Base 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import StyleSettings 1.0

BaseDialog {
    id: root
    readonly property alias dialog: root
    property int index: -1
    property alias nameField: _nameField
    property alias surnameField: _surnameField
    property alias phoneField: _phoneField

    standardButtons: Dialog.Ok | Dialog.Cancel

    GridLayout {
        id: _layout
        anchors.fill: parent
        rows: 3
        columns: 2
        columnSpacing: Style.bigSpacing
        Label {
            text: "Имя:"
        }
        TextField {
            id: _nameField
        }
        Label {
            text: "Фамилия:"
        }
        TextField {
            id: _surnameField
        }
        Label {
            text: "Номер телефона:"
        }
        TextField {
            id: _phoneField
        }
    }

    function show(_edit, _name, _surname, _phone, _index) {
        if (_edit){
            root.title = "Редактирование контакта";
            _nameField.text = String(_name);
            _surnameField.text = String(_surname);
            _phoneField.text = String(_phone);
            index = _index;
        } else {
            root.title = "Создание контакта";
            _nameField.clear();
            _surnameField.clear();
            _phoneField.clear();
            index = -1;
        }
        open();
    }
}
