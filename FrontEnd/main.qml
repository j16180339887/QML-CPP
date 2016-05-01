import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

//ApplicationWindow {
Rectangle {
    id: app
    visible: true

    /* this is a qml class example "colors" */
    property variant colors: {
        "blue": "#0696f5",
        "purple": "purple",
        "red": "red",
        "darkblue": "#0474d3"
    }

    color: colors.blue

    signal onWindowMaximum ()
    signal onWindowMinimum ()
    signal onWindowNormal ()
    signal onWindowShow ()
    signal onWindowHide ()
    signal onWindowClose ()
    signal onWindowMove (point p)
    signal onSettingClick ()
    signal onNewClick ()


//    flags: Qt.Window | Qt.FramelessWindowHint | Qt.WindowSystemMenuHint | Qt.WindowMinMaxButtonsHint

    property bool maxed: false
    property variant win
    FontLoader { id: webFont; source: "qrc:/Font/Resourse/Font/UbuntuWqy.ttf" }

    Rectangle {
        id: drivesArea
        color: "white"
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        height: parent.height / 1.2
    }

    MouseArea {
        id: appMouseArea
        property variant clickPos: "1,1"
//        anchors.fill: parent
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: drivesArea.top

        onPressed: {
            clickPos  = Qt.point(mouse.x,mouse.y)
        }

//        onMouseXChanged: {
//            onWindowMove (Qt.point(mouse.x-clickPos.x, 0))
//        }

//        onMouseYChanged: {
//            onWindowMove (Qt.point(0, mouse.y-clickPos.y))
//        }

        onPositionChanged: {
            onWindowMove (Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y))
//            console.log("clickPos " + clickPos.x + ", " + clickPos.y);
//            var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)
//            app.x += delta.x;
//            app.y += delta.y;
        }

        onDoubleClicked: {
            onWindowMaxChange()
        }
    }

    Button {
        id: closeWindow
        width: 25
        height: 25
        anchors.top: parent.top
        anchors.right: parent.right
        enabled: true
//        iconSource: "qrc:/Image/Resourse/Images/quit.png"
        property bool buttonHovered: false
//        text: qsTr("X")

        style: ButtonStyle {
            label: Text {
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: webFont.name
                text: control.text
                font.pointSize: 14
                color: "white"
            }
            background: Rectangle {
                color: closeWindow.hovered ? colors.red : colors.blue
//                radius: width / 2
            }
        }

        Image {
            anchors.fill: parent
            source: "qrc:/Image/Resourse/Images/quit.png"
//            fillMode: Image.Tile
        }

        onClicked: {
            onWindowHide ()
        }
    }

    Button {
        id: maxWindow
        width: 25
        height: 25
        anchors.top: parent.top
        anchors.right: closeWindow.left
        enabled: true
        property bool buttonHovered: false
//        text: qsTr("□")

        style: ButtonStyle {
            label: Text {
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: webFont.name
                text: control.text
                font.pointSize: 20
                color: "white"
            }
            background: Rectangle {
                color: maxWindow.hovered ? colors.darkblue : colors.blue
//                radius: width / 2
            }
        }

        Image {
            id: maxWindowIcon
            anchors.fill: parent
            source: "qrc:/Image/Resourse/Images/max.png"
//            fillMode: Image.Tile
        }

        onClicked: {
            onWindowMaxChange()
        }
    }

    Button {
        id: minWindow
        width: 25
        height: 25
        anchors.top: parent.top
        anchors.right: maxWindow.left
        enabled: true
        property bool buttonHovered: false
//        text: qsTr("_")

        style: ButtonStyle {
            label: Text {
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: webFont.name
                text: control.text
                font.pointSize: 12
                color: "white"
            }
            background: Rectangle {
                color: minWindow.hovered ? colors.darkblue : colors.blue
//                radius: width / 2
            }
        }

        Image {
            anchors.fill: parent
            source: "qrc:/Image/Resourse/Images/min.png"
//            fillMode: Image.Tile
        }

        onClicked: {
            onWindowMinimum ()
        }
    }

    Button {
        id: setWindow
        width: 25
        height: 25
        anchors.top: parent.top
        anchors.right: minWindow.left
        enabled: true
        property bool buttonHovered: false
//        text: qsTr("S")

        style: ButtonStyle {
            label: Text {
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: webFont.name
                text: control.text
                font.pointSize: 12
                color: "white"
            }
            background: Rectangle {
                color: setWindow.hovered ? colors.darkblue : colors.blue
//                radius: width / 2
            }
        }

        Image {
            id: setWindowIcon
            anchors.fill: parent
            source: "qrc:/Image/Resourse/Images/setting.png"
//            fillMode: Image.Tile
        }

        onClicked: {
//            showSettingWindow()
//            appMouseArea.enabled = false
            onSettingClick()
        }
    }

    Button {
        id: newItem
        width: 50
        height: 50
        anchors.top: parent.top
        anchors.left: parent.left
        enabled: true
        property bool buttonHovered: false
        text: qsTr("+")

        style: ButtonStyle {
            label: Text {
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: webFont.name
                text: control.text
                font.pointSize: 30
                color: "white"
            }
            background: Rectangle {
                color: "red"
                radius: width / 2
            }
        }

        onClicked: {
            onNewClick()
//            showSettingWindow()
//            appMouseArea.enabled = false
        }
    }

//    function showSettingWindow() {
//        var component = Qt.createComponent("Setting.qml")
//        if( component.status !== Component.Ready )
//        {
//            if( component.status === Component.Error )
//                console.debug("Error:"+ component.errorString() );
//            return; // or maybe throw
//        }
//        win = component.createObject(app)
//        onWindowNormal ()
//        win.show()
//    }

    function onWindowMaxChange() {
        if (!maxed) {
            onWindowMaximum ()
//            maxWindow.text = qsTr("-")
            maxWindowIcon.source = "qrc:/Image/Resourse/Images/normal.png"
        } else {
            onWindowNormal ()
//            maxWindow.text = qsTr("□")
            maxWindowIcon.source = "qrc:/Image/Resourse/Images/max.png"
        }
        maxed = !maxed
    }

    function updateQMLDrives(CloudDrives) {
        console.log("updateQMLDrives")
        for (var i = 0; i < CloudDrives.length; i++)
        {
            console.log(CloudDrives[i])
            var component = Qt.createComponent("DriveProcessbar.qml")
            if (component.status === Component.Ready) {
                component.createObject(drivesArea, {"x": 100, "y": 100 + i *100});
            }
            else {
                console.log("Error:updateQMLDrives")
            }
        }
    }
}
