import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
  visible: true
  width: 640
  height: 480
  title: qsTr("Hello World")

  Rectangle {
    anchors.fill: parent
    color: "gray"


    TextArea {
      anchors.fill: parent

      anchors.margins: 15
      id: textArea
      textFormat: Text.RichText
      wrapMode: Text.WordWrap
      readOnly: true
      text: textData
      background: Rectangle{color: "white"}
    } // TextArea

  }
}
