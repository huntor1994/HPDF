import QtQuick
import QtQuick.Controls 2.2
import QtQuick.Window 2.12
import assets 1.0

AbstractButton{
    enum ContentVisible {
        Text=0x01,
        Tooltip=0x02,
        Icon=0x04
    }
    property int visibleSelected:HPdfButton.ContentVisible.Text
    property bool textVisible: (visibleSelected&HPdfButton.ContentVisible.Text)!=0
    property bool tooltipVisible: (visibleSelected&HPdfButton.ContentVisible.Tooltip)!=0
    property bool iconVisible: (visibleSelected&HPdfButton.ContentVisible.Icon)!=0
    property bool iconSetOutLine:true
    property alias iconCharacter:textIcon.text
    property alias radius:background.radius
    property alias backgroundColor:background.color
    property color hoverColour: Style.colourToolBarBtnBackground
    property color clickedColour: hoverColour
    property color fontColour: Style.textColourFont
    property color iconOutLineColour: Style.colourToolBarBtnFont
    property color iconColour:"transparent"
    property string description
    property alias btnText:text.text
    property int positionSelected:HPdfToolTip.Position.Right
    signal buttonClicked()
    onCheckedChanged: {
        if(checked)
            background.state = "clicked"
        else background.state = ""
    }
    Rectangle{
        id:background
        anchors.fill: parent
        color:Style.colourToolBarBtnBackground
        radius: Style.radiusToolBarBtn
        Text{
            id:textIcon
            visible: iconVisible
            anchors.centerIn: parent
            width:Style.toolBarBtnIconWidth
            height:Style.toolBarBtnIconHeight
            font{
                family: Style.fontAwesome
                pixelSize: Style.pixelSizeToolBarBtnIcon
                weight:Font.Light
            }
            style: iconSetOutLine?Text.Outline:Text.Normal
            styleColor: iconOutLineColour
            color: iconColour
            text:"\uf11a"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text{
            id:text
            visible: textVisible
            anchors.centerIn: parent
            width:Style.toolBarBtnIconWidth
            height:Style.toolBarBtnIconHeight

            styleColor: Style.colourToolBarBtnFont
            color: fontColour
            text:"SET ME"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea{
            id:mouseArea
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            hoverEnabled: true
            //propagateComposedEvents: true
            onEntered:{
                background.state = "hover"
                popupCenter.open();
            }
            onExited: {
                if(!checked)
                    background.state = ""
                popupCenter.close();

            }
            onClicked: {
                background.state = "clicked"
                buttonClicked();
            }

        }

        states: [
            State{
                name:"hover"
                PropertyChanges {
                    target: background
                    color: hoverColour
                }
            },
            State{
                name:"clicked"
                PropertyChanges {
                    target: background
                    color: clickedColour
                }
            }
        ]
    }

    property bool topPosition: (positionSelected&HPdfToolTip.Position.Top)!=0
    property bool bottomPosition: (positionSelected&HPdfToolTip.Position.Bottom)!=0
    property bool leftPosition: (positionSelected&HPdfToolTip.Position.Left)!=0
    property bool rightPosition: (positionSelected&HPdfToolTip.Position.Right)!=0
    Popup {
        id:popupCenter
        modal:false//模态， 为 true后弹出窗口会叠加一个独特的背景调光效果
        focus:false//焦点,  当弹出窗口实际接收到焦点时，activeFocus将为真
        padding:0

        closePolicy:Popup.NoAutoClose //| Popup.CloseOnPressOutside
        property var raiseItem:null
        background:Rectangle {
            id:popupBackground
            color:Qt.rgba(0,6,0,0)//背景为无色
        }

        Loader {
            id:loaderCenter
            Component.onCompleted: {
                if(tooltipVisible)
                    loaderCenter.setSource("HPdfToolTip.qml"
                                           ,{ "description": description
                                               ,"positionSelected": positionSelected}
                                           );

            }
            onLoaded: {
                if(tooltipVisible)
                {
                    switch(positionSelected)
                    {
                    case HPdfToolTip.Position.Top:
                        popupCenter.x =(background.width-loaderCenter.item.width)*0.5
                        popupCenter.y =-loaderCenter.item.height-Style.tooltipMargin
                        break;
                    case HPdfToolTip.Position.Bottom:
                        popupCenter.x =(background.width-loaderCenter.item.width)*0.5
                        popupCenter.y =background.height+Style.tooltipMargin
                        break;
                    case HPdfToolTip.Position.Left:
                        popupCenter.x =-loaderCenter.item.width-Style.tooltipMargin
                        popupCenter.y =0
                        break;
                    case HPdfToolTip.Position.Right:
                        popupCenter.x =background.width+Style.tooltipMargin
                        popupCenter.y =0
                        break;
                    }
                }
            }
        }
    }

}



