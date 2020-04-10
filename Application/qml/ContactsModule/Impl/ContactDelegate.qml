import QtQuick 2.0
import ContactsModule.Base 1.0
import StyleSettings 1.0
import ContactsModule.ResourceProvider 1.0
import QtGraphicalEffects 1.0

BaseListDelegate {
    id: root
    signal infoButtonClicked(var _name, var _surname, var _phone)
    signal editButtonClicked(var edit, var _name, var _surname, var _phone)
    signal deleteButtonClicked(var _name, var _surname)

    ImageBubble {
        id: _contactBubble
        anchors.left: root.left
        anchors.leftMargin: Style.defaultOffset
        anchors.verticalCenter: root.verticalCenter
        width: root.height - 15
        height: root.height - 15
        image.source: Resources.contacts.defaultContactIcon
    }

    Column {
        anchors.verticalCenter: root.verticalCenter
        anchors.left: _contactBubble.right
        anchors.leftMargin: Style.defaultOffset
        Row {
            spacing: Style.smallSpacing
            BaseText {
                text: name
            }
            BaseText {
                text: surname
            }
        }
        BaseText {
            text: phoneNumber
            color: Style.primaryColor
        }
    }
    Row {
        id: _row
        anchors.right: root.right
        anchors.verticalCenter: root.verticalCenter
        anchors.topMargin: Style.defaultOffset
        anchors.rightMargin: 90
        spacing: Style.smallSpacing
        BaseImage {
            id: _infotButton
            source: Resources.contacts.infoIcon
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    root.infoButtonClicked(name, surname, phoneNumber)
                }
            }
        }
        BaseImage {
            id: _editButton
            source: Resources.contacts.editIcon
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    root.editButtonClicked(true, name, surname, phoneNumber)
                }
            }
        }
        BaseImage {
            id: _deleteButton
            source: Resources.contacts.deleteIcon
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    root.deleteButtonClicked(name, surname)
                }
            }
        }
    }
}
