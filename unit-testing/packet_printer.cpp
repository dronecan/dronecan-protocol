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

#include "packet_printer.h"
#include "drone_can_protocol.h"

void PrintPacket(DC_Packet_t& pkt, bool extended)
{
    uint16_t msgId = DC_GetMessageFromID(pkt.id);
    uint8_t msgClass = DC_GetClassFromID(pkt.id);

    printf("Packet 0x%08x -> ", pkt.id);

    for (int idx=0; idx<pkt.length; idx++)
    {
        printf  ("%02x ", pkt.data[idx]);
    }

    printf("\n");

    if (extended)
    {
        printf("Class: %s (%u)\n", DC_GetClassName(msgClass), msgClass);

        printf("Msg: %u - %s\n", msgId, DroneCAN_GetMessageLabel(pkt.id));

        printf("Address: %u\n", DC_GetAddressFromID(pkt.id));
        printf("Direction: %s\n", DC_GetDirectionFromID(pkt.id) == DC_MSG_DIR_TO ? "to" : "from");
    }
}
