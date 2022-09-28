import QtQuick
import QtQuick.Layouts 1.15
import components 1.0
import assets 1.0
import QtQuick.Shapes
Item {
    property alias roundCornerSelected: background.roundCornerSelected
    width:Style.toolBarWidth
    //color:"#000000"
    RoundRectangle{
        id:background
        anchors.fill: parent
        radius:Style.radiusToolBar
        color:Style.colourToolBarBackground
    }
}




