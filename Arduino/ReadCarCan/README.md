## Test mit zwei Arduinos

### Ziel
Das Ziel dieses Tests ist es, die CAN-Kommunikation zwischen dem Arduino mit dem MCP2515 und mit dem Auto herzustellen und sich die Can-Daten die durch das Auto laufen, anzuschauen und zu verstehen.

### Prototyp-Aufbau
Der Prototyp besteht aus einem Arduino und einem MCP2515. Der MCP2515 empfängt einkommende CAN-Daten aus dem Auto und der Arduino liest die dann aus. Zur Veranschaulichung ist die schematische Darstellung des Prototyps unten dargestellt:

![Prototyp-Schematik](https://github.com/cruv3/PraxisProjekt2024_AutoRadio_AndreasSchurawlev/blob/main/Arduino/TestCanLED/img/LedTestWhiteBackGround.png)

### Ergebnis
Wir konnten die CAN-Daten auslesen und mithilfe eines Python-Skripts sortieren. Dadurch war es uns möglich herauszufinden, welche CAN-IDs Veränderungen aufwiesen. Durch das Ein- und Ausschalten der Zündung konnten wir bei einer bestimmten CAN-ID feststellen, wie sich die Daten genau veränderten, um dies reproduzieren zu können.
