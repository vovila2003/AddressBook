import QtQuick 2.0
import ContactsModule.Base 1.0
import Contacts 1.0

BaseListView {
    id: root
    property alias contactModel: _model
    model: ContactsModel {
        id: _model
    }

    delegate: ContactDelegate {
        id: _delegate
        width: root.width
        height: 100
        Connections {
            target: _delegate
            onInfoButtonClicked: _infoDialog.show(_name, _surname, _phone)
            onEditButtonClicked: _editDialog.show(true, _name, _surname, _phone, index)
            onDeleteButtonClicked: _yesNoDialog.show("Удалить контакт:\n" + _name + " " + _surname, index)
        }
    }
    InfoDialog {
        id: _infoDialog
    }
    EditDialog {
        id: _editDialog
        onAccepted: {
            _model.editData(dialog.index, dialog.nameField.text, dialog.surnameField.text, dialog.phoneField.text);
        }
    }
    YesNoDialog {
        id: _yesNoDialog
        onAccepted: {
            _model.deleteData(dialog.index);
        }
    }
}
