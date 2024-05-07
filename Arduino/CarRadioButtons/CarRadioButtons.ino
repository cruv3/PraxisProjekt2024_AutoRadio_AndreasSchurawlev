#include <AceButton.h>
using namespace ace_button;

#define IGNITION_PIN 12
#define RELAY_1_IGNITION_PIN 2
bool ignition_on = false;
bool last_ignition_state = false;
bool current_ignition_state = false;

#define REVERSE_PIN 13
#define RELAY_2_REVERSE_PIN 3
bool reverse_on = false;
bool last_reverse_state = false;
bool current_reverse_state = false;

#define ILLUMINATION_PIN 11
#define RELAY_3_ILLUMINATION_PIN 4
bool illumination_on = false;
bool last_illumination_state = false;
bool current_illumination_state = false;

#define HAND_BRAKE_PIN 10
#define RELAY_4_HAND_BRAKE_PIN 5
bool handBrake_on = false;
bool last_handBrake_state = false;
bool current_handBrake_state = false;


void setup() {
  Serial.begin(9600);
  Serial.println();
  Ignition_Init();
  Reverse_Init();
  Illumination_Init();
  HandBrake_Init();
}

void loop() {
  Ignition();
  Reverse();
  Illumination();
  HandBrake();
}

void Ignition_Init(){
  pinMode(RELAY_1_IGNITION_PIN, OUTPUT);
  pinMode(IGNITION_PIN, INPUT_PULLUP);
  digitalWrite(RELAY_1_IGNITION_PIN, HIGH);
  Serial.println("RELAY_1_Zuendung OFF");
}

void Ignition(){
  current_ignition_state = digitalRead(IGNITION_PIN);
  if (current_ignition_state != last_ignition_state) {
    if (current_ignition_state == LOW) {
      if (!ignition_on) {
        Serial.println("RELAY_1_Zuendung ON");
        digitalWrite(RELAY_1_IGNITION_PIN, LOW);
        ignition_on = true;
      } else {
        Serial.println("RELAY_1_Zuendung OFF");
        digitalWrite(RELAY_1_IGNITION_PIN, HIGH);
        ignition_on = false;
      }
    }
  }
  last_ignition_state = current_ignition_state;
}

void Reverse_Init(){
  pinMode(RELAY_2_REVERSE_PIN, OUTPUT);
  pinMode(REVERSE_PIN, INPUT_PULLUP);
  digitalWrite(RELAY_2_REVERSE_PIN, HIGH);
  Serial.println("RELAY_2_Reverse OFF");
}

void Reverse(){
  current_reverse_state = digitalRead(REVERSE_PIN);
  if (current_reverse_state != last_reverse_state) {
    if (current_reverse_state == LOW) {
      if (!reverse_on) {
        Serial.println("RELAY_2_Reverse ON");
        digitalWrite(RELAY_2_REVERSE_PIN, LOW);
        reverse_on = true;
      } else {
        Serial.println("RELAY_2_Reverse OFF");
        digitalWrite(RELAY_2_REVERSE_PIN, HIGH);
        reverse_on = false;
      }
    }
  }
  last_reverse_state = current_reverse_state;
}

void Illumination_Init(){
  pinMode(RELAY_3_ILLUMINATION_PIN, OUTPUT);
  pinMode(ILLUMINATION_PIN, INPUT_PULLUP);
  digitalWrite(RELAY_3_ILLUMINATION_PIN, HIGH);
  Serial.println("RELAY_3_Illumination OFF");
}

void Illumination(){
  current_illumination_state = digitalRead(ILLUMINATION_PIN);
  if (current_illumination_state != last_illumination_state) {
    if (current_illumination_state == LOW) {
      if (!illumination_on) {
        Serial.println("RELAY_3_Illumination ON");
        digitalWrite(RELAY_3_ILLUMINATION_PIN, LOW);
        illumination_on = true;
      } else {
        Serial.println("RELAY_3_Illumination OFF");
        digitalWrite(RELAY_3_ILLUMINATION_PIN, HIGH);
        illumination_on = false;
      }
    }
  }
  last_illumination_state = current_illumination_state;
}

void HandBrake_Init(){
  pinMode(RELAY_4_HAND_BRAKE_PIN, OUTPUT);
  pinMode(HAND_BRAKE_PIN, INPUT_PULLUP);
  digitalWrite(RELAY_4_HAND_BRAKE_PIN, HIGH);
  Serial.println("RELAY_4_HandBrake OFF");
}

void HandBrake(){
  current_handBrake_state = digitalRead(HAND_BRAKE_PIN);
  if (current_handBrake_state != last_handBrake_state) {
    if (current_handBrake_state == LOW) {
      if (!handBrake_on) {
        Serial.println("RELAY_4_HandBrake ON");
        digitalWrite(RELAY_4_HAND_BRAKE_PIN, LOW);
        handBrake_on = true;
      } else {
        Serial.println("RELAY_4_HandBrake OFF");
        digitalWrite(RELAY_4_HAND_BRAKE_PIN, HIGH);
        handBrake_on = false;
      }
    }
  }
  last_handBrake_state = current_handBrake_state;
}
