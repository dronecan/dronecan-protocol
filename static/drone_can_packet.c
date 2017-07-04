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

#include "drone_can_packet.h"

uint8_t DC_GetClassFromID(uint32_t id)
{
    return (uint8_t) ((id & DC_MASK_CLASS) >> 25);
}

uint16_t DC_GetMessageFromID(uint32_t id)
{
    return (uint16_t) ((id & DC_MASK_MSG) >> 9);
}

uint8_t DC_GetAddressFromID(uint32_t id)
{
    return (uint8_t) (id & DC_MASK_ADDRESS);
}

uint8_t DC_GetDirectionFromID(uint32_t id)
{
    return (uint8_t) ((id & DC_MASK_DIR) >> 8);
}

uint32_t DC_EncodeID(uint8_t msgClass, uint16_t msgId, uint8_t msgDir, uint8_t msgAddress)
{
    uint32_t id = 0x00;

    // Encode message class
    id |= (msgClass & 0x0F) << 25;

    // Encode message ID
    id |= (msgId & 0xFFFF) << 9;

    // Encode message direction
    id |= (msgDir & 0x01) << 8;

    // Encode message address
    id |= msgAddress;

    return id;
}

void DC_DecodeID(uint32_t id, uint8_t *msgClass, uint16_t *msgId, uint8_t *msgDir, uint8_t *msgAddress)
{
    *msgClass = (uint8_t) ((id & DC_MASK_CLASS) >> 25);
    *msgId = (uint16_t) ((id & DC_MASK_MSG)) >> 9;
    *msgDir = (uint8_t) ((id & DC_MASK_DIR)) >> 8;
    *msgAddress = (uint8_t) (id & DC_MASK_ADDRESS);
}

void DC_SetAddress(uint32_t *id, uint8_t address)
{
    *id &= ~DC_MASK_ADDRESS;
    *id |= address;
}

void DC_SetDirection(uint32_t *id, uint8_t direction)
{
    *id &= ~DC_MASK_DIR;
    *id |= (direction & 0x01) << 8;
}
