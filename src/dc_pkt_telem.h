// dc_pkt_telem.h was generated by ProtoGen version 2.2.d

#ifndef _DC_PKT_TELEM_H
#define _DC_PKT_TELEM_H

// C++ compilers: don't mangle us
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \file
 */

#include "DC_TelemetryProtocol.h"

typedef struct
{
    unsigned mode : 4;     //!< Device mode
    unsigned warning : 1;  //!< Device warning
    unsigned error : 1;    //!< Device error
    unsigned critical : 1; //!< Device critical
    unsigned fatal : 1;    //!< Device fatal
}DC_Telemetry_DeviceStatusField_t;

#define getMinLengthOfDC_Telemetry_DeviceStatusField_t() (1)

//! Encode a DC_Telemetry_DeviceStatusField_t structure into a byte array
void encodeDC_Telemetry_DeviceStatusField_t(uint8_t* data, int* bytecount, const DC_Telemetry_DeviceStatusField_t* user);

//! Decode a DC_Telemetry_DeviceStatusField_t structure from a byte array
int decodeDC_Telemetry_DeviceStatusField_t(const uint8_t* data, int* bytecount, DC_Telemetry_DeviceStatusField_t* user);

/*!
 * Device status
 */
typedef struct
{
    DC_Telemetry_DeviceStatusField_t status; //!< Device status information
    uint32_t                         uptime; //!< Device uptime (s)
}DC_Telemetry_DeviceStatus_t;

#define getMinLengthOfDC_Telemetry_DeviceStatus_t() (5)

//! Create the DC_Telemetry_DeviceStatus packet
void encodeDC_Telemetry_DeviceStatusPacketStructure(DC_Packet_t* pkt, const DC_Telemetry_DeviceStatus_t* user);

//! Decode the DC_Telemetry_DeviceStatus packet
int decodeDC_Telemetry_DeviceStatusPacketStructure(const DC_Packet_t* pkt, DC_Telemetry_DeviceStatus_t* user);

//! return the packet ID for the DC_Telemetry_DeviceStatus packet
#define getDC_Telemetry_DeviceStatusPacketID() (DC_PKT_TELEM_STATUS)

//! return the minimum data length for the DC_Telemetry_DeviceStatus packet
#define getDC_Telemetry_DeviceStatusMinDataLength() (5)

//! return the maximum data length for the DC_Telemetry_DeviceStatus packet
#define getDC_Telemetry_DeviceStatusMaxDataLength() (5)

#ifdef __cplusplus
}
#endif
#endif