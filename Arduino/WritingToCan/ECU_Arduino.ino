#include "can_communicator.h"
#include "SPI.h"

CANBUS_COMMUNICATOR *can;

struct can_frame_with_flag {
  bool isValid;
  can_frame frame;
};

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
  can_frame_with_flag message = readingIncomingCanbusMessages();
  handleIncomingMessageForHeadLights(message);
  delay(100);
}

void handleIncomingMessageForHeadLights(can_frame_with_flag message){
  if(!message.isValid){
    return;
  }
  // check if it comes from the this arduino
  if(message.frame.data[0] == ARDUINO_ID_ECU || message.frame.data[0] == ARDUINO_ID_HEADUNIT){
    return;
  }
  
  if(message.frame.can_id == CAN_ID_HEADLIGHTS){
    if(message.frame.data[1] == CAN_DATA_HEADLIGHTS_TURN_ON){
      turnOnCarLights();
    }else if(message.frame.data[1] == CAN_DATA_HEADLIGHTS_TURN_OF){
      turnOffCarLights();
    }
  }
}

can_frame_with_flag readingIncomingCanbusMessages(){
    can_frame *read = can->read_frame();
    can_frame_with_flag result;

    if (read->can_dlc != 0) {
      result.isValid = true;
    }else{
      result.isValid = false;
    }
    result.frame = *read;
    return result;
}

void turnOnCarLights(){
  Serial.println("Lights are on");
  digitalWrite(LED_PIN, HIGH);
}

void turnOffCarLights(){
  Serial.println("Lights are off");
  digitalWrite(LED_PIN, LOW);
}

// for simulating ecu communication
void sendRandomDataToCanbus(){
  can_frame sendRandom;
  sendRandom.can_dlc = 8; // 8 bytes data
  sendRandom.can_id = random(0, 0x80000000);
  // Set the first byte of data to ARDUINO_ID_ECU
  sendRandom.data[0] = ARDUINO_ID_ECU;
  for (int i = 1; i < sendRandom.can_dlc; ++i) {
    sendRandom.data[i] = random(0, 256); // Generate random data byte (0 to 255)
  }
  can->sendToBus(&sendRandom);
}
