import QtQuick
import assets 1.0
Item {
    property alias text: textMetrics.text//menuText.text
    property alias shortcutText: menuShortcut.text
    signal buttonClicked();
    width:parent.width
    height:Style.menuBtnHeight
    Rectangle{
        id:background
        anchors.fill: parent
        color:"transparent"
        radius:5
        Text{
            id:menuText
            width:parent.width-menuShortcut.contentWidth
            height:30
            color: "black"
            text:textMetrics.elidedText//"Set Me"
            anchors{
                left: background.left
                leftMargin: 10
            }
            verticalAlignment: Text.AlignVCenter
        }
        Text{
            id:menuShortcut
            //width:menuShortcut.contentWidth
            height:30
            color: "black"
            text:"Set Me"
            anchors{
                right: background.right
                rightMargin: Style.menuShortcutRightMargin
            }
            verticalAlignment: Text.AlignVCenter
        }
        TextMetrics {
            id: textMetrics
            font.family: "Arial"
            elide: Text.ElideMiddle
            elideWidth:parent.width-40
            text: "SET ME"
        }
        MouseArea{
            hoverEnabled: true
            anchors.fill: background
            cursorShape: Qt.PointingHandCursor
            propagateComposedEvents:false
            onEntered:{
                background.state = "hover"
            }
            onExited: {
                background.state = ""
            }
            onClicked: {
                buttonClicked()
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

    }
}
