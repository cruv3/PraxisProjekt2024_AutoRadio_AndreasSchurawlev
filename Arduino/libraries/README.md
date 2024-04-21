# MCP2515 Library

Diese Bibliothek wurde erstellt, um die Verwendung des MCP2515 CAN-Controllers in Arduino-Projekten zu erleichtern. Sie umfasst die Grundfunktionen für die Initialisierung, den Empfang und das Senden von CAN-Frames.

## Ursprung der Bibliothek

Die MCP2515 Library basiert auf der ursprünglichen Github Projekt von [rnd-ash](https://github.com/rnd-ash/W203-canbus/tree/master/ARDUINO_CODE).

## Can_Communicator

Zusätzlich zur MCP2515 Library enthält dieses Repository den Can_Communicator, der eine erweiterte Schnittstelle für die CAN-Kommunikation bereitstellt. Der Can_Communicator baut auf der MCP2515 Library auf und fügt nützliche Funktionen hinzu, um CAN-Frames zu erstellen, zu lesen und zu senden. Die Entscheidung für die Verwendung dieser Bibliothek wurde getroffen, um von den erweiterten Funktionen des Can_Communicators zu profitieren, der eine benutzerfreundliche Schnittstelle und zusätzliche Funktionen bietet, die für das Projekt von Vorteil sind.


## Veränderungen

Für mein Projekt wurden einige Anpassungen an der Bibliothek vorgenommen, um sie besser an die Anforderungen anzupassen. Dazu gehören:

- **Entfernung überflüssiger Funktionen:** Einige Funktionen, die für mein Projekt nicht relevant waren, wurden aus der Bibliothek entfernt, um den Code schlanker und übersichtlicher zu gestalten.

