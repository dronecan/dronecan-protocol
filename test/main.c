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
#include <string.h>

#include "main.h"
#include "dronecan_packet_glue.h"

#include "DroneCANProtocol.h"
#include "dronecan_packets.h"
#include "dronecan_system_packets.h"
#include "dronecan_parameter_packets.h"

#include "dronecan_id.h"
#include "dronecan_param.h"
#include "dronecan_packet_descriptor.h"


#define ASSERT(condition) tests++; assert(condition)

static int tests = 0;

static DroneCAN_Packet_t pkt;

int main()
{
    printf("Done!\n");

    printf("------------------------------\n");
    printf("DroneCAN Protocol Unit Testing\n");
    printf("Protocol Version: %s / API %d\n", getDroneCANVersion(), getDroneCANApi());
    printf("------------------------------\n\n");

    printf("Running DroneCAN protocol tests:\n");

    /* Static code tests */
    testId();

    /* Generated protocol code test */

    testParams();

    testUID();
    testFirmwareVersion();
    testIDStrings();

    /* Packet descriptor lookup */
    testPacketLabel();
    testPacketDescription();

    printf("\n------------------------------\n");
    printf("Ran %d tests - all passed\n", tests);

    // All tests passed
    return 0;
}


void testId()
{
    printf(" - Testing CAN ID routines\n");

    DroneCAN_ID_t id;

    // Encode an ID struct to a 32-bit ID
    id.priority = DRONECAN_PRIORITY_ELEVATED;
    id.vendor = 0;
    id.multiframe = 0;
    id.direction = 1;
    id.message = 0x1234;
    id.address = 0x64;

    uint32_t tmp = DroneCAN_encodeID(&id);

    ASSERT(tmp == 0x9123464);

    // Decode the result back into a struct
    DroneCAN_decodeID(tmp, &id);

    ASSERT(id.priority == DRONECAN_PRIORITY_ELEVATED);
    ASSERT(id.vendor == 0);
    ASSERT(id.multiframe == 0);
    ASSERT(id.direction == 1);
    ASSERT(id.message == 0x1234);
    ASSERT(id.address == 0x64);
}


void testParams()
{
    printf(" - Testing parameters\n");

    DroneCAN_Parameter_t param;

    // Encode a 16-bit unsigned value parameter
    encodeDroneCAN_ParameterValueU16Packet(&pkt, 0, 0x1234);

    ASSERT(pkt.id == PKT_DC_PARAM_VALUE);
    ASSERT(pkt.length == 5);

    uint16_t idx = 0;

    // Attempt to decode it into the union
    if (decodeDroneCAN_ParameterValueU16Packet(&pkt, &idx, &param.value_uint16))
    {
        ASSERT(param.value_uint16 == 0x1234);
    }
    else
    {
        ASSERT(false);
    }

    // Attempt to decode as a different parameter type
    ASSERT(decodeDroneCAN_ParameterValueS16Packet(&pkt, &idx, &param.value_sint16) == 0);

    // Encode a 'void' packet
    encodeDroneCAN_ParameterNullPacket(&pkt, 1);

    ASSERT(pkt.id == PKT_DC_PARAM_INFO);
    ASSERT(pkt.length == 3);
    ASSERT(pkt.data[2] == DRONECAN_PARAMETER_NULL);

    // Ensure that it decodes
    ASSERT(decodeDroneCAN_ParameterNullPacket(&pkt, &idx) == 1);

    // Encode a parameter information packet
    // Let's call it "number of motor poles" like it is an ESC or something crazy

    const char* param_name = "esc.settings.motor.numPoles";

    encodeDroneCAN_ParameterInfoPacket(&pkt, 0, DRONECAN_PARAMETER_UINT8, param_name);

    ASSERT(pkt.length == 31);
    ASSERT(pkt.id == PKT_DC_PARAM_INFO);
    ASSERT(pkt.data[2] == DRONECAN_PARAMETER_UINT8);

    // Now decode it into the parameter
    ASSERT(decodeDroneCAN_ParameterInfoPacket(&pkt, &idx, &param.format, param.name) == 1);

    ASSERT(strcmp(param.name, param_name) == 0);

    ASSERT(param.format == DRONECAN_PARAMETER_UINT8);
}


/**
 * Test the UniqueID packets
 */
void testUID()
{
    printf(" - Testing System Packets\n");

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


void testFirmwareVersion()
{
    printf(" - Testing firmware version\n");

    // Test a firmware version structure encode
    DroneCAN_FirmwareVersion_t fw;

    fw.checksum = 0x12345678;
    fw.versionMajor = 1;
    fw.versionMinor = 2;
    fw.versionSub = 3;

    encodeDroneCAN_FirmwareVersionPacketStructure(&pkt, &fw);

    ASSERT(pkt.id == PKT_DC_SYS_FW_VERSION);

    ASSERT(pkt.length >= 7);
}


/**
 * Test the manufacturer and user strings
 */
void testIDStrings(void)
{
    printf(" - Testing ID strings\n");

    encodeDroneCAN_ManufacturerStringPacket(&pkt, "ACME Devices");

    ASSERT(pkt.id == PKT_DC_SYS_MANF_STRING);
    ASSERT(pkt.length == 13);

    const char* user_string = "My user string";

    encodeDroneCAN_UserStringPacket(&pkt, user_string);

    ASSERT(pkt.id == PKT_DC_SYS_USER_STRING);
    ASSERT(pkt.length == 15);

    char s[64];

    // Ensure that the packet decodes the string correctly
    if (decodeDroneCAN_UserStringPacket(&pkt, s))
    {
        ASSERT(strcmp(s, user_string) == 0);
    }
    else
    {
        assert(false);
    }
    
    // Assert that decoding as a different packet will fail
    ASSERT(decodeDroneCAN_ManufacturerStringPacket(&pkt, s) == 0);

}


void testPacketLabel(void)
{
    char s[512];

    strcpy(s, DroneCAN_PacketLabel(PKT_DC_SYS_UID));

    ASSERT(strlen(s) > 0);

    // A packet which is out of range should return empty string
    strcpy(s, DroneCAN_PacketLabel(0x12345));

    ASSERT(strlen(s) == 0);
}


void testPacketDescription(void)
{
    char s[512];

    strcpy(s, DroneCAN_PacketDescription(PKT_DC_SYS_UID));

    ASSERT(strlen(s) > 0);

    // A packet which is out of range should return emptry string
    strcpy(s, DroneCAN_PacketDescription(0x12345));

    ASSERT(strlen(s) == 0);
}