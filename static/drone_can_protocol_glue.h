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

#ifndef _DC_PROTOCOL_GLUE_H_
#define _DC_PROTOCOL_GLUE_H_

#include "drone_can_packet.h"
#include "drone_can_classes.h"

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

/*
 * Glue functions for Autopilot message class
 */

void finishDC_AutopilotPacket(DC_Packet_t* pkt, int size, uint32_t id);
uint32_t getDC_AutopilotPacketID(const DC_Packet_t* pkt);
#define getDC_AutopilotPacketData(pkt) getDroneCANPacketData(pkt)
#define getDC_AutopilotPacketDataConst(pkt) getDroneCANPacketDataConst(pkt)
#define getDC_AutopilotPacketSize(pkt) getDroneCANPacketSize(pkt)


/*
 * Glue functions for Command message class
 */

void finishDC_CommandPacket(DC_Packet_t* pkt, int size, uint32_t id);
uint32_t getDC_CommandPacketID(const DC_Packet_t* pkt);
#define getDC_CommandPacketData(pkt) (getDroneCANPacketData(pkt))
#define getDC_CommandPacketDataConst(pkt) (getDroneCANPacketDataConst(pkt))
#define getDC_CommandPacketSize(pkt) (getDroneCANPacketSize(pkt))


/*
 * Glue functions for Telemetry message class
 */

void finishDC_TelemetryPacket(DC_Packet_t* pkt, int size, uint32_t id);
uint32_t getDC_TelemetryPacketID(const DC_Packet_t* pkt);
#define getDC_TelemetryPacketData(pkt) getDroneCANPacketData(pkt)
#define getDC_TelemetryPacketDataConst(pkt) getDroneCANPacketDataConst(pkt)
#define getDC_TelemetryPacketSize(pkt) getDroneCANPacketSize(pkt)

/*
 * Glue functions for System message class
 */

void finishDC_SystemPacket(DC_Packet_t* pkt, int size, uint32_t id);
uint32_t getDC_SystemPacketID(const DC_Packet_t* pkt);
#define getDC_SystemPacketData(pkt) getDroneCANPacketData(pkt)
#define getDC_SystemPacketDataConst(pkt) getDroneCANPacketDataConst(pkt)
#define getDC_SystemPacketSize(pkt) getDroneCANPacketSize(pkt)

/*
 * Glue functions for Block message class
 */

void finishDC_BlockPacket(DC_Packet_t* pkt, int size, uint32_t id);
uint32_t getDC_BlockPacketID(const DC_Packet_t* pkt);
#define getDC_BlockPacketData(pkt) getDroneCANPacketData(pkt)
#define getDC_BlockPacketDataConst(pkt) getDroneCANPacketDataConst(pkt)
#define getDC_BlockPacketSize(pkt) getDroneCANPacketSize(pkt)

#ifdef __cplusplus
}
#endif

#endif // _DC_PROTOCOL_GLUE_H_
