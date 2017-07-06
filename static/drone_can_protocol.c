/*
 * This program source code file is part of DroneCAN protocol specification
 *
 * Website: www.dronecan.org
 * GitHub: www.github.com/dronecan
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
#include "drone_can_protocol.h"

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

void finishDC_ClassPacket(DC_Packet_t *pkt, int size, uint32_t id, uint8_t msgClass)
{
    id = DC_EncodeID(msgClass,
                     id,
                     0x00,
                     0x00);

    finishDroneCANPacket(pkt, size, id);
}

uint32_t getDC_ClassID(const DC_Packet_t *pkt, uint8_t msgClass)
{
    if (DC_GetClassFromID(pkt->id) != msgClass)
    {
        return DC_MSG_INVALID;
    }

    return DC_GetMessageFromID(pkt->id);
}

const char* DroneCAN_GetMessageLabel(uint32_t id)
{
    uint16_t msgClass = DC_GetClassFromID(id);
    uint8_t  msgId = DC_GetMessageFromID(id);

    switch (msgClass)
    {
    default:
        return "Unknown msg class";
    case DC_MSG_CLASS_AUTOPILOT:
        //TODO
        return "";
    case DC_MSG_CLASS_COMMAND:
        return DroneCAN_CommandMessages_EnumLabel(msgId);
    case DC_MSG_CLASS_TELEMETRY:
        return DroneCAN_TelemetryMessages_EnumLabel(msgId);
    case DC_MSG_CLASS_SYSTEM:
        return DroneCAN_SystemMessages_EnumLabel(msgId);
    case DC_MSG_CLASS_DEBUG:
        //TODO
        return "";
    case DC_MSG_CLASS_BLOCK:
        //TODO
        return "";
    }
}


/* Glue functions for the Autopilot message class */

inline uint8_t* getDC_AutopilotPacketData(DC_Packet_t *pkt)
{
    return getDroneCANPacketData(pkt);
}

inline const uint8_t* getDC_AutopilotPacketDataConst(const DC_Packet_t *pkt)
{
    return getDroneCANPacketDataConst(pkt);
}

inline void finishDC_AutopilotPacket(DC_Packet_t *pkt, int size, uint32_t packetID)
{
    finishDC_ClassPacket(pkt, size, packetID, DC_MSG_CLASS_AUTOPILOT);
}

inline int getDC_AutopilotPacketSize(const DC_Packet_t *pkt)
{
    return getDroneCANPacketSize(pkt);
}

inline uint32_t getDC_AutopilotPacketID(const DC_Packet_t *pkt)
{
    return getDC_ClassID(pkt, DC_MSG_CLASS_AUTOPILOT);
}


/* Glue functions for the Command message class */

inline uint8_t* getDC_CommandPacketData(DC_Packet_t *pkt)
{
    return getDroneCANPacketData(pkt);
}

inline const uint8_t* getDC_CommandPacketDataConst(const DC_Packet_t *pkt)
{
    return getDroneCANPacketDataConst(pkt);
}

inline void finishDC_CommandPacket(DC_Packet_t *pkt, int size, uint32_t packetID)
{
    finishDC_ClassPacket(pkt, size, packetID, DC_MSG_CLASS_COMMAND);
}

inline int getDC_CommandPacketSize(const DC_Packet_t *pkt)
{
    return getDroneCANPacketSize(pkt);
}

inline uint32_t getDC_CommandPacketID(const DC_Packet_t *pkt)
{
    return getDC_ClassID(pkt, DC_MSG_CLASS_COMMAND);
}

/* Glue functions for the Telemetry message class */

inline uint8_t* getDC_TelemetryPacketData(DC_Packet_t *pkt)
{
    return getDroneCANPacketData(pkt);
}

inline const uint8_t* getDC_TelemetryPacketDataConst(const DC_Packet_t *pkt)
{
    return getDroneCANPacketDataConst(pkt);
}

inline void finishDC_TelemetryPacket(DC_Packet_t *pkt, int size, uint32_t packetID)
{
    finishDC_ClassPacket(pkt, size, packetID, DC_MSG_CLASS_TELEMETRY);
}

inline int getDC_TelemetryPacketSize(const DC_Packet_t *pkt)
{
    return getDroneCANPacketSize(pkt);
}

inline uint32_t getDC_TelemetryPacketID(const DC_Packet_t *pkt)
{
    return getDC_ClassID(pkt, DC_MSG_CLASS_TELEMETRY);
}

/* Glue functions for the System message class */

inline uint8_t* getDC_SystemPacketData(DC_Packet_t *pkt)
{
    return getDroneCANPacketData(pkt);
}

inline const uint8_t* getDC_SystemPacketDataConst(const DC_Packet_t *pkt)
{
    return getDroneCANPacketDataConst(pkt);
}

inline void finishDC_SystemPacket(DC_Packet_t *pkt, int size, uint32_t packetID)
{
    finishDC_ClassPacket(pkt, size, packetID, DC_MSG_CLASS_SYSTEM);
}

inline int getDC_SystemPacketSize(const DC_Packet_t *pkt)
{
    return getDroneCANPacketSize(pkt);
}

inline uint32_t getDC_SystemPacketID(const DC_Packet_t *pkt)
{
    return getDC_ClassID(pkt, DC_MSG_CLASS_SYSTEM);
}

/* Glue functions for the Block message class */

inline uint8_t* getDC_BlockPacketData(DC_Packet_t *pkt)
{
    return getDroneCANPacketData(pkt);
}

inline const uint8_t* getDC_BlockPacketDataConst(const DC_Packet_t *pkt)
{
    return getDroneCANPacketDataConst(pkt);
}

inline void finishDC_BlockPacket(DC_Packet_t *pkt, int size, uint32_t packetID)
{
    finishDC_ClassPacket(pkt, size, packetID, DC_MSG_CLASS_BLOCK);
}

inline int getDC_BlockPacketSize(const DC_Packet_t *pkt)
{
    return getDroneCANPacketSize(pkt);
}

inline uint32_t getDC_BlockPacketID(const DC_Packet_t *pkt)
{
    return getDC_ClassID(pkt, DC_MSG_CLASS_BLOCK);
}
