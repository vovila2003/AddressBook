import QtQuick 2.0
import QtQuick.Controls 2.4
import ContactsModule.Base 1.0
import QtQuick.Layouts 1.3
import StyleSettings 1.0

BaseDialog {
    id: root
    title: "Информация о контакте"
    GridLayout {
        id: _layout
        anchors.fill: parent
        rows: 3
        columns: 2
        columnSpacing: Style.bigSpacing
        Label {
            text: "Имя:"
        }
        Label {
            id: _nameLabel
        }
        Label {
            text: "Фамилия:"
        }
        Label {
            id: _surnameLabel
        }
        Label {
            text: "Номер телефона:"
        }
        Label {
            id: _phoneLabel
        }
    }

    function show(name, surname, phone) {
        _nameLabel.text = name;
        _surnameLabel.text = surname;
        _phoneLabel.text = phone;
        open();
    }
}
