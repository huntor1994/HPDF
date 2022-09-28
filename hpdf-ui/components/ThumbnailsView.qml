import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts
import QtQuick.Pdf
import assets 1.0
Item {
    id:root
    required property PdfDocument document
    Component {
        id: imageBackground
        Image {
            anchors.fill: parent
            source:"qrc:/assets/background.png"
            fillMode: Image.Tile
            cache:true
            asynchronous:true
        }
    }
    TableView {
        id:tableView
        reuseItems: false
        anchors.fill: parent
        model:root.document ?root.document.pageCount : 0
        onHeightChanged: forceLayout()
        onWidthChanged: forceLayout()
        property size firstPagePointSize: document?.status === PdfDocument.Ready ? document.pagePointSize(0) : Qt.size(1, 1)
        property real pageHolderWidth:root.width
        onPageHolderWidthChanged: forceLayout()
        columnWidthProvider:function() { return document ? pageHolderWidth-scrollBar.width : 0 }
        rowHeightProvider: function(){return Style.thumbailsViewCellHeight}
        delegate: Rectangle {
            id:pageHolder
            color: "transparent"
            required property int index
            implicitWidth: image.width
            implicitHeight: image.height
            radius:5
            Rectangle{
                id:paper
                implicitWidth: image.width
                implicitHeight: image.height
                color:"white"
                anchors.centerIn:parent
                property size pagePointSize: tableView.firstPagePointSize //document.pagePointSize(index)
                property real pageScale: image.paintedWidth / pagePointSize.width
                Loader{
                    anchors.fill: parent
                    sourceComponent: imageBackground
                    asynchronous: false
                    visible: image.status!==Image.Ready
                }
                PdfPageImage {
                    id: image
                    document: root.document
                    currentFrame: index
                    asynchronous: true
                    cache:false
                    fillMode: Image.PreserveAspectFit
                    width:Style.thumbailsViewImageWidth
                    height:Style.thumbailsViewImageHeight
                    anchors.top: parent.top
                    anchors.horizontalCenter: parent.horizontalCenter
                }


            }
            Text {
                id: pageNumber
                anchors.bottom: parent.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                text:index+1
            }
            MouseArea{
                id:mouseArea
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                hoverEnabled: true
                onEntered:pageHolder.state = "hover"
                onExited: pageHolder.state = ""
                TapHandler {
                    onTapped: view.goToPage(index)
                }

            }

            states: [
                State{
                    name:"hover"
                    PropertyChanges {
                        target: pageHolder
                        color: Style.colourToolBarBtnClickedBackground
                    }
                }
            ]
        }
        ScrollBar.vertical: ScrollBar {
            id:scrollBar}
    }
}
