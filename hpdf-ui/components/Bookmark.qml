import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts
import QtQuick.Pdf
import assets 1.0
Item {
    required property PdfDocument doc

    TreeView {
        id: bookmarksTree
        x:Style.contextContentMargin
        y:Style.contextContentMargin
        implicitHeight: parent.height-Style.contextContentMargin*2
        implicitWidth: parent.width-Style.contextContentMargin*2
        columnWidthProvider: function() { return bookmarksTree.width }
        onWidthChanged: forceLayout()
        delegate:Item {
            id: treeDelegate
            implicitWidth: parent.width//padding + label.x + label.implicitWidth + padding
            implicitHeight: label.implicitHeight * 1.5
            readonly property real indent: 20
            readonly property real padding: 5

            // Assigned to by TreeView:
            required property TreeView treeView
            required property bool isTreeNode
            required property bool expanded
            required property int hasChildren
            required property int depth

            required property int page
            required property point location
            required property real zoom
            Rectangle{
                id:background
                anchors.fill: parent
                color:"transparent"
                radius: Style.radiusToolBarBtn
                Text {
                    id: indicator
                    visible: treeDelegate.isTreeNode && treeDelegate.hasChildren
                    x: padding + (treeDelegate.depth * treeDelegate.indent)
                    anchors.verticalCenter: label.verticalCenter
                    font{
                        family: Style.fontAwesome
                        pixelSize: 10
                        weight:Font.Light
                    }
                    style: Text.Normal
                    //styleColor: iconOutLineColour
                    text: "\uf054"
                    rotation: treeDelegate.expanded ? 90 : 0
                }

                Text {
                    id: label
                    x: padding + (treeDelegate.isTreeNode ? (treeDelegate.depth + 1) * treeDelegate.indent : 0)
                    width: treeDelegate.width - treeDelegate.padding - x
                    clip: true
                    text: model.display
                    anchors.verticalCenter: parent.verticalCenter
                }

                MouseArea{
                    id:mouseArea
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    hoverEnabled: true
                    //propagateComposedEvents: true
                    onEntered:background.state = "hover"
                    onExited: background.state = ""
                    TapHandler {
                        onTapped: treeView.toggleExpanded(row)
                    }
                    onClicked: {
                        //console.log("Go to:",page, location, zoom)
                        view.goToLocation(page, location, zoom)
                    }
                }

                states: [
                    State{
                        name:"hover"
                        PropertyChanges {
                            target: background
                            color: Style.colourToolBarBtnClickedBackground
                        }
                    }
                ]
            }
        }
        model: PdfBookmarkModel {document:doc}
        ScrollBar.vertical: ScrollBar { }
    }

}
