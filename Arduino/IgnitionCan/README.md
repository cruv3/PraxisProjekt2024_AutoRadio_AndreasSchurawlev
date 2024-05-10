## Can-Signal an den Canbus-Adapter

### Ziel
Ziel hier ist es über den MCP2515 einen Signal an den Can-Bus-Adapter zu senden, um das Auto-Radio eingeschalten zu bekommen.
Dies erfolgt durch das senden eines Zündungssignal, wo dann der Can-Bus-Adapter einen 12v Signal an das Auto-Radio senden sollte.

### Prototyp-Aufbau
Der Prototype sieht follgendermaßen aus.

![Prototyp-Schematik](https://github.com/cruv3/PraxisProjekt2024_AutoRadio_AndreasSchurawlev/blob/main/img/CanbusAdapterTest.png)

### Ergebnis
Trotz dem senden des richtigen Signals für die Zündung, hat der Canbus-Adapter kein 12v Signal an das Auto-Radio gesendet. 
Dies bedeutet, dass die Can-Id mit den jeweiligen Can-Daten falsch vom Canbus-Adapter erfasst werden, da der Canbus-Adapter nach bestimmten Canbus-IDs filtert.

