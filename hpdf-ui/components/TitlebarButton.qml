import QtQuick
import QtQuick.Controls
import assets 1.0
Item {
    property string popupQml:""
    property alias text:btn.btnText
    property alias visibleSelected:btn.visibleSelected
    property alias positionSelected:btn.positionSelected
    property alias  iconCharacter:btn.iconCharacter
    property alias iconSetOutLine:btn.iconSetOutLine
    property alias iconColour:btn.iconColour
    property alias description: btn.description
    property alias hoverColour: btn.hoverColour
    property alias menueItem: loaderCenter.item
    property int popupPosX: 0
    property int popupPosY: btn.height+Style.contextMargin
    signal tabBtnClicked()
    function closePopup(){
        popup.close()
    }
    width:Style.titleBtnWidth
    height:Style.titleBtnHeight
    HPdfButton{
        id:btn
        anchors.fill: parent
        backgroundColor:"transparent"
        hoverColour: "#535353"
        visibleSelected:HPdfButton.ContentVisible.Text
        positionSelected:HPdfToolTip.Position.Bottom
        btnText:"Set Me"
        iconCharacter:""
        fontColour:Style.textColourFont
        onButtonClicked:{
            //loaderCenter.setSource(popupQml);
            tabBtnClicked()
            if(popupQml!="")popup.open()
        }
        Popup {
            id:popup
            closePolicy:Popup.CloseOnPressOutside
            background:Rectangle {
                id:popupBackground
                anchors.fill: parent
                color:Qt.rgba(0,6,0,0)//背景为无色
            }
            Loader {
                id:loaderCenter
                Component.onCompleted: {
                    loaderCenter.setSource(popupQml);
                }
                onLoaded: {
                    popup.x=popupPosX
                    popup.y=popupPosY
                }
            }
        }
    }

}
