import QtQuick
import QtQuick.Shapes
Item {
    property alias color: path.strokeColor
    width: 8
    height: 0.8
    Shape{
        id:line
        anchors.fill: parent
        ShapePath {
            id:path
            strokeWidth:height
            strokeColor: "black"
            startX:0
            startY:0
            PathLine {
                x:line.width
                y:0
            }
        }
    }
}
