/*
 * This program source code file is part of DroneCAN protocol specification
 *
 * Copyright (C) 2017 Currawong Engineering, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#ifndef _DC_PKT_H_
#define _DC_PKT_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DC_PAYLOAD_LEN_MAX 8

#define CAN_ID_MASK      0x1FFFFFFFUL

// CAN frame ID masks
#define DC_MASK_ADDRESS  0x000000FFUL
#define DC_MASK_DIR      0x00000100UL
#define DC_MASK_MSG      0x01FFFE00UL
#define DC_MASK_RESERVED 0x01E00000UL
#define DC_MASK_CLASS    0x1E000000UL

// Broadcast node address
#define DC_ADDRESS_BROADCAST = 0xFF

// Invalid message identifier
#define DC_MSG_INVALID   0xF0000000UL

// Message direction
#define DC_MSG_DIR_TO    0x00   // Message is being sent TO the addressed device
#define DC_MSG_DIR_FROM  0x01   // Message is being received FROM the addressed device

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

/**
 * @brief DC_GetClassFromID - Extract the message class from the CAN ID
 * @param id - 29-bit CAN ID
 * @return message class
 */
uint8_t DC_GetClassFromID(uint32_t id);

/**
 * @brief DC_GetMessageFromID - Extract the message identifier from the CAN ID
 * @param id - 29-bit CAN ID
 * @return message ID
 */
uint16_t DC_GetMessageFromID(uint32_t id);

/**
 * @brief DC_GetAddressFromID - Extract message address from the CAN ID
 * @param id - 29-bit CAN ID
 * @return message address
 */
uint8_t DC_GetAddressFromID(uint32_t id);

/**
 * @brief DC_GetDirectionFromID - Extract message direction from the CAN ID
 * @param id - 29-bit CAN ID
 * @return message direction bit
 */
uint8_t DC_GetDirectionFromID(uint32_t id);

/**
 * @brief DC_EncodeID - Encode a DroneCAN Message ID
 * @param msgClass - message class
 * @param msgId - message ID
 * @param msgDir - message direction
 * @param msgAddress - message address
 * @return
 */
uint32_t DC_EncodeID(uint8_t msgClass, uint16_t msgId, uint8_t msgDir, uint8_t msgAddress);

/**
 * @brief DC_DecodeID - Decode a DroneCAN message ID
 * @param msgClass - message class
 * @param msgId - message ID
 * @param msgDir - message direction
 * @param msgAddress - message address
 */
void DC_DecodeID(uint32_t id, uint8_t* msgClass, uint16_t* msgId, uint8_t* msgDir, uint8_t* msgAddress);

/**
 * @brief DC_SetAddress overrides the address field of a CAN ID
 * @param id - pointer to the CAN ID
 * @param address - address value to be written
 */
void DC_SetAddress(uint32_t* id, uint8_t address);

/**
 * @brief DC_SetDirection overrides the direction bit of a CAN ID
 * @param id - pointer to the CAN ID
 * @param direction - address value to be written
 */
void DC_SetDirection(uint32_t* id, uint8_t direction);

#ifdef __cplusplus
}
#endif

#endif //_DC_PKT_H_
