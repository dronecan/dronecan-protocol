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

#include "drone_can_classes.h"

const char* DC_GetClassName(uint8_t classId)
{
    switch (classId)
    {
    case DC_MSG_CLASS_AUTOPILOT:
        return "Autopilot";
    case DC_MSG_CLASS_COMMAND:
        return "Command";
    case DC_MSG_CLASS_TELEMETRY:
        return "Telemetry";
    case DC_MSG_CLASS_SYSTEM:
        return "System";
    case DC_MSG_CLASS_BLOCK:
        return "Block";
    case DC_MSG_CLASS_DEBUG:
        return "Debug";
    default:
        return "Unknown";
    }
}
