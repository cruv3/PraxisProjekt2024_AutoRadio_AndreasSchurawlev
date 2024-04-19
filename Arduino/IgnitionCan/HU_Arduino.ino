#include "can_communicator.h"
#include "SPI.h"

CANBUS_COMMUNICATOR *can;

#define IGNITION_PIN 3
#define IGNITION_ID 0x0001
#define IGNITION_DLC 3

int lastSwitchValue = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(IGNITION_PIN, INPUT_PULLUP);

  SPI.begin();
  can = new CANBUS_COMMUNICATOR(10, CAN_83K3BPS, MCP_16MHZ, CAN_B_DEF);
  delay(100);
}

void loop() {
  //NetWorkManagment();
  KL_15C_TWO();
  delay(10);
}

void NetWorkManagment(){
  int switchValue = digitalRead(IGNITION_PIN);

  can_frame sendFrame;
  sendFrame.can_id = 0x0001;
  sendFrame.can_dlc = 8;

  for(int i = 0; i < sendFrame.can_dlc; i++){
    sendFrame.data[i] = 0x00;
  }
  if(switchValue == LOW){
    Serial.println("Ignition On");
    sendFrame.data[0] = 0xFD;
    sendFrame.data[1] = 0x01;
    sendFrame.data[2] = 0x3F;
    sendFrame.data[3] = 0xFF;
    sendFrame.data[4] = 0xFF;
    sendFrame.data[5] = 0xFF;
    sendFrame.data[6] = 0xFF;
    sendFrame.data[7] = 0xFF;
    can->sendToBus(&sendFrame);
  } else {
    Serial.println("Ignition Off");
  }
  lastSwitchValue = switchValue;
}

void KL_15C_TWO(){
  int switchValue = digitalRead(IGNITION_PIN);

  can_frame sendFrame;
  sendFrame.can_id = 0x0000;
  sendFrame.can_dlc = 6;

  for(int i = 0; i < sendFrame.can_dlc; i++){
    sendFrame.data[i] = 0x00;
  }
  if(switchValue == LOW){
    Serial.println("Ignition On");
    sendFrame.data[0] = 0x03;
    sendFrame.data[2] = 0x02;
    //sendFrame.can_dlc = sizeof(sendFrame.data);
    can->sendToBus(&sendFrame);
  } else {
    Serial.println("Ignition Off");
  }
  lastSwitchValue = switchValue;
}
