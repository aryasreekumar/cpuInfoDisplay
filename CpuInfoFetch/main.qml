import QtQuick 2.4
import QtQuick.Window 2.2

Window {

    property alias text: cpuInfo.text

    visible: true
    width: 700
    height: 700
    color: "#1a0101"
    opacity: 0.70
    title: "Terminal"


Flickable{
    width: 700
    height: 700
    contentHeight: 2800
    contentWidth: 700
    interactive: true
    boundsBehavior: Flickable.StopAtBounds

        MouseArea {
            anchors.fill: parent
            onClicked: {
                Qt.quit();
            }

            Text {
                id: firstLine
                x: 23
                y: 33
                width: 45
                color: "#f2ecec"
                text: "cat /proc/cpuinfo"
            }

        Text {
            id: cpuInfo
            objectName: "cpuInfo"
            x: 24
            y: 126
            width: 676
            height: 494
            color: "#f2f2f2"
            text: "Change this text"
            font.pixelSize: 12
            }
        }
    }
}

