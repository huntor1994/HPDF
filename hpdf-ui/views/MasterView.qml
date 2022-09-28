import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import QtQuick.Pdf
import QtQuick.Shapes
import components 1.0
import assets 1.0
import QtQuick.Layouts
Window {
    //property Command name: value
    property int activePdfIndex: 0
    property int displayPdfCount: 1
    property bool isMax: false
    readonly property int maxVisibilityValue: 4
    id: window
    visible: true
    width: Style.windowWidth
    height: Style.windowHeight
    title: qsTr("HPDF")
    color: "#00000000"
    flags:Qt.Window|Qt.FramelessWindowHint

    onActivePdfIndexChanged: titleBar.tabGroup.buttons[activePdfIndex].checked=true
    onVisibilityChanged: {
        titleBar.zoomInBtnIconCharacter=window.visibility==maxVisibilityValue?"\uf24d":"\uf0c8";
        windowBorder.radius=window.visibility==maxVisibilityValue?0:Style.windowRadius;
    }
    Component.onCompleted: {
        addTab(Style.newTabName)
    }
    ListModel {
        id: tabModel
    }
    function showTabInRightPos(){
        var i=Math.floor(titleBar.tabAllowWidth/Style.tabWidth)
        i=i==0?1:i
        if(activePdfIndex===0)
        {
            titleBar.tabRows.x=0

        }
        else if(activePdfIndex+1>i)
        {
            titleBar.tabRows.x=-(activePdfIndex-i+1)*Style.tabWidth
        }
        displayPdfCount=i
    }
    function addTab(filePath){
        for (var i = 0; i < tabModel.count; i++) {
            if (tabModel.get(i).tabName === filePath&&filePath!==Style.newTabName) {
                activePdfIndex=i
                showTabInRightPos()
                return
            }
        }
        tabModel.append({"tabName":filePath.toString()})
        activePdfIndex=tabModel.count-1
        showTabInRightPos()
    }
    function closeTab(index){
        console.log("Pdf is closing")
        pdfStackRepeater.itemAt(index).close()
        //        if(tabModel.count!==1)
        //        {
        //            tabModel.remove(index)
        //            displayPdfCount--
        //            var allowTabCount=Math.floor(titleBar.tabAllowWidth/Style.tabWidth)
        //            var currentHideTabCount=(-titleBar.tabRows.x)/Style.tabWidth
        //            if(displayPdfCount<=tabModel.count
        //                    &&displayPdfCount<allowTabCount)
        //            {
        //                var addDisplayTabCount=currentHideTabCount<(allowTabCount-displayPdfCount)?currentHideTabCount:(allowTabCount-displayPdfCount)
        //                titleBar.tabRows.x+=addDisplayTabCount*Style.tabWidth
        //            }

        //        }
        //        else{
        //            editTab(0,Style.newTabName)
        //        }
        tabModel.remove(index)
        displayPdfCount--
        var allowTabCount=Math.floor(titleBar.tabAllowWidth/Style.tabWidth)
        var currentHideTabCount=(-titleBar.tabRows.x)/Style.tabWidth
        if(displayPdfCount<=tabModel.count
                &&displayPdfCount<allowTabCount)
        {
            var addDisplayTabCount=currentHideTabCount<(allowTabCount-displayPdfCount)?currentHideTabCount:(allowTabCount-displayPdfCount)
            titleBar.tabRows.x+=addDisplayTabCount*Style.tabWidth
        }
        if(tabModel.count===0)
            addTab(Style.newTabName)

    }
    function editTab(index,filePath){
        for (var i = 0; i < tabModel.count; i++) {
            if (tabModel.get(i).tabName === filePath) {
                activePdfIndex=i
                showTabInRightPos()
                return
            }
        }
        tabModel.setProperty(index,"tabName",filePath.toString())
    }
    function readRecentlyOpenFiles(){
        console.log("reading opened files from database...")
        masterController.ui_commandController.ui_workAreaViewCommands[1].executed();
    }


    Rectangle{
        id:windowBorder
        width: parent.width
        height: parent.height
        anchors.fill: parent
        color:"#353535"
        radius:Style.windowRadius
        DragHandler {
            id: resizeHandler
            grabPermissions: TapHandler.TakeOverForbidden
            target: null
            onActiveChanged: if (active) {
                                 const p = resizeHandler.centroid.position;
                                 const b = Style.borderMargin + 20; // Increase the corner size slightly
                                 let e = 0;
                                 if (p.x < b) { e |= Qt.LeftEdge }
                                 if (p.x >= width - b) { e |= Qt.RightEdge }
                                 if (p.y < b) { e |= Qt.TopEdge }
                                 if (p.y >= height - b) { e |= Qt.BottomEdge }
                                 window.startSystemResize(e);
                             }
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            cursorShape: {
                const p = Qt.point(mouseX, mouseY);
                const b = Style.borderMargin// + 10; // Increase the corner size slightly
                if (p.x < b && p.y < b) return Qt.SizeFDiagCursor;
                if (p.x >= width - b && p.y >= height - b) return Qt.SizeFDiagCursor;
                if (p.x >= width - b && p.y < b) return Qt.SizeBDiagCursor;
                if (p.x < b && p.y >= height - b) return Qt.SizeBDiagCursor;
                if (p.x < b || p.x >= width - b) return Qt.SizeHorCursor;
                if (p.y < b || p.y >= height - b) return Qt.SizeVerCursor;
            }
            acceptedButtons: Qt.NoButton // don't handle actual event
            TitleBar{
                id:titleBar

                onCloseWin:window.close()

                onMaximized:{
                    if(window.visibility==maxVisibilityValue)  window.showNormal();
                    else window.showMaximized();
                }
                onMinimized:window.showMinimized()
            }

            StackLayout {
                id:pdfStack
                width: parent.width-Style.borderMargin*2
                height: parent.height
                Component{
                    id:myPdfArea

                    HPdfWorkArea{
                        required property int index
                        required property string tabName
                        pdfIndex:index
                        documentFile:tabName
                        Layout.alignment: Qt.AlignHCenter|Qt.AlignBottom
                    }
                }
                Repeater{
                    id:pdfStackRepeater
                    Component.onCompleted: readRecentlyOpenFiles()
                    model:tabModel
                    delegate:myPdfArea
                    //onItemRemoved: function(index,item){item.myDestroy()}

                }

                anchors{
                    top:titleBar.bottom
                    topMargin: 0
                    bottom: parent.bottom
                    bottomMargin: 0
                    horizontalCenter: parent.horizontalCenter
                }
                //onCountChanged:console.log(pdfStack.count)

            }

        }

    }

}


