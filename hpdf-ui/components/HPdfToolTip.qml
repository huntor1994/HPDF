import QtQuick
import QtQuick.Shapes
import QtQuick.Controls 2.2
import assets 1.0
Item {
    enum Position {
        Top=0x01,
        Bottom=0x02,
        Left=0x04,
        Right=0x08
    }
    property int positionSelected:HPdfToolTip.Position.Right
    property bool topPosition: (positionSelected&HPdfToolTip.Position.Top)!=0
    property bool bottomPosition: (positionSelected&HPdfToolTip.Position.Bottom)!=0
    property bool leftPosition: (positionSelected&HPdfToolTip.Position.Left)!=0
    property bool rightPosition: (positionSelected&HPdfToolTip.Position.Right)!=0
    property alias description: textDescription.text
    width:{Math.floor(textDescription.contentWidth)+30}
    height:Style.tooltipHeight
    function drawRaisedPolygon(points, radius, ctx) {
        ctx.beginPath();
        ctx.moveTo(points[0].x, points[0].y);
        ctx.arcTo(points[1].x, points[1].y, points[2].x, points[2].y, radius);
        ctx.lineTo(points[2].x, points[2].y)
        ctx.closePath();
        ctx.stroke();
    }

    //w:canvas.width
    //h:canvas.height
    //b:triangle.base
    //l:triangle.legth
    //ctx:getContext
    function drawToolTip(w,h,b,l,r1,r2,ctx){
        var points;
        switch(positionSelected)
        {
        case HPdfToolTip.Position.Top:
            points= [
                        Qt.point(0,(h-l)*0.5),
                        Qt.point(0,0),
                        Qt.point(w,0),
                        Qt.point(w,h-l),
                        Qt.point(w*0.5+b*0.5,h-l),
                        Qt.point(w*0.5,h),
                        Qt.point(w*0.5-b*0.5,h-l),
                        Qt.point(0,h-l)

                    ];
            break;
        case HPdfToolTip.Position.Bottom:
            points= [
                        Qt.point(w,(h-l)*0.5+l),
                        Qt.point(w,h),
                        Qt.point(0,h),
                        Qt.point(0,l),
                        Qt.point(w*0.5-b*0.5,l),
                        Qt.point(w*0.5,0),
                        Qt.point(w*0.5+b*0.5,l),
                        Qt.point(w,l)
                    ];
            break;
        case HPdfToolTip.Position.Left:
            points= [
                        Qt.point((w-l)*0.5,h),
                        Qt.point(0,h),
                        Qt.point(0,0),
                        Qt.point(w-l,0),
                        Qt.point(w-l,h*0.5-b*0.5),
                        Qt.point(w,h*0.5),
                        Qt.point(w-l,h*0.5+b*0.5),
                        Qt.point(w-l,h)
                    ];
            break;
        case HPdfToolTip.Position.Right:
            points= [
                        Qt.point(l+(w-l)*0.5,0),
                        Qt.point(w,0),
                        Qt.point(w,h),
                        Qt.point(l,h),
                        Qt.point(l,h*0.5+b*0.5),
                        Qt.point(0,h*0.5),
                        Qt.point(l,h*0.5-b*0.5),
                        Qt.point(l,0)
                    ];
            break;
        }



        ctx.beginPath();
        ctx.moveTo(points[0].x, points[0].y);
        ctx.arcTo(points[1].x, points[1].y, points[2].x, points[2].y, r1);
        ctx.arcTo(points[2].x, points[2].y, points[3].x, points[3].y, r1);
        ctx.arcTo(points[3].x, points[3].y, points[4].x, points[4].y, r1);

        ctx.lineTo(points[4].x,points[4].y);
        ctx.arcTo(points[4].x,points[4].y,points[5].x,points[5].y,r2);
        ctx.arcTo(points[5].x,points[5].y,points[6].x,points[6].y,r2);
        ctx.lineTo(points[6].x,points[6].y);

        ctx.arcTo(points[6].x, points[6].y, points[7].x, points[7].y, r1);
        ctx.arcTo(points[7].x, points[7].y, points[0].x, points[0].y, r1);
        ctx.closePath();
        ctx.stroke();
    }

    Canvas {
        id:canvasBackground
        anchors.fill: parent
        antialiasing: true
        onPaint: {
            var ctx = getContext("2d");
            ctx.fillStyle = Style.colourTooltipTriangle;
            ctx.strokeStyle="transparent";
            var b=Style.tooltipRaisedBaseLength;
            var l=Style.tooltipRaisedLength;
            var r1=Style.tooltipRadius;
            var r2=Style.tooltipRaisedRadius;
            drawToolTip(canvasBackground.width,canvasBackground.height,b,l,r1,r2,ctx);
            ctx.fill();
        }

        Rectangle{
            id:textBackground
            color:"transparent"
            width:{
                switch(positionSelected)
                {
                case HPdfToolTip.Position.Top:
                case HPdfToolTip.Position.Bottom:
                    return canvasBackground.width
                case HPdfToolTip.Position.Left:
                case HPdfToolTip.Position.Right:
                    return canvasBackground.width-Style.tooltipRaisedLength;
                }
            }
            height:{
                switch(positionSelected)
                {
                case HPdfToolTip.Position.Top:
                case HPdfToolTip.Position.Bottom:
                    return canvasBackground.height-Style.tooltipRaisedLength;
                case HPdfToolTip.Position.Left:
                case HPdfToolTip.Position.Right:
                    return canvasBackground.height;
                }
            }
            anchors{
                bottom:bottomPosition?parent.bottom:undefined
                top:topPosition?parent.top:undefined
                right:rightPosition?parent.right:undefined
                left: leftPosition?parent.left:undefined
                }

            Text{
                id:textDescription
                color:Style.colourTooltipFont
                text: "SET ME"
                width:parent.width
                height:parent.height
                font.pixelSize: Style.pixelSizeTooltipText
                font.family: "Helvetica"
                verticalAlignment:  Text.AlignVCenter
                horizontalAlignment : Text.AlignHCenter
                font.weight: Font.Bold
            }
        }

    }
}

