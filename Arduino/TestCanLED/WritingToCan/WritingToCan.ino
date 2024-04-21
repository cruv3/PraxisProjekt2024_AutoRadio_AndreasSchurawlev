#include "can_communicator.h"
#include "SPI.h"

CANBUS_COMMUNICATOR *can;

// Lights -> Canbus data
#define CAN_ID_LIGHTS 0x0230
#define CAN_DATA_LIGHTS_TURN_ON 0x40
#define CAN_DATA_LIGHTS_TURN_OFF 0x00
#define CAN_DLC_LIGHTS 1

// LED
#define BUTTON_PIN 3

bool light_state = false;

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  SPI.begin();
  can = new CANBUS_COMMUNICATOR(10, CAN_83K3BPS, MCP_16MHZ);
  delay(100);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == LOW) {
    light_state = !light_state;
    if(light_state){
      turnOnLights();
    }else{
      turnOffLights();
    }
  }
  delay(100);
}

void turnOnLights(){
  Serial.println("Lights are on");
  sendToCanbus(CAN_DATA_LIGHTS_TURN_ON);
}

void turnOffLights(){
  Serial.println("Lights are off");
  sendToCanbus(CAN_DATA_LIGHTS_TURN_OFF);
}

// for simulating ecu communication
void sendToCanbus(uint8_t data){
  can_frame send;
  send.can_id = CAN_ID_LIGHTS;
  send.can_dlc = CAN_DLC_LIGHTS;
  send.data[0] = data;
  can->sendToBus(&send);
}
