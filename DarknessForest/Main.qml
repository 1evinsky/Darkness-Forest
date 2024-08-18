import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window
{
    id: root

    width: 414
    height: 736
    visible: true

    flags: Qt.Window | Qt.WindowFullscreenButtonHint

    visibility: Qt.platform.os === "windows" ? Window.Windowed : Window.FullScreen

    Component.onCompleted:
    {
        console.error(">>>>>>>>>>>>>>", width, height)
    }

    Rectangle
    {
        id: background

        anchors.fill: parent
        color: "#0F1A1E"
    }

    Item
    {
        id: statusBarItem

        anchors.top: parent.top
        width: root.width
        height: 50

        Rectangle
        {
            id: statusBarBackground

            color: "#192F28"
            anchors.fill: parent
            radius: 10
        }

        Row
        {
            id: rowItems

            anchors.centerIn: parent
            spacing: 15

            Rectangle
            {
                id: startRectangle

                width: 100
                height: 25

                color: "#0F1A1E"
                opacity: 0.4
                border.width: 2
                border.color: "#0c1418"
                radius: 5

                Image
                {
                    id: startLable
                    source: "qrc:/svg/images/star.svg"
                    width: 25
                    height: 25
                }
                Label
                {
                    anchors.left: startLable.right
//                    anchors.horizontalCenter: startRectangle.horizontalCenter
//                    anchors.verticalCenter: startRectangle.verticalCenter
                    width: startRectangle.width - startLable.width - 10
                    height: 25
                    text: "251"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Rectangle
            {
                id: heartRectangle

                width: 100
                height: 25
                color: "#0F1A1E"
                opacity: 0.4
                border.width: 4
                border.color: "#0c1418"
                radius: 5

                Image
                {
                    id: heartLable
                    source: "qrc:/svg/images/heart.svg"
                    width: 25
                    height: 25
                }
                Label
                {
                    anchors.left: heartLable.right
//                    anchors.horizontalCenter: heartRectangle.horizontalCenter
//                    anchors.verticalCenter: heartRectangle.verticalCenter
                    width: heartRectangle.width - heartLable.width - 10
                    height: 25
                    text: "100"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
            Rectangle
            {
                id: coinsRectangle

                width: 100
                height: 25
                color: "#0F1A1E"
                opacity: 0.4
                border.width: 2
                border.color: "#0c1418"
                radius: 5

                Image
                {
                    id: coinsLable
                    source: "qrc:/svg/images/coins.svg"
                    width: 25
                    height: 25
                }
                Label
                {
                    anchors.left: coinsLable.right
//                    anchors.horizontalCenter: coinsRectangle.horizontalCenter
//                    anchors.verticalCenter: coinsRectangle.verticalCenter
                    width: coinsRectangle.width - coinsLable.width - 10
                    height: 25
                    text: "1000"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }

    Item
    {
        id: pageShopItem

        anchors.top: statusBarItem.bottom
        anchors.topMargin: 10
        anchors.bottom: buttonBarItem.top
        anchors.bottomMargin: 10

        width: root.width

        Rectangle
        {
            id: pageItemBackground
            anchors.fill: parent
            color: "#3E5646"
        }

        Item
        {
            id: gridItem

            anchors.top: parent.top

            width: parent.width
            height: parent.height/2

            Rectangle
            {
                anchors.fill: parent
                color: "transparent"
                border.color: "#070d0f"
                border.width: 2
            }

            GridView
            {
                id: grid

                width: gridItem.width - 6
                height: gridItem.height - 5

                anchors.centerIn: parent

                model: 150
                cellWidth: width/15
                cellHeight: height/10

                interactive: false
                clip: false

                delegate: Item
                {
                    id: boxItem

                    width: grid.cellWidth - 1
                    height: grid.cellHeight - 1

                    property bool active: false
                    property color uiColor: active ? "#4f0f0f" : "#0F1A1E"

                    Rectangle
                    {
                        anchors.fill: parent
                        color: boxItem.uiColor
                        opacity: 0.4
                        border.width: 2
                        border.color: "#0c1418"
                        radius: 5
                    }

                    MouseArea
                    {
                        id: mArea
                        anchors.fill: boxItem
                        onPressed: active = !active
                    }
                }
            }
        }

    }

    Item
    {
        id: buttonBarItem

        anchors.bottom: parent.bottom
        width: root.width
        height: 100

        Rectangle
        {
            id: buttonBarBackground

            color: "#887A57"
            anchors.fill: parent
            radius: 10
        }
    }
}
