#ifndef _DC_PKT_H_
#define _DC_PKT_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DC_PAYLOAD_LEN_MAX 8

const uint32_t CAN_ID_MASK      = 0x1FFFFFFFUL;

// CAN frame ID masks
const uint32_t DC_MASK_ADDRESS  = 0x000000FFUL;
const uint32_t DC_MASK_DIR      = 0x00000100UL;
const uint32_t DC_MASK_MSG      = 0x001FFE00UL;
const uint32_t DC_MASK_RESERVED = 0x01E00000UL;
const uint32_t DC_MASK_CLASS    = 0x1E000000UL;

// Broadcast node address
const uint8_t DC_ADDRESS_BROADCAST = 0xFF;

typedef struct
{
  // Identifier extension
  unsigned ide : 1;

  // Remote transmission request
  unsigned rtr : 1;

} DC_CANFlags_t;

typedef struct
{
  // CAN frame identifier
  uint32_t id;

  // CAN frame payload data
  uint8_t data[DC_PAYLOAD_LEN_MAX];

  // CAN frame payload length
  uint8_t length;

  // CAN frame flags
  DC_CANFlags_t flags;

} DC_Packet_t;

/*
 * Top-level DroneCAN packet functions
 */
void finishDroneCANPacket(DC_Packet_t* pkt, int size, uint32_t id);
uint8_t* getDroneCanPacketData(DC_Packet_t* pkt);
const uint8_t* getDroneCANPacketDataConst(const DC_Packet_t* pkt);
int getDroneCANPacketSize(const DC_Packet_t* pkt);
uint32_t getDroneCANPacketID(const DC_Packet_t* pkt);

#ifdef __cplusplus
}
#endif

#endif //_DC_PKT_H_
