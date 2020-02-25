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

#ifndef _DRONECAN_ID_H_
#define _DRONECAN_ID_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// DroneCAN message identifier bitmasks
#define DRONECAN_ID_MASK 0x1FFFFFFF

#define DRONECAN_ID_PRIORITY_OFFSET     27
#define DRONECAN_ID_VENDOR_OFFSET       26
#define DRONECAN_ID_MULTIFRAME_OFFSET   25
#define DRONECAN_ID_DIRECTION_OFFSET    24
#define DRONECAN_ID_MESSAGE_OFFSET      8
#define DRONECAN_ID_ADDRESS_OFFSET      0

#define DRONECAN_ID_PRIORITY_MASK       0x18000000
#define DRONECAN_ID_VENDOR_MASK         0x04000000
#define DRONECAN_ID_MULTIFRAME_MASK     0x02000000
#define DRONECAN_ID_DIRECTION_MASK      0x01000000
#define DRONECAN_ID_MESSAGE_MASK        0x00FFFF00
#define DRONECAN_ID_ADDRESS_MASK        0x000000FF

/**
 * DroneCAN message identifier struct:
 * 
 * Priority: 2 bits of message priority
 * Vendor: Set if a vendor-specific message, cleared otherwise
 * Multiframe: Set for multi-frame message, cleared otherwise
 * Direction: 0 = "To" addressed device, 1 = "From" addressed device
 * Message: 16-bit message identifier
 * Address: 8-bit device address
 */
typedef struct {
    unsigned priority: 2;
    unsigned vendor: 1;
    unsigned multiframe: 1;
    unsigned direction: 1;
    unsigned message: 16;
    unsigned address: 8;
} DroneCAN_ID_t;


uint32_t DroneCAN_encodeID(DroneCAN_ID_t* idStruct);
void DroneCAN_decodeID(uint32_t id, DroneCAN_ID_t* idStruct);


#ifdef __cplusplus
}
#endif


#endif //_DRONECAN_ID_H_
