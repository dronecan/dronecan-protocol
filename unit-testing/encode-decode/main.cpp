#include <stdio.h>

using namespace std;

#include "drone_can_classes.h"
#include "drone_can_packet.h"
#include "drone_can_protocol_glue.h"
#include "dc_pkt_cmd.h"

void printPacket(DC_Packet_t& pkt, bool extended = false);

void printPacket(DC_Packet_t& pkt, bool extended)
{
    printf("Packet 0x%08x -> ", pkt.id);

    for (int idx=0; idx<pkt.length; idx++)
    {
        printf  ("%02x ", pkt.data[idx]);
    }

    printf("\n");

    if (extended)
    {
        printf("Class: %s (%u)\n", DC_GetClassName(DC_GetClassFromID(pkt.id)), DC_GetClassFromID(pkt.id));
        printf("Msg: %u\n", DC_GetMessageFromID(pkt.id));
        printf("Address: %u\n", DC_GetAddressFromID(pkt.id));
        printf("Direction: %s\n", DC_GetDirectionFromID(pkt.id) == DC_MSG_DIR_TO ? "to" : "from");
    }
}

int main(int argc, char *argv[])
{
    DC_Packet_t pkt;

    encodeDC_Cmd_PWMCommandPacket(&pkt, 1000);

    printPacket(pkt, true);

    DC_SetAddress(&pkt.id, 123);
    DC_SetDirection(&pkt.id, DC_MSG_DIR_FROM);

    printPacket(pkt, true);

    return 0;
}
