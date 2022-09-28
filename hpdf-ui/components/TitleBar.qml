import QtQuick
import QtQuick.Controls
import assets 1.0
import QtQuick.Window
import QtQuick.Layouts
import QtQml.Models
Item {
    width: parent.width-2*Style.borderMargin
    height: Style.titleBarHeight
    x:Style.borderMargin
    y:2
    signal maximized()
    signal minimized()
    signal closeWin()
    property alias tabAllowWidth:tabArea.allowWidth
    property alias tabGroup: group
    property alias tabRows: rows
    property alias zoomInBtnIconCharacter:zoomInBtn.iconCharacter
    readonly property int buttonBottomMargin:(parent.height-Style.borderMargin)*0.5+Style.borderMargin
    Item {
        anchors.fill: parent
//        Rectangle{
//            anchors.fill: parent
//            color:Qt.rgba(0,6,0,0.5)
//        }
        MouseArea {
            anchors.fill: parent
            TapHandler {
                onTapped: if (tapCount === 2){ zoomInBtn.buttonClicked();}
                gesturePolicy: TapHandler.DragThreshold
            }
            DragHandler {
                grabPermissions: TapHandler.CanTakeOverFromAnything
                onActiveChanged: if (active) { window.startSystemMove(); }
            }
            Image{
                id:ico
                width: 42
                height: 23
                fillMode: Image.PreserveAspectFit
                anchors{
                    left:parent.left
                    verticalCenter: parent.verticalCenter

                }
                source: "qrc:/assets/HPDF.svg"
                mipmap: true
            }
            TitlebarButton{
                id:fileBtn
                text:"FILE"
                width:Style.titleBtnWidth
                height:Style.titleBtnHeight
                popupQml:"FileMenu.qml"
                anchors{
                    left:ico.right
                    leftMargin:30
                    verticalCenter: parent.verticalCenter
                }
            }

            TitlebarButton{
                id:helpBtn
                text:"HELP"
                width:Style.titleBtnWidth
                height:Style.titleBtnHeight
                popupQml:"HelpMenu.qml"
                anchors{
                    left:fileBtn.right
                    leftMargin:10
                    verticalCenter: parent.verticalCenter
                }
            }
            HPdfButton{
                id:closeBtn
                width:Style.zoomBtnWidth
                height:Style.zoomBtnHeight
                backgroundColor:"transparent"
                hoverColour: "#535353"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Bottom
                description: "Close"
                iconColour:Style.textColourFont
                iconCharacter:"\uf00d"
                iconSetOutLine: false
                anchors{
                    right:parent.right
                    rightMargin:10
                    verticalCenter: parent.verticalCenter
                }
                onButtonClicked: closeWin()
            }
            HPdfButton{
                id:zoomInBtn
                width:Style.zoomBtnWidth
                height:Style.zoomBtnHeight
                backgroundColor:"transparent"
                hoverColour: "#535353"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Bottom
                description: "Zoom In"
                iconOutLineColour:Style.textColourFont
                iconCharacter:"\uf0c8"
                anchors{
                    right:closeBtn.left
                    rightMargin:10

                    verticalCenter: parent.verticalCenter
                }
                onButtonClicked: maximized()
            }
            HPdfButton{
                id:zoomOutBtn
                width:Style.zoomBtnWidth
                height:Style.zoomBtnHeight
                backgroundColor:"transparent"
                hoverColour: "#535353"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Bottom
                description: "Zoom Out"
                iconColour:Style.textColourFont
                iconCharacter:"\uf068"
                iconSetOutLine: false
                anchors{
                    right:zoomInBtn.left
                    rightMargin:10
                    verticalCenter: parent.verticalCenter
                }
                onButtonClicked: minimized()
            }

            TitlebarButton{
                id:openNewTabBtn
                width:Style.zoomBtnWidth
                height:Style.zoomBtnHeight
                popupQml:"OpenFilesMenu.qml"
                popupPosX:-Style.tabWidth
                anchors{
                    right:zoomOutBtn.left
                    rightMargin:10
                    verticalCenter: parent.verticalCenter
                }
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Bottom
                iconCharacter:"\uf078"
                iconSetOutLine: false
                iconColour:Style.textColourFont
                description: "Open New Tab"
            }

            Rectangle{
                id:tabArea
                property int allowWidth:openNewTabBtn.x-helpBtn.x-helpBtn.width-newTabBtn.width-30
                property int allowTabCount:Math.floor(allowWidth/Style.tabWidth)
                color:"transparent"
                width:(group.buttons.length<allowTabCount?group.buttons.length:allowTabCount)*Style.tabWidth//childrenRect.width<allowWidth?childrenRect.width:allowWidth
                onAllowTabCountChanged: {
                    var currentHideTabCount=(-titleBar.tabRows.x)/Style.tabWidth
                    if(displayPdfCount<=group.buttons.length
                            &&displayPdfCount<allowTabCount)
                    {
                        //from narrow to broad
                        var addDisplayTabCount=currentHideTabCount<(allowTabCount-displayPdfCount)?currentHideTabCount:(allowTabCount-displayPdfCount)
                        titleBar.tabRows.x+=addDisplayTabCount*Style.tabWidth
                    }
                    showTabInRightPos()
                }
                clip:true
                height:parent.height
                anchors{
                    bottom:parent.bottom
                    left:helpBtn.right
                    leftMargin:10
                }
                ButtonGroup{
                    id:group
                    buttons:rows.children
                }
                Row{
                    id:rows
                    spacing: 0

                    Component {
                        id: tabDelegate
                        HpdfTab{
                            required property int index
                            required property string tabName
                            property variant stringList: tabName.split('/')
                            id:tab
                            tabText:stringList[stringList.length-1]
                            pdfIndex:index
                            Component.onCompleted: checked=true
                            onCloseClicked:closeTab(pdfIndex)
                            y:tabArea.height-tab.height
                        }
                    }
                    Repeater{
                        id:repeater
                        model:tabModel
                        delegate:tabDelegate
                    }
                }
            }

            HPdfButton{
                id:newTabBtn
                width:Style.zoomBtnWidth
                height:Style.zoomBtnHeight
                backgroundColor:"transparent"
                hoverColour: "#535353"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Bottom
                description: Style.newTabName
                iconColour:Style.textColourFont
                iconCharacter:"\u002b"
                iconSetOutLine: false
                anchors{
                    left:tabArea.right
                    leftMargin:10
                    verticalCenter: parent.verticalCenter
                    verticalCenterOffset: (Style.titleBarHeight-Style.tabHeight)*0.5
                    // bottomMargin: Style.titleBarHeight*0.5
                }
                MouseArea{
                    anchors.fill: newTabBtn
                    onClicked:{
                        window.addTab(Style.newTabName)
                    }
                }
            }
        }
    }
}


