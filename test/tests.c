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
#include "munit/munit.h"
#include "dronecan_packet_glue.h"

#include "DroneCANProtocol.h"
#include "dronecan_packets.h"
#include "dronecan_system_packets.h"
#include "dronecan_parameter_packets.h"

#include "dronecan_id.h"
#include "dronecan_param.h"
#include "dronecan_packet_descriptor.h"


DroneCAN_Packet_t pkt;


static MunitResult test_id_packet(const MunitParameter params[], void* data)
{
    DroneCAN_ID_t id;

    // Encode an ID struct to a 32-bit ID
    id.priority = DRONECAN_PRIORITY_ELEVATED;
    id.vendor = 0;
    id.multiframe = 0;
    id.direction = 1;
    id.message = 0x1234;
    id.address = 0x64;

    uint32_t enc = DroneCAN_encodeID(&id);

    munit_assert(enc == 0x9123464);

    // Decode the result back into a struct
    DroneCAN_decodeID(enc, &id);

    munit_assert(id.priority == DRONECAN_PRIORITY_ELEVATED);
    munit_assert(id.vendor == 0);
    munit_assert(id.multiframe == 0);
    munit_assert(id.direction == 1);
    munit_assert(id.message == 0x1234);
    munit_assert(id.address == 0x64);

    return MUNIT_OK;
}


static MunitResult test_params(const MunitParameter params[], void* data)
{
DroneCAN_Parameter_t param;

    // Encode a 16-bit unsigned value parameter
    encodeDroneCAN_ParameterValueU16Packet(&pkt, 0, 0x1234);

    munit_assert(pkt.id == PKT_DC_PARAM_VALUE);
    munit_assert(pkt.length == 5);

    uint16_t idx = 0;

    // Attempt to decode it into the union
    if (decodeDroneCAN_ParameterValueU16Packet(&pkt, &idx, &param.value_uint16))
    {
        munit_assert(param.value_uint16 == 0x1234);
    }
    else
    {
        munit_assert(false);
    }

    // Attempt to decode as a different parameter type
    munit_assert(decodeDroneCAN_ParameterValueS16Packet(&pkt, &idx, &param.value_sint16) == 0);

    // Encode a 'void' packet
    encodeDroneCAN_ParameterNullPacket(&pkt, 1);

    munit_assert(pkt.id == PKT_DC_PARAM_INFO);
    munit_assert(pkt.length == 3);
    munit_assert(pkt.data[2] == DRONECAN_PARAMETER_NULL);

    // Ensure that it decodes
    munit_assert(decodeDroneCAN_ParameterNullPacket(&pkt, &idx) == 1);

    // Encode a parameter information packet
    // Let's call it "number of motor poles" like it is an ESC or something crazy

    const char* param_name = "esc.settings.motor.numPoles";

    encodeDroneCAN_ParameterInfoPacket(&pkt, 0, DRONECAN_PARAMETER_UINT8, param_name);

    munit_assert(pkt.length == 31);
    munit_assert(pkt.id == PKT_DC_PARAM_INFO);
    munit_assert(pkt.data[2] == DRONECAN_PARAMETER_UINT8);

    // Now decode it into the parameter
    munit_assert(decodeDroneCAN_ParameterInfoPacket(&pkt, &idx, &param.format, param.name) == 1);

    munit_assert(strcmp(param.name, param_name) == 0);

    munit_assert(param.format == DRONECAN_PARAMETER_UINT8);

    return MUNIT_OK;
}


static MunitResult test_uid(const MunitParameter params[], void* data)
{
    encodeDroneCAN_UniqueIdPacket(
                &pkt,
                0x1234,
                0x5678,
                0xAABBCC,
                0xEF);

    // Check for correct packet ID
    munit_assert(pkt.id == PKT_DC_SYS_UID);

    // Check for correct data encoding
    munit_assert(pkt.data[0] == 0x12);
    munit_assert(pkt.data[1] == 0x34);

    // Decode the packet back into the original format
    uint32_t sn;
    uint16_t vid, pid;
    uint8_t address;

    decodeDroneCAN_UniqueIdPacket(&pkt, &vid, &pid, &sn, &address);
    munit_assert(vid == 0x1234);
    munit_assert(pid == 0x5678);
    munit_assert(sn == 0xAABBCC);
    munit_assert(address == 0xEF);

    munit_assert(pkt.length == 8);

    return MUNIT_OK;
}


static MunitResult test_fw(const MunitParameter params[], void* data)
{
    // Test a firmware version structure encode
    DroneCAN_FirmwareVersion_t fw;

    fw.checksum = 0x12345678;
    fw.versionMajor = 1;
    fw.versionMinor = 2;
    fw.versionSub = 3;

    encodeDroneCAN_FirmwareVersionPacketStructure(&pkt, &fw);

    munit_assert(pkt.id == PKT_DC_SYS_FW_VERSION);

    munit_assert(pkt.length >= 7);

    return MUNIT_OK;
}


static MunitResult test_id_strings(const MunitParameter params[], void* data)
{
    encodeDroneCAN_ManufacturerStringPacket(&pkt, "ACME Devices");

    munit_assert(pkt.id == PKT_DC_SYS_MANF_STRING);
    munit_assert(pkt.length == 13);

    const char* user_string = "My user string";

    encodeDroneCAN_UserStringPacket(&pkt, user_string);

    munit_assert(pkt.id == PKT_DC_SYS_USER_STRING);
    munit_assert(pkt.length == 15);

    char s[64];

    // Ensure that the packet decodes the string correctly
    if (decodeDroneCAN_UserStringPacket(&pkt, s))
    {
        munit_assert(strcmp(s, user_string) == 0);
    }
    else
    {
        printf("User String packet decoded incorrectly\n");
        munit_assert(false);
    }
    
    // Assert that decoding as a different packet will fail
    munit_assert(decodeDroneCAN_ManufacturerStringPacket(&pkt, s) == 0);

    return MUNIT_OK;
}

static MunitResult test_pkt_label(const MunitParameter params[], void* data)
{
    char s[512];

    strcpy(s, DroneCAN_PacketLabel(PKT_DC_SYS_UID));

    munit_assert(strlen(s) > 0);

    // A packet which is out of range should return empty string
    strcpy(s, DroneCAN_PacketLabel(0x12345));

    munit_assert(strlen(s) == 0);

    return MUNIT_OK;
}

static MunitResult test_pkt_description(const MunitParameter params[], void* data)
{
    char s[512];

    strcpy(s, DroneCAN_PacketDescription(PKT_DC_SYS_UID));

    munit_assert(strlen(s) > 0);

    // A packet which is out of range should return emptry string
    strcpy(s, DroneCAN_PacketDescription(0x12345));

    munit_assert(strlen(s) == 0);

    return MUNIT_OK;
}

static MunitTest dronecan_tests[] = {
    { "/id/", test_id_packet, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/params/", test_params, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/uid/", test_uid, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/fw/", test_fw, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/id-strings/", test_id_strings, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/pkt-label/", test_pkt_label, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/pkt-description/", test_pkt_description, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};


static const MunitSuite dronecan_test_suite = {
    (char*) "dronecan", dronecan_tests,
    NULL,
    1, MUNIT_SUITE_OPTION_NONE
};


int main(int argc, char** argv)
{
    printf("------------------------------\n");
    printf("DroneCAN Protocol Unit Testing\n");
    printf("Protocol Version: %s / API %d\n", getDroneCANVersion(), getDroneCANApi());
    printf("------------------------------\n\n");

    return munit_suite_main(&dronecan_test_suite, (void*) "", argc, argv);
};