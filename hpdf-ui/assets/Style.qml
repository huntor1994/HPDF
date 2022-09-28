pragma Singleton
import QtQuick
import QtQml.Models
Item {

    FontLoader{
        id:fontAwesomeLoader
        source: "qrc:/assets/fontawesome.ttf"
    }

    property alias fontAwesome: fontAwesomeLoader.name
    readonly property color colourBackground: "#efefef"

    readonly property int windowRadius: 7
    readonly property int windowWidth: 1090
    readonly property int windowHeight: 787
    readonly property int workArearadius: 16
    readonly property int borderMargin: 15
    readonly property int workAreaMargin: 15
    readonly property int toolBarWidth: 60
    readonly property int radiusToolBar:workArearadius
    readonly property int thumbNailBarWidth: 205

    readonly property int toolBarBtnWidth: 27
    readonly property int toolBarBtnHeight: 27
    readonly property int toolBarLineMargin: 12
    readonly property color colourToolBarBackground: "#ececec"

    readonly property int toolBarBtnIconWidth: 10
    readonly property int toolBarBtnIconHeight: 10
    readonly property color colourToolBarBtnBackground: "#dadada"
    readonly property int pixelSizeToolBarBtnIcon:15
    readonly property color colourToolBarBtnFont: "#000000"
    readonly property int radiusToolBarBtn:5
    readonly property color colourToolBarBtnClickedBackground: "#e9daff"

    readonly property int tooltipWidth: 60
    readonly property int tooltipHeight: 30
    readonly property color colourTooltipBackground: "#353535"
    readonly property int widthTooltipDescription: 50
    readonly property int heightTooltipDescription: 20
    readonly property color colourTooltipFont: "#ffffff"
    readonly property int pixelSizeTooltipText: 13
    readonly property int tooltipRadius:5
    readonly property int tooltipRaisedRadius:2
    readonly property int tooltipRaisedLength:7
    readonly property int tooltipRaisedBaseLength:7
    readonly property color colourTooltipTriangle: colourTooltipBackground
    readonly property int tooltipMargin:10

    readonly property int titleBarHeight: titleBtnHeight+Style.borderMargin

    readonly property int titleBtnWidth: 60
    readonly property int titleBtnHeight: 25
    readonly property color textColourFont: "white"

    readonly property int zoomBtnWidth: titleBtnHeight
    readonly property int zoomBtnHeight:titleBtnHeight

    readonly property int contextRadius: 5
    readonly property int contextMargin: 5
    readonly property int contextContentMargin: 8

    readonly property int fileContextWidth: 250
    readonly property int fileContextHeight: 490
    readonly property int helpContextWidth: 150
    readonly property int helpontextHeight:270
    readonly property int openFilesMenueWidth: 250

    readonly property int tabPopupWidth: 200
    readonly property int tabPopupHeight:130

    readonly property int menuBtnHeight:30
    readonly property int menuSplitLineMargin:5
    readonly property int menuShortcutRightMargin:60

    readonly property int tabRadius: 6
    readonly property int tabWidth: 220
    readonly property int tabHeight: 33
    readonly property int tabMargin: 20
    readonly property color tabBackgroundColour: "white"
    readonly property string newTabName: "New Tab"

    readonly property int tabPopupBtnWidth: 15
    readonly property int tabPopupBtnHeight: 15
    readonly property color tabPopupBtnHoverColor: "#595959"

    readonly property int thumbailsViewPageMargin: 10
    readonly property int thumbailsViewImageWidth: 130
    readonly property int thumbailsViewImageHeight: 160
    readonly property int thumbailsViewCellHeight: 50+thumbailsViewImageHeight

    readonly property int welcomeImageWidth: 300
    readonly property int welcomeImageHeight: 100

    readonly property int recentlyFilesAreaWidth: 900
    readonly property int recentlyFilesAreaHeight: 550

    readonly property int openFileBtnWidth: 150
    readonly property int openFileBtnHeight: 22
    readonly property color openFileBtnColor: "#c08fff"
    readonly property color openFileBtnHoverColor: "#a37ad9"

    readonly property int recentlyOpenedFileBtnWidth: 150
    readonly property int recentlyOpenedFileBtnHeight:70

    readonly property int recentlyOpenedFileBtnAreaUDMargin: 50
    readonly property int recentlyOpenedFileBtnAreaLRMargin: 40
    readonly property int recentlyOpenedFileBtnAreaScrollBarWidth: 10

    readonly property int recentlyOpenedFileBtnUDMargin: 8
    readonly property int recentlyOpenedFileBtnLRMargin: 12

    readonly property int recentlyOpenedFileBtnImageWidth: 40
    readonly property int recentlyOpenedFileBtnImageHeight:70

    readonly property int recentlyOpenedFileBtnPopupBtnWidth:20
    readonly property int recentlyOpenedFileBtnPopupBtnHeight:20

    readonly property int recentlyOpenedFileBtnClosePageTextWidth:50

}


