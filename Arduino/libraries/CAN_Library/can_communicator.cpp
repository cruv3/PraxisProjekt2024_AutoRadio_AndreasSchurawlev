#include "can_communicator.h"

CANBUS_COMMUNICATOR::CANBUS_COMMUNICATOR(uint8_t cs_pin, CAN_SPEED speed, CAN_CLOCK clock) {
    this->mcp = new MCP2515(cs_pin);
    this->mcp->reset();
    uint8_t error = this->mcp->setBitrate(speed);
    if(error  != MCP2515::ERROR_OK) {
        Serial.println("ERROR SETTING UP CANBUS ");
    } else {
        Serial.println("Canbus Ready");
    }
    this->mcp->setNormalMode();
    frame_string.reserve(140);
}

CANBUS_COMMUNICATOR::CANBUS_COMMUNICATOR(uint8_t cs_pin, CAN_SPEED speed) {
    this->mcp = new MCP2515(cs_pin);
    this->mcp->reset();
    if(this->mcp->setBitrate(speed) != MCP2515::ERROR_OK) {
        Serial.println("ERROR SETTING UP CANBUS ");
    } else {
        Serial.println("Canbus Ready");
    }
    this->mcp->setNormalMode();
    frame_string.reserve(140);
}

void CANBUS_COMMUNICATOR::sendToBus(can_frame *send) {
    mcp->sendMessage(send);
    printFrame(send);
}

can_frame *CANBUS_COMMUNICATOR::read_frame() {
    // Setup default Error frame
    read.can_id = 0x00;
    read.can_dlc = 0x00;

    // Try and read a frame from Bus. If frame cannot be read, then the read frame
    // Retains its data
    mcp->readMessage(&read);
    return &read;
}

char idBuffer[7];
char hexBuffer[4];

void CANBUS_COMMUNICATOR::printFrame(can_frame *f) {
    frame_string = "";
    frame_string += millis();
    frame_string += ",";
    frame_string += f->can_id;
    frame_string += ",";
    frame_string += f->can_dlc;
    frame_string += ",";
    for (uint8_t i = 0; i < f->can_dlc; i++) {
        frame_string += f->data[i];
        frame_string += ",";
    }
    frame_string = frame_string.substring(0, frame_string.length() - 1);
    Serial.println(frame_string);
}
