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

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "main.h"
#include "dronecan_packet_glue.h"

#include "DroneCANProtocol.h"
#include "DroneCAN_Packets.h"
#include "DroneCAN_SystemPackets.h"

#define ASSERT(condition) tests++; assert(condition)

static int tests = 0;

int main()
{
    printf("Done!\n");

    printf("------------------------------\n");
    printf("DroneCAN Protocol Unit Testing\n");
    printf("Protocol Version: %s / API %d\n", getDroneCANVersion(), getDroneCANApi());
    printf("------------------------------\n\n");

    printf("Running DroneCAN protocol tests:\n");

    testSystemPackets();

    printf("\n------------------------------\n");
    printf("Ran %d tests - all passed\n", tests);

    // All tests passed
    return 0;
}

void testSystemPackets()
{
    printf(" - Testing System Packets\n");

    DroneCAN_Packet_t pkt;

    encodeDroneCAN_UniqueIdPacket(
                &pkt,
                0x1234,
                0x5678,
                0xAABBCC,
                0xEF);

    // Check for correct packet ID
    ASSERT(pkt.id == PKT_DC_SYS_UID);

    // Check for correct data encoding
    ASSERT(pkt.data[0] == 0x12);
    ASSERT(pkt.data[1] == 0x34);

    // Decode the packet back into the original format
    uint32_t sn;
    uint16_t vid, pid;
    uint8_t address;

    decodeDroneCAN_UniqueIdPacket(&pkt, &vid, &pid, &sn, &address);

    ASSERT(vid == 0x1234);
    ASSERT(pid == 0x5678);
    ASSERT(sn == 0xAABBCC);
    ASSERT(address == 0xEF);

    ASSERT(pkt.length == 8);
}
