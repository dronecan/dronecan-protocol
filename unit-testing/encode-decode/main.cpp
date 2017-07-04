#include <stdio.h>

using namespace std;

#include "drone_can_packet.h"
#include "drone_can_protocol_glue.h"
#include "dc_pkt_cmd.h"

void printPacket(DC_Packet_t& pkt, bool extended = false);

void printPacket(DC_Packet_t& pkt, bool extended)
{
    printf("Packet 0x%08x -> ", pkt.id);

    for (int idx=0; idx<pkt.length; idx++)
    {
        printf("%02x ", pkt.data[idx]);
    }

    printf("\n");

    if (extended)
    {
        printf("Class: %u\n", DC_GetClassFromID(pkt.id));
        printf("Msg: %u\n", DC_GetMessageFromID(pkt.id));
        printf("Address: %u\n", DC_GetAddressFromID(pkt.id));
    }

}

int main(int argc, char *argv[])
{
    DC_Packet_t pkt;

    encodeDC_Cmd_PWMCommandPacket(&pkt, 1000);

    printPacket(pkt, true);

    uint32_t id;

    id = getDroneCANPacketID(&pkt);

    printf("Packet ID: %08x\n", id);

    id = getDC_CommandPacketID(&pkt);

    printf("Command pkt: %02x\n", id);

    return 0;
}
