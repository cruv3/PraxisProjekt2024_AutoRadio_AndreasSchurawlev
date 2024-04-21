#include "can_communicator.h"
#include "SPI.h"

CANBUS_COMMUNICATOR *can;

#define CAN_ID_LIGHTS 0x0230
#define CAN_DATA_LIGHTS_TURN_ON 0x40
#define CAN_DATA_LIGHTS_TURN_OFF 0x00

// LED
#define LED_PIN 3

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);

  SPI.begin();
  can = new CANBUS_COMMUNICATOR(10, CAN_83K3BPS, MCP_16MHZ);
  delay(100);
}

void loop() {
  handleMessage();
  delay(100);
}

void handleMessage(){
  can_frame *read = can->read_frame();
  
  if(read->can_dlc == 0)
  {
    return;
  }

  // check if the is the ECU for the Headlights
  // in our example 0x0230
  if(read->can_id == CAN_ID_LIGHTS)  
  {
    if(read->data[0] == CAN_DATA_LIGHTS_TURN_ON)
    {
      digitalWrite(LED_PIN, HIGH);
    }
    if(read->data[0] == CAN_DATA_LIGHTS_TURN_OFF)
    {
      digitalWrite(LED_PIN, LOW);
    }
    can->printFrame(read);
  }
}
