import QtQuick
import components 1.0
import assets 1.0
import QtQuick.Controls 2.15
import Qt5Compat.GraphicalEffects
import QtQuick.Layouts
Item {
    property alias roundCornerSelected: background.roundCornerSelected

    RoundRectangle{
        id:background
        width: Style.openFilesMenueWidth
        height: contextBackground.height+Style.contextContentMargin*2
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
            width: background.width-Style.contextContentMargin*2
            height:childrenRect.height
            anchors.centerIn: parent.Center
            color:"transparent"
             Column{
                id:openFilesLayout
                spacing:10
                Repeater{
                    id:openFilesMenuRepeater
                    model:masterController.ui_recentlyOpenedFileSearch.ui_readResults

                    delegate:
                        MenuNormalButton{
                        required property int index
                        property variant stringList: masterController.ui_recentlyOpenedFileSearch.ui_readResults[index].ui_filePath.ui_value.split('/')
                        id:btn
                        text:stringList[stringList.length-1]
                        shortcutText:""
                        width:background.width-Style.contextContentMargin*2
                        height:Style.menuBtnHeight
                        onButtonClicked:{
                            window.addTab(Style.newTabName)
                            window.editTab(activePdfIndex,masterController.ui_recentlyOpenedFileSearch.ui_readResults[index].ui_filePath.ui_value)
                            //window.addTab(masterController.ui_recentlyOpenedFileSearch.ui_readResults[index].ui_filePath.ui_value)
                            recentlyFilesBtn.closePopup()
                            fileBtn.closePopup()
                        }
                    }

                }
            }



        }}
    DropShadow{
        anchors.fill: background
        radius: 12
        samples: 16
        color: "#dadada"
        source: background
    }

}

