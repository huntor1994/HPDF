import QtQuick
import QtQuick.Controls
import components 1.0
import assets 1.0
import HPDF 1.0
AbstractButton {
    property RecentlyOpenedFile readResult
    property int imageIndex
    property color hoverColour: "#f0f0f0"
    width:Style.recentlyOpenedFileBtnWidth
    height:Style.recentlyOpenedFileBtnHeight
    signal btnDoubleClicked()
    onReadResultChanged: {
        coverImage.source = ""
        coverImage.source="image://RecentlyOpenedFiles/"+imageIndex
    }
    Rectangle{
        anchors.fill: parent
        id:background
        color: "#f7f7f7"
        radius:5
        MouseArea{
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            hoverEnabled: true
            onEntered:background.state = "hover"
            onExited: background.state = ""
            onDoubleClicked: btnDoubleClicked()
            Rectangle{
                color:"transparent"
                anchors{
                    top: parent.top
                    bottom:parent.bottom
                    left:parent.left
                    right:parent.right
                    topMargin:Style.recentlyOpenedFileBtnUDMargin
                    bottomMargin:Style.recentlyOpenedFileBtnUDMargin
                    leftMargin:Style.recentlyOpenedFileBtnLRMargin
                    rightMargin:Style.recentlyOpenedFileBtnLRMargin
                }


                Rectangle{
                    id:coverBackground
                    color:"white"
                    width:Style.recentlyOpenedFileBtnImageWidth
                    height:Style.recentlyOpenedFileBtnImageHeight
                    anchors{
                        top:parent.top
                        bottom:parent.bottom
                        left:parent.left
                    }
                    Image{
                        id:coverImage
                        cache: false
                        source: "image://RecentlyOpenedFiles/"+imageIndex
                        anchors.fill: parent
                    }
                }

                Rectangle{
                    id:midArea
                    width:parent.width-10-10-Style.recentlyOpenedFileBtnImageWidth-Style.recentlyOpenedFileBtnPopupBtnWidth-Style.recentlyOpenedFileBtnClosePageTextWidth

                    anchors{
                        top:parent.top
                        bottom:parent.bottom
                        left:coverBackground.right
                        leftMargin: 10
                    }
                    color:"transparent"
                    Text {
                        id: pdfTitleText
                        text: textMetrics.elidedText
                        color:"black"
                        anchors{
                            top:parent.top
                            topMargin: parent.height/5

                        }
                    }
                    TextMetrics {
                        id: textMetrics
                        property variant stringList: readResult.ui_filePath.ui_value.split('/')
                        font.family: "Arial"
                        elide: Text.ElideRight
                        elideWidth: midArea.width*0.8
                        text:stringList[stringList.length-1]
                    }

                    Text {
                        id: pdfCloseDateText
                        text:readResult.ui_closeTime.ui_simpleString
                        anchors{
                            top:pdfTitleText.top
                            topMargin: 20
                        }
                    }
                }

                Text{
                    id:closePageText
                    width: Style.recentlyOpenedFileBtnClosePageTextWidth
                    text:{return readResult.ui_closePage.ui_value+"/"+readResult.ui_pageCount.ui_value}
                    color:"#8a8a8a"
                    anchors{
                        left:midArea.right
                        verticalCenter: parent.verticalCenter
                    }
                }
                HPdfButton{
                    id:popupBtn
                    btnText:"..."
                    backgroundColor:"transparent"
                    hoverColour:"#dadada"
                    fontColour:"#8a8a8a"
                    width:Style.recentlyOpenedFileBtnPopupBtnWidth
                    height:Style.recentlyOpenedFileBtnPopupBtnHeight
                    radius:5
                    anchors{
                        left:closePageText.right
                        leftMargin: 10
                        verticalCenter: parent.verticalCenter
                    }

                }

            }
        }
        states: [
            State{
                name:"hover"
                PropertyChanges {
                    target: background
                    color: hoverColour
                }
            }
        ]
    }
}
