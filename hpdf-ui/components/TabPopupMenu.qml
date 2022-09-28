import QtQuick
import components 1.0
import assets 1.0
import QtQuick.Controls 2.15
import Qt5Compat.GraphicalEffects
Item {
    property alias roundCornerSelected: background.roundCornerSelected

    RoundRectangle{
        id:background
        width: Style.tabPopupWidth
        height: Style.tabPopupHeight
        color: "#f7f7f7"
        radius:Style.contextRadius
        roundCornerSelected: RoundRectangle.RoundCorner.UpLeftCorner
                             |RoundRectangle.RoundCorner.UpRightCorner
                             |RoundRectangle.RoundCorner.DownLeftCorner
                             |RoundRectangle.RoundCorner.DownRightCorner
        Rectangle{
            id:contextBackground
            x:Style.contextContentMargin
            y:Style.contextContentMargin
            width: parent.width-Style.contextContentMargin*2
            height:parent.height-Style.contextContentMargin*2
            anchors.centerIn: parent.Center
            color:"transparent"
            MenuNormalButton{
                id:newTabBtn
                text:"Show In Folder"
                shortcutText:""
                anchors.top: parent.top
            }
            MenuNormalButton{
                id:newWinBtn
                text:"Move to New Window"
                shortcutText:""
                anchors{
                    top: newTabBtn.bottom
                    topMargin: 10
                }

            }
            MenuNormalButton{
                id:lockWinBtn
                text:"Lock Window"
                shortcutText:""
                anchors{
                    top: newWinBtn.bottom
                    topMargin: 10
                }

            }
        }
    }
    DropShadow{
        anchors.fill: background
        radius: 12
        samples: 16
        color: "#dadada"
        source: background
    }

}

