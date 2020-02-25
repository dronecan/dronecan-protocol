/**

Copyright (c) 2020 DroneCAN

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

**/

#include "dronecan_id.h"

uint32_t DroneCAN_encodeID(DroneCAN_ID_t* idStruct)
{
    uint32_t id = 0;

    // Message priority
    id |= (idStruct->priority << DRONECAN_ID_PRIORITY_OFFSET);
    
    // Vendor message bit
    id |= (idStruct->vendor << DRONECAN_ID_VENDOR_OFFSET);

    // Multiframe message bit
    id |= (idStruct->multiframe << DRONECAN_ID_MULTIFRAME_OFFSET);

    // Message direction bit
    id |= (idStruct->direction << DRONECAN_ID_DIRECTION_OFFSET);

    // Message identifier
    id |= (idStruct->message << DRONECAN_ID_MESSAGE_OFFSET);

    // Message address
    id |= (idStruct->address);

    return id;
}


void DroneCAN_decodeID(uint32_t id, DroneCAN_ID_t* idStruct)
{
    // Message priority
    idStruct->priority = (id & DRONECAN_ID_PRIORITY_MASK) >> DRONECAN_ID_PRIORITY_OFFSET;

    // Vendor message bit
    idStruct->vendor = (id & DRONECAN_ID_VENDOR_MASK) >> DRONECAN_ID_VENDOR_OFFSET;

    // Multiframe message bit
    idStruct->multiframe = (id & DRONECAN_ID_MULTIFRAME_MASK) >> DRONECAN_ID_MULTIFRAME_OFFSET;

    // Message direction bit
    idStruct->direction = (id & DRONECAN_ID_DIRECTION_MASK) >> DRONECAN_ID_DIRECTION_OFFSET;

    // Message identifier
    idStruct->message = (id & DRONECAN_ID_MESSAGE_MASK) >> DRONECAN_ID_MESSAGE_OFFSET;

    // Message address
    idStruct->address = (id & DRONECAN_ID_ADDRESS_MASK) >> DRONECAN_ID_ADDRESS_OFFSET;
}
