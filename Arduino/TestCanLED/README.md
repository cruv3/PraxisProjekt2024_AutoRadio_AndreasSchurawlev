## Test mit zwei Arduinos

### Ziel
Das Ziel dieses Tests ist es, die CAN-Kommunikation zwischen zwei Arduinos mithilfe des MCP2515 CAN-Controllers zu untersuchen und zu testen. Dabei soll eine LED über den CAN-Bus ein- und ausgeschaltet werden, um die Übertragung von CAN-Frames zwischen den beiden Arduinos zu demonstrieren.

### Prototyp-Aufbau
Der Prototyp besteht aus zwei Arduinos, die jeweils mit einem MCP2515 CAN-Controller verbunden sind. Die Arduinos sind über den CAN-Bus miteinander verbunden. Ein Arduino dient als Sender und ein anderer als Empfänger von CAN-Frames. Zur Veranschaulichung ist die schematische Darstellung des Prototyps unten dargestellt:

![Prototyp-Schematik](https://github.com/cruv3/PraxisProjekt2024_AutoRadio_AndreasSchurawlev/blob/main/Arduino/TestCanLED/img/LedTest.png)

Die Abbildung zeigt den Aufbau des Prototyps, bei dem zwei Arduinos über den MCP2515 CAN-Controller miteinander verbunden sind. Ein Arduino dient als Sender, der einen CAN-Frame mit einem Befehl zum Ein- oder Ausschalten der LED sendet, während der andere Arduino als Empfänger fungiert und die empfangenen CAN-Frames interpretiert, um die LED entsprechend ein- oder auszuschalten.
