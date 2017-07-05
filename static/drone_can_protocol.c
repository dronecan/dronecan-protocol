/*
 * This program source code file is part of DroneCAN protocol specification
 *
 * Copyright (C) 2017 Currawong Engineering Pty Ltd, see AUTHORS.txt for contributors.
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

void finishDroneCANPacket(DC_Packet_t* pkt, int size, uint32_t id)
{
    pkt->length = (uint8_t) size;
    pkt->id = id;
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
    return pkt->id;
}

/* Autopilot messages */
void finishDC_CommandPacket(DC_Packet_t *pkt, int size, uint32_t id)
{
    id = DC_EncodeID(DC_MSG_CLASS_COMMAND,
                     id,
                     0x00,
                     0x00);

    finishDroneCANPacket(pkt, size, id);
}

uint32_t getDC_CommandPacketID(const DC_Packet_t *pkt)
{
    if (DC_GetClassFromID(pkt->id) != DC_MSG_CLASS_COMMAND)
    {
        return DC_MSG_INVALID;
    }

    return DC_GetMessageFromID(pkt->id);
}

/* System Messages */
void finishDC_SystemPacket(DC_Packet_t *pkt, int size, uint32_t id)
{
    id = DC_EncodeID(DC_MSG_CLASS_SYSTEM,
                     id,
                     0x00,
                     0x00);

    finishDroneCANPacket(pkt, size, id);
}

uint32_t getDC_SystemPacketID(const DC_Packet_t *pkt)
{
    if (DC_GetClassFromID(pkt->id) != DC_MSG_CLASS_SYSTEM)
    {
        return DC_MSG_INVALID;
    }

    return DC_GetMessageFromID(pkt->id);
}
