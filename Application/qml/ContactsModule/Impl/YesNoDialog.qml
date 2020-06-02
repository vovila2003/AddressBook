import QtQuick 2.0
import ContactsModule.Base 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import StyleSettings 1.0

BaseDialog {
    id: root
    readonly property alias dialog: root
    property int index: -1
    standardButtons: Dialog.Yes | Dialog.No

    Label {
        id: _label
    }

    function show(_text, _index) {
        _label.text = _text;
        index = _index;
        open();
    }
}
