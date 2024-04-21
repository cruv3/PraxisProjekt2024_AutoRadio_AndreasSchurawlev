#ifndef CANCOM_H

#define CANCOM_H

#include "can.h"
#include "mcp2515.h"

/**
 * Class to handle reading and writing to Canbus
 */
class CANBUS_COMMUNICATOR {
    public:

        /**
         * Clock is 16Mhz
         * @param cs_pin CS Pin of MCP2515 module
         * @param speed Speed of Canbus
         */
        CANBUS_COMMUNICATOR(uint8_t cs_pin, CAN_SPEED speed);
        /**
         * @param cs_pin CS Pin of MCP2515 module
         * @param speed Speed of Canbus
         * @param clock Clock frequency of MCP2515 module
         */
        CANBUS_COMMUNICATOR(uint8_t cs_pin, CAN_SPEED speed, CAN_CLOCK clock);
        /**
         * Sends frame to bus
         */
        void sendToBus(can_frame *send);

        void printFrame(can_frame *f);
        /**
         * Attempts to read a frame from canbus.
         * If no frame is found during the read cycle, then a frame with DLC of 0 is returned
         */
        can_frame *read_frame();

    private:
        String frame_string;
        can_frame read;
        MCP2515 *mcp;
};

#endif
