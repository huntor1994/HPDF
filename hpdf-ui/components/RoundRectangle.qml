import QtQuick
import QtQuick.Shapes
import QtQuick.Controls 2.15
import assets 1.0
import HPDF 1.0
Item {
    property int radius:5
    property string color: "black"
    property bool setGradient:false
    property alias canvas: roundRectangleCanvas
    enum RoundCorner {
        UpLeftCorner=0x01,
        UpRightCorner=0x02,
        DownRightCorner=0x04,
        DownLeftCorner=0x08
    }
    property int roundCornerSelected
    property bool upLeftCorner: (roundCornerSelected&RoundRectangle.RoundCorner.UpLeftCorner)!=0//===RoundRectangle.RoundCorner.UpLeftCorner
    property bool upRightCorner: (roundCornerSelected&RoundRectangle.RoundCorner.UpRightCorner)!=0//===RoundRectangle.RoundCorner.UpRightCorner
    property bool downRightCorner: (roundCornerSelected&RoundRectangle.RoundCorner.DownRightCorner)!=0//===RoundRectangle.RoundCorner.DownRightCorner
    property bool downLeftCorner: (roundCornerSelected&RoundRectangle.RoundCorner.DownLeftCorner)!=0//===RoundRectangle.RoundCorner.DownLeftCorner
    property string gradientColorL: "#787878"
    property string gradientColorM: "#5e5e5e"
    property string gradientColorR: "#424242"
    Canvas {
        //        layer.enabled: true
        //        layer.samples: 8
        id:roundRectangleCanvas
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
        //antialiasing: true
        clip: true
        onPaint: {
            var w=roundRectangleCanvas.width;
            var h=roundRectangleCanvas.height;
            var points = [
                        Qt.point(0,0),
                        Qt.point(w,0),
                        Qt.point(w,h),
                        Qt.point(0,h),
                    ];

            var ctx = getContext("2d");
            var gradient=ctx.createLinearGradient(0,0,w,0)
            //渐变
            if(setGradient===true)
            {
                gradient.addColorStop(0.0, gradientColorL)
                gradient.addColorStop(0.5, gradientColorM)
                gradient.addColorStop(1.0, gradientColorR)
                ctx.fillStyle=gradient;
            }
            else
                ctx.fillStyle = color;

            ctx.strokeStyle="transparent";
            drawRaisedPolygon(points, radius, ctx);
            ctx.fill();
        }
    }
    function drawRaisedPolygon(points, radius, ctx) {
        ctx.beginPath();
        var start=Qt.point((points[0].x+points[3].x)/2,(points[0].y+points[3].y)/2)
        ctx.moveTo(start.x, start.y);
        ctx.arcTo( points[0].x, points[0].y, points[1].x, points[1].y,upLeftCorner?radius:0);
        ctx.arcTo(points[1].x, points[1].y, points[2].x, points[2].y, upRightCorner?radius:0);
        ctx.arcTo(points[2].x, points[2].y, points[3].x, points[3].y, downRightCorner?radius:0)
        ctx.arcTo(points[3].x, points[3].y, start.x, start.y, downLeftCorner?radius:0)
        ctx.closePath();
        ctx.stroke();
    }




}
