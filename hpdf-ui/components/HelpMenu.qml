import QtQuick
import components 1.0
import assets 1.0
import QtQuick.Controls 2.15
import Qt5Compat.GraphicalEffects
Item {
    property alias roundCornerSelected: background.roundCornerSelected

    RoundRectangle{
        id:background
        width: Style.helpContextWidth
        height: Style.helpontextHeight
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
            height:background.height-Style.contextContentMargin*2
            anchors.centerIn: parent.Center
            color:"transparent"
            MenuNormalButton{
                id:aboutBtn
                text:"About HPDF"
                shortcutText:""
                anchors.top: parent.top
            }

            SplitLine{
                id:line1
                width:contextBackground.width
                color:"#ebebeb"
                anchors{
                    top:aboutBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.menuSplitLineMargin
                }
            }

            MenuNormalButton{
                id:checkUpdateBtn
                text:"Check Update..."
                shortcutText:""
                anchors{
                    top: line1.bottom
                    topMargin: Style.menuSplitLineMargin
                }

            }

            SplitLine{
                id:line2
                width:contextBackground.width
                color:"#ebebeb"
                anchors{
                    top:checkUpdateBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.menuSplitLineMargin
                }
            }



            MenuNormalButton{
                id:homeBtn
                text:"Home"
                shortcutText:""
                anchors{
                    top: line2.bottom
                    topMargin:Style.menuSplitLineMargin
                }
            }

            MenuNormalButton{
                id:onlineHelpBtn
                text:"Online Help"
                shortcutText:""
                anchors{
                    top: homeBtn.bottom
                }
            }

            SplitLine{
                id:line3
                width:contextBackground.width
                color:"#ebebeb"
                anchors{
                    top:onlineHelpBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.menuSplitLineMargin
                }
            }

            MenuNormalButton{
                id:feedbackBtn
                text:"Feedback"
                shortcutText:""
                anchors{
                    top: line3.bottom
                    topMargin: Style.menuSplitLineMargin
                }
            }

            SplitLine{
                id:line4
                width:contextBackground.width
                color:"#ebebeb"
                anchors{
                    top:feedbackBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.menuSplitLineMargin
                }
            }

            MenuNormalButton{
                id:privacyPolicyBtn
                text:"Privacy Policy"
                shortcutText:""
                anchors{
                    top: line4.bottom
                    topMargin: Style.menuSplitLineMargin
                }
            }

            MenuNormalButton{
                id:licenseBtn
                text:"License"
                shortcutText:""
                anchors{
                    top: privacyPolicyBtn.bottom

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

