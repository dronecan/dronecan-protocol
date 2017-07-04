// DC_CommandProtocol.h was generated by ProtoGen version 2.2.d

#ifndef _DC_COMMANDPROTOCOL_H
#define _DC_COMMANDPROTOCOL_H

// C++ compilers: don't mangle us
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \file
 * \mainpage DC_Command protocol stack
 *

 *
 * The protocol API enumeration is incremented anytime the protocol is changed
 * in a way that affects compatibility with earlier versions of the protocol.
 * The protocol enumeration for this version is: 1
 *
 * The protocol version is 1.0
 */

#include <stdint.h>
#include "drone_can_protocol_glue.h"	// Protocol glue files

//! \return the protocol API enumeration
#define getDC_CommandApi() 1

//! \return the protocol version string
#define getDC_CommandVersion() "1.0"
typedef enum
{
    DC_PKT_CMD_DISARM = 0x00,    
    DC_PKT_CMD_ARM,              
    DC_PKT_CMD_BRAKE = 0x10,     
    DC_PKT_CMD_RAW_VALUE = 0x20, 
    DC_PKT_CMD_TARGET_PWM,       
    DC_PKT_CMD_TARGET_RPM,       
    DC_PKT_CMD_TARGET_ANGLE,     
    DC_PKT_CMD_THROTTLE = 0x30,  //!< Throttle position command
    DC_PKT_CMD_INDICATOR = 0x40  //!< Indicator command
} DroneCAN_CommandMessages;


// The prototypes below provide an interface to the packets.
// They are not auto-generated functions, but must be hand-written

//! \return the packet data pointer from the packet
uint8_t* getDC_CommandPacketData(DC_Packet_t* pkt);

//! \return the packet data pointer from the packet, const
const uint8_t* getDC_CommandPacketDataConst(const DC_Packet_t* pkt);

//! Complete a packet after the data have been encoded
void finishDC_CommandPacket(DC_Packet_t* pkt, int size, uint32_t packetID);

//! \return the size of a packet from the packet header
int getDC_CommandPacketSize(const DC_Packet_t* pkt);

//! \return the ID of a packet from the packet header
uint32_t getDC_CommandPacketID(const DC_Packet_t* pkt);

#ifdef __cplusplus
}
#endif
#endif
