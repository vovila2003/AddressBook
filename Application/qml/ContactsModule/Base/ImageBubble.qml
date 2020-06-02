import QtQuick 2.0
import StyleSettings 1.0
import QtGraphicalEffects 1.0

Rectangle {
    id: root
    property alias image: _internalImage

    color: "transparent"
    radius: width / 2
    border.color: Style.primaryColor
    border.width: 2

    RoundImage {
        id: _internalImage
        anchors.fill: root
        anchors.margins: Style.mediumSpacing
        sourceSize.height: height
        sourceSize.width: width
    }

    ColorOverlay {
        anchors.fill: _internalImage
        source: root.image
        color: Style.themeInvertedColor
        antialiasing: true
    }
}
