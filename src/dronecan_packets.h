// dronecan_packets.h was generated by ProtoGen version 2.19.a

/**

Copyright (c) 2020 DroneCAN

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

**/

#ifndef _DRONECAN_PACKETS_H
#define _DRONECAN_PACKETS_H

// C++ compilers: don't mangle us
#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    PKT_DC_PARAM_REQUEST = 0xEF00,//!< Request device parameter
    PKT_DC_PARAM_INFO,           //!< Parameter description
    PKT_DC_PARAM_VALUE           //!< Parameter value
} DroneCAN_Param_Packets;

//! \return the label of a 'DroneCAN_Param_Packets' enum entry, based on its value
const char* DroneCAN_Param_Packets_EnumLabel(int value);

//! \return the title of a 'DroneCAN_Param_Packets' enum entry, based on its value
const char* DroneCAN_Param_Packets_EnumTitle(int value);

typedef enum
{
    PKT_DC_SYS_STATUS = 0xF000,      //!< Device status information
    PKT_DC_SYS_UID = 0xF100,         //!< Unique Identifer for DroneCAN node
    PKT_DC_SYS_MANF_STRING = 0xF105, //!< Manufacturer device identifier string
    PKT_DC_SYS_USER_STRING,          //!< User device identifier string
    PKT_DC_SYS_FW_VERSION = 0xF110,  //!< Firmware version information
    PKT_DC_SYS_FW_DATE,              //!< Firmware date information
    PKT_DC_SYS_FW_SETTINGS,          //!< User-configurable settings information
    PKT_DC_SYS_HW_INFO = 0xF115,     //!< Hardware information
    PKT_DC_SYS_PROTOCOL_INFO = 0xF11A //!< DroneCAN protocol information
} DroneCAN_System_Packets;

//! \return the label of a 'DroneCAN_System_Packets' enum entry, based on its value
const char* DroneCAN_System_Packets_EnumLabel(int value);

//! \return the title of a 'DroneCAN_System_Packets' enum entry, based on its value
const char* DroneCAN_System_Packets_EnumTitle(int value);

#ifdef __cplusplus
}
#endif
#endif
