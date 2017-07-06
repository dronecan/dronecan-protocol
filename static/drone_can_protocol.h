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

#ifndef _DC_PROTOCOL_H_
#define _DC_PROTOCOL_H_

#include "drone_can_packet.h"
#include "drone_can_classes.h"

#include "DC_AutopilotProtocol.h"
#include "DC_CommandProtocol.h"
#include "DC_TelemetryProtocol.h"
#include "DC_SystemProtocol.h"
#include "DC_BlockProtocol.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Top-level DroneCAN Protogen glue functions
 */
void finishDroneCANPacket(DC_Packet_t* pkt, int size, uint32_t id);
uint32_t getDroneCANPacketID(const DC_Packet_t* pkt);
uint8_t* getDroneCANPacketData(DC_Packet_t* pkt);
const uint8_t* getDroneCANPacketDataConst(const DC_Packet_t* pkt);
int getDroneCANPacketSize(const DC_Packet_t* pkt);

/**
 * @brief finishDC_ClassPacket - Finish a DroneCAN packet and encode for a particular message class
 * @param pkt - pointer to the packet
 * @param size - size of packet payload
 * @param id - message ID
 * @param msgClass - message class
 */
void finishDC_ClassPacket(DC_Packet_t* pkt, int size, uint32_t id, uint8_t msgClass);

/**
 * @brief getDC_ClassID - Return the packet ID, assuming a particular message class
 * @param pkt - pointer to the packet
 * @param msgClass - message class
 * @return message ID if the message is in the given class else DC_MSG_INVALID
 */
uint32_t getDC_ClassID(const DC_Packet_t* pkt, uint8_t msgClass);


/**
 * @brief DroneCAN_GetMessageLabel - return human-readable string associated with a given CAN ID
 * @param id - CAN ID
 * @return message string if ID is valid else empty string
 */
const char* DroneCAN_GetMessageLabel(uint32_t id);

#ifdef __cplusplus
}
#endif

#endif // _DC_PROTOCOL_H_
