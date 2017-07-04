#include <stdio.h>

using namespace std;

#include "drone_can_packet.h"
#include "dc_pkt_cmd.h"

void printPacket(DC_Packet_t& pkt);

void printPacket(DC_Packet_t& pkt)
{
    printf("pkt %08x -> ", pkt.id);

    for (int idx=0; idx<pkt.length; idx++)
    {
        printf("%02x", pkt.data[idx]);
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    DC_Packet_t pkt;

    encodeDC_Cmd_PWMCommandPacket(&pkt, 1000);

    printPacket(pkt);

    return 0;
}
