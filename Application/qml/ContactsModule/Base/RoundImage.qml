import QtQuick 2.0
import QtGraphicalEffects 1.0


Image {
    id: root
    property bool rounded: true

    layer.enabled: rounded
    layer.effect: OpacityMask {
        maskSource: Item {
            width: root.width
            height: root.height
            Rectangle {
                anchors.centerIn: parent
                width: parent.width
                height: parent.height
                radius: Math.min(height, width) / 2
            }
        }
    }
}
