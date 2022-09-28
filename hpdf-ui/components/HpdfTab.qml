import QtQuick
import QtQuick.Controls 2.15
import assets 1.0
import QtQuick.Window 2.12

AbstractButton {
    checkable: true
    width:Style.tabWidth
    height:Style.tabHeight
    property alias color: background.color
    property alias setGradient: background.setGradient
    property alias tabText: textMetrics.text
    required property int pdfIndex
    signal closeClicked()

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onClicked:{
            parent.checked=true;
        }
        RoundRectangle{
            id:background
            roundCornerSelected:RoundRectangle.RoundCorner.UpLeftCorner|RoundRectangle.RoundCorner.UpRightCorner
            radius:Style.tabRadius
            anchors.fill: parent
            clip: true
            color:"#2b2b2b";
            setGradient:false
            TitlebarButton{
                id:tabPopupBtn
                width:Style.tabPopupBtnWidth
                height:Style.tabPopupBtnHeight
                popupQml:"TabPopupMenu.qml"
                anchors{
                    left:parent.left
                    leftMargin: 20
                    verticalCenter:parent.verticalCenter
                }
                visibleSelected:HPdfButton.ContentVisible.Icon
                positionSelected:HPdfToolTip.Position.Bottom
                iconCharacter:"\uf0d7"
                iconSetOutLine: false
                iconColour:Style.textColourFont
                hoverColour:Style.tabPopupBtnHoverColor
            }
            TitlebarButton{
                id:closeBtn
                width:Style.tabPopupBtnWidth
                height:Style.tabPopupBtnHeight
                anchors{
                    right:parent.right
                    rightMargin: 20
                    verticalCenter:parent.verticalCenter
                }
                visibleSelected:HPdfButton.ContentVisible.Icon
                positionSelected:HPdfToolTip.Position.Bottom
                iconCharacter:"\uf00d"
                iconSetOutLine: false
                iconColour:Style.textColourFont
                hoverColour:Style.tabPopupBtnHoverColor
                onTabBtnClicked:{
                    closeClicked()
                }
            }
            Text{
                id:text
                anchors.centerIn: parent
                width:100
                height:Style.toolBarBtnIconHeight

                styleColor: Style.colourToolBarBtnFont
                color: Style.textColourFont
                text:textMetrics.elidedText//"SET ME"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            TextMetrics {
                id: textMetrics
                font.family: "Arial"
                elide: Text.ElideMiddle
                elideWidth: text.width
                text: "SET ME"
            }
        }
    }
    onCheckedChanged: {
        if(checked)
        {
            activePdfIndex=pdfIndex
            background.gradientColorL="#787878"
            background.gradientColorM="#5e5e5e"
            background.gradientColorR="#424242"
            background.setGradient=true;
        }else{
            background.gradientColorL="#2b2b2b"
            background.gradientColorM="#2f2f2f"
            background.gradientColorR="#333333"
            background.setGradient=true;
        }
        pdfStack.itemAt(pdfIndex).visible=checked
        background.canvas.requestPaint();

        //console.log(pdfIndex," pdf visible set ",checked )
    }
}
