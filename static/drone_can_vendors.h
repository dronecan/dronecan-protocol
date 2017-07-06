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

#ifndef _DRONE_CAN_VENDORS_H_
#define _DRONE_CAN_VENDORS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief The DroneCANVendors enum defines unique vendor ID values
 *
 * A conformant DroneCAN device requires a unique vendor ID for device enumeration.
 *
 * This enumeration may contain 'secret' vendor IDs for vendors that
 * do not wish to identify themselves in the protocol specification.
 */
enum DroneCANVendors
{
    // Currawong Engineering Pty Ltd
    // www.currawongeng.com
    DC_VENDOR_CURRAWONG_ENGINEERING = 0xCECE,
};

/**
 * @brief DroneCAN_VendorString returns a human-readable vendor name
 * @param vendorId - unique vendor ID
 * @return - vendor name (string)
 */
const char* DroneCAN_VendorString(uint16_t vendorId);

#ifdef __cplusplus
}
#endif

#endif // _DRONE_CAN_VENDORS_H_
