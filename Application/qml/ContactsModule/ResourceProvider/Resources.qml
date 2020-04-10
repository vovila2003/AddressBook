pragma Singleton
import QtQuick 2.0

Item {
    property alias contacts: _contacts
    QtObject {
        id: _contacts
        readonly property string defaultContactIcon: "qrc:/qml/resources/contact.svg"
        readonly property string infoIcon: "qrc:/qml/resources/info.png"
        readonly property string editIcon: "qrc:/qml/resources/edit.png"
        readonly property string deleteIcon: "qrc:/qml/resources/delete.png"
    }
}
