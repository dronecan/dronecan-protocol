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

#include "drone_can_protocol_glue.h"

// Magic number class values for various message classes
const uint32_t _CLASS_AUTOPILOT     = (uint32_t) DC_MSG_CLASS_AUTOPILOT << 15;
const uint32_t _CLASS_COMMAND       = (uint32_t) DC_MSG_CLASS_COMMAND   << 15;
const uint32_t _CLASS_TELEMETRY     = (uint32_t) DC_MSG_CLASS_TELEMETRY << 15;
const uint32_t _CLASS_SYSTEM        = (uint32_t) DC_MSG_CLASS_SYSTEM    << 15;
const uint32_t _CLASS_BLOCK         = (uint32_t) DC_MSG_CLASS_BLOCK     << 15;
const uint32_t _CLASS_DEBUG         = (uint32_t) DC_MSG_CLASS_DEBUG     << 15;

// Mask for the 16-bits of allowable message range within each class
const uint32_t _MSG_MASK            = 0xFFFF;

// Mask for the 20-bit CLASS + MSG mask
const uint32_t _MSG_CLASS_MASK      = 0xFFFFF;

void finishDroneCANPacket(DC_Packet_t* pkt, int size, uint32_t id)
{
    // Ensure packet length is correct
    pkt->length = (uint8_t) size;

    // Left-shift ID by 9 bits to account for extra ID info
    // a) 8 bits of address information
    // b) 1 bit of direction information
    pkt->id = (id & _MSG_CLASS_MASK) << 9;
}

uint8_t* getDroneCANPacketData(DC_Packet_t* pkt)
{
  return (uint8_t*) &(pkt->data);
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
    // Right-shift the encoded ID value
    // This is to ignore the address and direction bits
    return (pkt->id >> 9) & _MSG_CLASS_MASK;
}

/* Autopilot messages */
void finishDC_CommandPacket(DC_Packet_t *pkt, int size, uint32_t id)
{
    id &= _MSG_MASK;
    id |= _CLASS_AUTOPILOT;

    finishDroneCANPacket(pkt, size, id);
}

uint32_t getDC_CommandPacketID(const DC_Packet_t *pkt)
{
    uint32_t id = getDroneCANPacketID(pkt);

    if ((id >> 16) != _CLASS_COMMAND)
    {
        return DC_MSG_INVALID;
    }

    // Return the message type with the class masked out
    return id & _MSG_MASK;
}
