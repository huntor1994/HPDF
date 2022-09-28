import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Pdf
import QtQuick.Shapes
import QtQuick.Layouts
import QtQuick.Dialogs
import components 1.0
import assets 1.0
import HPDF 1.0
Item {
    property  RecentlyOpenedFile newOpenedFile: masterController.newOpenedFile
    property int pdfIndex
    property string documentFile
    property bool bNewTab: true
    property alias document: view.document
    width: parent.width
    height: parent.height
    onDocumentFileChanged: {
        if(documentFile===Style.newTabName)
        {    bNewTab=true;

        }
        else
        {    bNewTab=false;
            doc.source=documentFile
            //saveToDatabase(documentFile)
        }
    }
    function close(){

        if(documentFile!==Style.newTabName)
        {
            saveToDatabase(documentFile)
        }
    }
    function saveToDatabase(filepath){
        var date = new Date();
        date.setHours(date.getHours(), date.getMinutes() - date.getTimezoneOffset());
        newOpenedFile.ui_filePath.ui_value=documentFile
        newOpenedFile.ui_pageCount.ui_value=doc.pageCount
        newOpenedFile.ui_coverImage.ui_value=documentFile
        newOpenedFile.ui_closeTime.ui_value=date.toISOString()
        newOpenedFile.ui_closePage.ui_value=view.currentPage
        console.log("close command execute,closetime:",date.toISOString())
        masterController.ui_commandController.ui_workAreaViewCommands[0].executed();
    }

    RoundRectangle{
        id:workArea

        width: parent.width
        height: parent.height
        color: "#f6f6f6"
        clip:true
        radius:Style.workArearadius
        roundCornerSelected: RoundRectangle.RoundCorner.UpLeftCorner
                             |RoundRectangle.RoundCorner.UpRightCorner
        //VToolBar
        VToolBar{
            id:leftToolBar
            visible: !bNewTab
            anchors{
                top:workArea.top
                bottom:workArea.bottom
                left:workArea.left
            }
            roundCornerSelected: RoundRectangle.RoundCorner.UpLeftCorner
            HPdfButton{
                id:readerBtn
                width:Style.toolBarBtnWidth
                height:Style.toolBarBtnHeight
                hoverColour: "#3edf9c"
                iconCharacter: "\uf518"
                description: "Reader"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Right
                anchors{
                    top:parent.top
                    horizontalCenter: parent.horizontalCenter
                    topMargin: 16
                }
            }
            SplitLine{
                id:line1
                anchors{
                    top:readerBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.toolBarLineMargin
                }
            }
            HPdfButton{
                id:commentBtn
                width:Style.toolBarBtnWidth
                height:Style.toolBarBtnHeight
                hoverColour: "#ffe34f"
                iconCharacter: "\uf305"
                description: "Comment"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Right
                anchors{
                    top:line1.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.toolBarLineMargin
                }

            }
            HPdfButton{
                id:editBtn
                width:Style.toolBarBtnWidth
                height:Style.toolBarBtnHeight
                hoverColour: "#b5e1fa"
                iconCharacter: "\uf31c"
                description: "Edit"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Right
                anchors{
                    top:commentBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: 16
                }

            }
            SplitLine{
                id:line2
                anchors{
                    top:editBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.toolBarLineMargin
                }
            }

            HPdfButton{
                id:organizeBtn
                width:Style.toolBarBtnWidth
                height:Style.toolBarBtnHeight
                hoverColour: "#d8b9ff"
                iconCharacter: "\uf15c"
                description: "Organize"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Right
                anchors{
                    top:line2.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: Style.toolBarLineMargin
                }

            }
            ButtonGroup{
                id:group
            }
            HPdfButton{
                id:thumbnailBtn
                Component.onCompleted: group.addButton(thumbnailBtn)
                width:Style.toolBarBtnWidth
                height:Style.toolBarBtnHeight
                backgroundColor:"transparent"
                hoverColour: "#dadada"
                clickedColour:"#e9daff"
                iconCharacter:"\uf5fd"
                description: "Thumbnail"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Right
                anchors{
                    bottom:bookMarkBtn.top
                    horizontalCenter: parent.horizontalCenter
                    bottomMargin:16
                }
                onButtonClicked:{
                    thumbnailBtn.checked=true
                    thumbnailBarLayout.currentIndex=0
                }
            }
            HPdfButton{
                id:bookMarkBtn
                Component.onCompleted: {
                    group.addButton(bookMarkBtn)
                    bookMarkBtn.buttonClicked()
                }
                width:Style.toolBarBtnWidth
                height:Style.toolBarBtnHeight
                backgroundColor:"transparent"
                hoverColour: "#e9daff"
                clickedColour:"#e9daff"
                iconCharacter:"\uf02e"
                description: "BookMark"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Right
                anchors{
                    bottom:parent.bottom
                    horizontalCenter: parent.horizontalCenter
                    bottomMargin: 16
                }
                onButtonClicked:
                {
                    bookMarkBtn.checked=true
                    thumbnailBarLayout.currentIndex=1
                }

            }
        }
        //VToolBar
        SplitView{
            id:splitView
            visible: !bNewTab
            anchors{
                top:workArea.top
                bottom:workArea.bottom
                left:leftToolBar.right
                right:rightToolBar.left
            }
            orientation:Qt.Horizontal

            handle: Rectangle {
                id: handleDelegate
                implicitWidth: 0
                containmentMask: Item {
                    x: (handleDelegate.width - width) / 2
                    width:4
                    height: splitView.height
                }
            }

            ThumbnailBar{
                id:thumbnailBar
                implicitWidth:Style.thumbNailBarWidth
                StackLayout{
                    id:thumbnailBarLayout
                    y:Style.contextContentMargin
                    SplitView.minimumWidth: Style.thumbailsViewImageWidth+Style.thumbailsViewPageMargin*2
                    SplitView.fillWidth: true
                    width: parent.width//minimumWidth>parent.width?minimumWidth:parent.width
                    height: parent.height-Style.contextContentMargin
                    clip: true
                    ThumbnailsView{
                        id:thumbnailsView
                        document:view.document
                        //Layout.alignment: Qt.AlignHCenter
                    }
//                    GridView {
//                        id: thumbnailsView

//                        implicitWidth: Style.thumbNailBarWidth//parent.width
//                        implicitHeight: parent.height
//                        model: view.document.pageModel//doc.pageModel
//                        cellWidth: width-Style.thumbailsViewPageMargin /// 2
//                        cellHeight: Style.thumbailsViewCellHeight//cellWidth + 10
//                        delegate: Item {
//                            id:cellItem
//                            required property int index
//                            required property string label
//                            required property size pointSize
//                            width: thumbnailsView.cellWidth-scrollBar.width
//                            height: thumbnailsView.cellHeight

//                            Rectangle{
//                                id:background
//                                anchors.centerIn: parent.Center
//                                anchors.horizontalCenter: parent.horizontalCenter
//                                implicitWidth: parent.width-Style.thumbailsViewPageMargin
//                                implicitHeight: parent.height-Style.thumbailsViewPageMargin
//                                color:"transparent"
//                                radius:5
//                                Rectangle {
//                                    id: paper
//                                    width: image.width
//                                    height: image.height
//                                    x: (parent.width - width) / 2
//                                    y: (parent.height - height-pageNumber.height) / 2
//                                    PdfPageImage {
//                                        id: image
//                                        document: view.document
//                                        currentFrame: index
//                                        asynchronous: true
//                                        fillMode: Image.PreserveAspectFit
//                                        //                                        property bool landscape: pointSize.width > pointSize.heigh
//                                        //                                        width: landscape ? thumbnailsView.cellWidth - 6
//                                        //                                                         : height * pointSize.width / pointSize.height
//                                        //                                        height: 0.85*(landscape ? width * pointSize.height / pointSize.width
//                                        //                                                                : thumbnailsView.cellHeight - 14)
//                                        width:Style.thumbailsViewImageWidth
//                                        height:Style.thumbailsViewImageHeight
//                                        sourceSize.width: width
//                                        sourceSize.height: height
//                                    }
//                                }
//                                Text {
//                                    id: pageNumber
//                                    anchors.bottom: parent.bottom
//                                    anchors.horizontalCenter: parent.horizontalCenter
//                                    text: label
//                                }
//                                MouseArea{
//                                    id:mouseArea
//                                    anchors.fill: parent
//                                    cursorShape: Qt.PointingHandCursor
//                                    hoverEnabled: true
//                                    //propagateComposedEvents: true
//                                    onEntered:background.state = "hover"
//                                    onExited: background.state = ""
//                                    TapHandler {
//                                        onTapped: view.goToPage(index)
//                                    }

//                                }

//                                states: [
//                                    State{
//                                        name:"hover"
//                                        PropertyChanges {
//                                            target: background
//                                            color: Style.colourToolBarBtnClickedBackground
//                                        }
//                                    }
//                                ]
//                            }
//                        }
//                        ScrollBar.vertical: ScrollBar {
//                            id:scrollBar}
//                    }
                    Bookmark{
                        id:bookmark
                        doc:view.document
                        implicitWidth: parent.width
                        implicitHeight: parent.height

                    }
                }//StackLayout
            }
            Rectangle{
                id:pdfViewArea
                HPdfMultiPageView {
                    id: view
                    clip:true
                    anchors.fill:parent
                    document: doc
                }
            }
            PdfDocument{
                id:doc
            }

        }
        //VToolBar
        VToolBar{
            id:rightToolBar
            visible: !bNewTab
            anchors{
                top:workArea.top
                bottom:workArea.bottom
                right:workArea.right
            }
            roundCornerSelected:RoundRectangle.RoundCorner.UpRightCorner
            HPdfButton{
                id:outputBtn
                width:Style.toolBarBtnWidth
                height:Style.toolBarBtnHeight
                backgroundColor:"transparent"
                hoverColour: "#e9daff"
                iconCharacter:"\uf56e"
                description: "Output"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Left
                anchors{
                    top:parent.top
                    horizontalCenter: parent.horizontalCenter
                    topMargin: 16
                }

            }
            HPdfButton{
                id:saveBtn
                width:Style.toolBarBtnWidth
                height:Style.toolBarBtnHeight
                backgroundColor:"transparent"
                hoverColour: "#e9daff"
                iconCharacter:"\uf1c1"
                description: "Save"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Left
                anchors{
                    top:outputBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: 16
                }

            }
            HPdfButton{
                id:protectBtn
                width:Style.toolBarBtnWidth
                height:Style.toolBarBtnHeight
                backgroundColor:"transparent"
                hoverColour: "#e9daff"
                iconCharacter:"\uf023"
                description: "Protect"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Left
                anchors{
                    top:saveBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: 16
                }

            }
            HPdfButton{
                id:emailBtn
                width:Style.toolBarBtnWidth
                height:Style.toolBarBtnHeight
                backgroundColor:"transparent"
                hoverColour: "#e9daff"
                iconCharacter:"\uf0e0"
                description: "Email"
                visibleSelected:HPdfButton.ContentVisible.Icon|HPdfButton.ContentVisible.Tooltip
                positionSelected:HPdfToolTip.Position.Left
                anchors{
                    top:protectBtn.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: 16
                }

            }

        }
        //VToolBar

        //NewTabWorkArea
        Item{
            id:newTabWorkArea
            visible: bNewTab
            anchors.fill: parent
            RoundRectangle{
                id:recentlyFilesArea
                width: Style.recentlyFilesAreaWidth
                height: Style.recentlyFilesAreaHeight
                color: "white"
                clip:true
                radius:Style.workArearadius
                roundCornerSelected: RoundRectangle.RoundCorner.UpLeftCorner
                                     |RoundRectangle.RoundCorner.UpRightCorner

                anchors{
                    bottom: parent.bottom
                    horizontalCenter: parent.horizontalCenter
                }

                ListView{
                    id:recentlyOpenedFilesListView
                    width:parent.width-Style.recentlyOpenedFileBtnAreaLRMargin*2
                    height:parent.height-Style.recentlyOpenedFileBtnAreaUDMargin
                    clip: true
                    spacing:10
                    anchors{
                        bottom:parent.bottom
                        horizontalCenter: parent.horizontalCenter
                    }
                    //                    Rectangle{
                    //                        color:"blue"
                    //                        anchors.fill: parent
                    //                    }

                    model:masterController.ui_recentlyOpenedFileSearch.ui_readResults

                    delegate:
                        HPdfRecentlyOpenedFilesButton{
                        required property int index
                        readResult:masterController.ui_recentlyOpenedFileSearch.ui_readResults[index]
                        imageIndex:index
                        width:parent.width//-Style.recentlyOpenedFileBtnAreaScrollBarWidth
                        anchors{
                            left:parent.left
                        }
                        onBtnDoubleClicked:window.editTab(pdfIndex,readResult.ui_filePath.ui_value)
                            //window.editTab(pdfIndex,masterController.ui_recentlyOpenedFileSearch.ui_readResults[index].ui_filePath.ui_value)

                    }
                    ScrollBar.vertical: ScrollBar {

                    }
                }//listview
            }
            HPdfButton{
                id:openFileBtn
                width: Style.openFileBtnWidth
                height:Style.openFileBtnHeight
                backgroundColor: Style.openFileBtnColor
                hoverColour:Style.openFileBtnHoverColor
                btnText:"Open File"
                anchors{
                    bottom: recentlyFilesArea.top
                    bottomMargin: 10
                    horizontalCenter: parent.horizontalCenter
                }
                onButtonClicked:{
                    fileDialog.open()
                }
            }
            Rectangle{
                id:welcomeImage
                color:"transparent"
                width:Style.welcomeImageWidth
                height:Style.welcomeImageHeight
                Image {
                    source: "qrc:/assets/welcomeImage.png"
                    anchors.fill: parent
                    fillMode:Image.PreserveAspectFit
                }
                anchors{
                    bottom: openFileBtn.top
                    bottomMargin: 10
                    horizontalCenter: parent.horizontalCenter
                }
            }

            FileDialog {
                id: fileDialog
                title: qsTr("Please choose a pdf file")
                nameFilters: ["Pdf Files(*.pdf)"]
                onAccepted:window.editTab(pdfIndex,fileDialog.currentFile)
            }

        }

    }
}
