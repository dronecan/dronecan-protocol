#include "drone_can_packet.h"

void finishDroneCANPacket(DC_Packet_t* pkt, int size, uint32_t id)
{
  pkt->length = (uint8_t) size;
  pkt->id = id;
}

uint8_t* getDroneCanPacketData(DC_Packet_t* pkt)
{
  return &(pkt->data);
}

const uint8_t* getDroneCANPacketDataConst(const DC_Packet_t* pkt)
{
  return (const uint8_t*) &(pkt->data);
}

int getDroneCANPacketSize(const DC_Packet_t* pkt)
{
  return (int) pkt->length;
}

uint32_t getDroneCANPacketID(const DC_Packet_t* pkt)
{
  return pkt->id & CAN_ID_MASK;
}
