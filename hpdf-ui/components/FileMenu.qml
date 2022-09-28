import QtQuick
import components 1.0
import assets 1.0
import QtQuick.Controls
import Qt5Compat.GraphicalEffects
import QtQuick.Dialogs
import QtQuick.Layouts
import QtQuick.Pdf
Item {
    property alias roundCornerSelected: background.roundCornerSelected
    RoundRectangle{
        id:background
        width: Style.fileContextWidth
        height: Style.fileContextHeight
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
            width: Style.fileContextWidth-Style.contextContentMargin*2
            height:Style.fileContextHeight-Style.contextContentMargin*2
            anchors.centerIn: parent.Center
            color:"transparent"
            MenuNormalButton{
                id:newTabBtn
                text:Style.newTabName
                shortcutText:"Ctrl+T"
                anchors.top: parent.top
                 onButtonClicked:{
                     addTab(Style.newTabName)
                 }
            }
            MenuNormalButton{
                id:newWinBtn
                text:"New Window"
                shortcutText:"Ctrl+N"
                anchors{
                    top: newTabBtn.bottom
                    topMargin: 10
                }

            }

            SplitLine{
                id:line1
                width:contextBackground.width
                color:"#ebebeb"
                anchors{
                    top:newWinBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.menuSplitLineMargin
                }
            }

            MenuNormalButton{
                id:openFileBtn
                text:"Open..."
                shortcutText:"Ctrl+O"
                anchors{
                    top: line1.bottom
                    topMargin:Style.menuSplitLineMargin
                }
                onButtonClicked:fileDialog.open()
            }

            MenuNextButton{
                id:recentlyFilesBtn
                text:"RecentlyFiles"
                popupQml:"RecentlyOpenedFilesMenu.qml"
                popupPosX:recentlyFilesBtn.x+recentlyFilesBtn.width+10
                popupPosY:0
                anchors{
                    top: openFileBtn.bottom
                }
            }

            SplitLine{
                id:line2
                width:contextBackground.width
                color:"#ebebeb"
                anchors{
                    top:recentlyFilesBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.menuSplitLineMargin
                }
            }

            MenuNormalButton{
                id:saveBtn
                text:"Save"
                shortcutText:"Ctrl+S"
                anchors{
                    top: line2.bottom
                    topMargin:Style.menuSplitLineMargin
                }
            }

            MenuNormalButton{
                id:saveAsBtn
                text:"Save As..."
                shortcutText:"Ctrl+Shift+S"
                anchors{
                    top: saveBtn.bottom
                }
            }

            SplitLine{
                id:line3
                width:contextBackground.width
                color:"#ebebeb"
                anchors{
                    top:saveAsBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.menuSplitLineMargin
                }
            }

            MenuNormalButton{
                id:closeTabBtn
                text:"Close Tab"
                shortcutText:"Ctrl+W"
                anchors{
                    top: line3.bottom
                    topMargin: Style.menuSplitLineMargin
                }
                onButtonClicked:{
                    closeTab(activePdfIndex)
                }
            }

            MenuNormalButton{
                id:closeWinBtn
                text:"Close Window"
                shortcutText:"Ctrl+Shift+W"
                anchors{
                    top: closeTabBtn.bottom

                }
            }

            SplitLine{
                id:line4
                width:contextBackground.width
                color:"#ebebeb"
                anchors{
                    top:closeWinBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.menuSplitLineMargin
                }
            }

            MenuNormalButton{
                id:showInFolderBtn
                text:"Show in Explorer"
                shortcutText:""
                anchors{
                    top: line4.bottom
                    topMargin: Style.menuSplitLineMargin
                }
                function getFileFolderUrl(filePath){
                    var stringList=filePath.split('/')
                    var folderUrl=""
                    for(var i=0;i<stringList.length-1;i++){
                        folderUrl+=stringList[i]
                        folderUrl+="/"
                    }
                    console.log(folderUrl)
                    return folderUrl
                }
                onButtonClicked:Qt.openUrlExternally(getFileFolderUrl(tabModel.get(activePdfIndex).tabName))
            }

            MenuNormalButton{
                id:propertyBtn
                text:"Property"
                shortcutText:"Ctrl+D"
                anchors{
                    top: showInFolderBtn.bottom
                }
            }

            SplitLine{
                id:line5
                width:contextBackground.width
                color:"#ebebeb"
                anchors{
                    top:propertyBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.menuSplitLineMargin
                }
            }

            MenuNormalButton{
                id:preferenceBtn
                text:"Preference"
                shortcutText:"Ctrl+K"
                anchors{
                    top: line5.bottom
                    topMargin: Style.menuSplitLineMargin
                }
            }

            SplitLine{
                id:line6
                width:contextBackground.width
                color:"#ebebeb"
                anchors{
                    top:preferenceBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.menuSplitLineMargin
                }
            }


            MenuNormalButton{
                id:printBtn
                text:"Print"
                shortcutText:"Ctrl+P"
                anchors{
                    top: line6.bottom
                    topMargin: Style.menuSplitLineMargin
                }
            }

            SplitLine{
                id:line7
                width:contextBackground.width
                color:"#ebebeb"
                anchors{
                    top:printBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.menuSplitLineMargin
                }
            }

            MenuNormalButton{
                id:exitBtn
                text:"Quit"
                shortcutText:"Ctrl+Q"
                anchors{
                    top: line7.bottom
                    topMargin: Style.menuSplitLineMargin
                }
               onButtonClicked:window.close()
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
    FileDialog {
        id: fileDialog
        title: qsTr("Please choose a pdf file")
        nameFilters: ["Pdf Files(*.pdf)"]
        onAccepted:
        {
            fileBtn.closePopup()
            //pdfStack.addPdfArea(fileDialog.currentFile)
            window.addTab(fileDialog.currentFile)
        }
        onRejected: {
            console.log("Canceled")
            fileBtn.closePopup()
        }
    }
}

