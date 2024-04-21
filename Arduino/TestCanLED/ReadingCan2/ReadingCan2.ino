#include "can_communicator.h"
#include "SPI.h"

CANBUS_COMMUNICATOR *can;

// HeadLights -> Canbus data
#define ARDUINO_ID_ECU 2
#define ARDUINO_ID_HEADUNIT 1
#define CAN_ID_HEADLIGHTS 0x0230
#define CAN_DATA_HEADLIGHTS_TURN_ON 0b01000000
#define CAN_DATA_HEADLIGHTS_TURN_OF 0b00000000

// LED
#define LED_PIN 9

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);

  SPI.begin();
  can = new CANBUS_COMMUNICATOR(10, CAN_83K3BPS, MCP_16MHZ, CAN_B_DEF);
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


  can->printFrame(read);
}
