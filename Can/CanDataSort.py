def parse_line(line):
    parts = line.strip().split(',')
    millis = int(parts[0])
    can_id = int(parts[1], 16)  # Konvertiere die ID von hexadezimal nach dezimal
    dlc = int(parts[2])
    data = tuple(int(x) for x in parts[3:])  # Verwende tuple statt list, da Listen nicht hashbar sind
    return millis, can_id, dlc, data

def format_data_hex(data):
    return ', '.join(hex(x) for x in data)

def sort_can_messages(file_path):
    seen_messages = {}  # Verwende ein Dictionary, um bereits gesehene Nachrichten zu speichern

    with open(file_path, 'r') as file:
        for line in file:
            millis, can_id, dlc, data = parse_line(line)
            key = (can_id, data)  # Erzeuge ein Tupel aus ID und Daten
            if key not in seen_messages:
                seen_messages[key] = (millis, dlc)  # Speichere den Zeitstempel und DLC, wenn die Kombination einzigartig ist

    # Sortiere die einzigartigen Nachrichten nach ID
    sorted_messages = sorted(seen_messages.items(), key=lambda x: x[0][0])

    # Gib sortierte CAN-Nachrichten aus
    for (can_id, data), (millis, dlc) in sorted_messages:
        formatted_data = format_data_hex(data)
        print(f"Millis: {millis}, ID: {hex(can_id)}, DLC: {dlc}, Data: [{formatted_data}]")

# Dateipfad zur Textdatei
file_path = 'can_data.txt'

# Sortiere und gib CAN-Nachrichten aus
sort_can_messages(file_path)
