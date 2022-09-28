import QtQuick
import QtQuick.Controls
import assets 1.0
Item {
    property alias text: menuText.text
    property bool iconSetOutLine:false
    property string popupQml:""
    property int popupPosX: 0
    property int popupPosY: 0
    function closePopup(){
        popup.close()
    }
    width:parent.width
    height:Style.menuBtnHeight
    Rectangle{
        id:background
        anchors.fill: parent
        color:"transparent"
        radius:5
        Text{
            id:menuText
            width:30
            height:30
            color: "black"
            text:"Set Me"
            anchors{
                left: background.left
                leftMargin: 10
            }
            verticalAlignment: Text.AlignVCenter
        }
        Text{
            id:textIcon
            width:menuText.height
            height:menuText.height
            font{
                family: Style.fontAwesome
                pixelSize: Style.pixelSizeToolBarBtnIcon
                weight:Font.Light
            }
            style: iconSetOutLine?Text.Outline:Text.Normal
            styleColor: "black"
            color: "black"
            text:"\uf0da"
            verticalAlignment: Text.AlignVCenter
            anchors{
                right: background.right

            }

        }

        MouseArea{
            hoverEnabled: true
            anchors.fill: background
            cursorShape: Qt.PointingHandCursor
            onEntered:{
                background.state = "hover"
                 if(popupQml!="")popup.open()
            }
            onExited: {
                background.state = ""

            }
            onClicked: {

            }
        }
        states: [
            State {
                name: "hover"
                PropertyChanges {
                    target: background
                    color:"#eaeaea"
                }
            }
        ]
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
