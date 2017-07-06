// dc_dev_info.c was generated by ProtoGen version 2.2.d

#include "dc_dev_info.h"
#include "fielddecode.h"
#include "fieldencode.h"
#include "scaleddecode.h"
#include "scaledencode.h"

/*!
 * \brief Encode a DC_Sys_UID_t structure into a byte array
 *
 * Unique Identifier for device
 * \param data points to the byte array to add encoded data to
 * \param bytecount points to the starting location in the byte array, and will be incremented by the number of encoded bytes.
 * \param user is the data to encode in the byte array
 */
void encodeDC_Sys_UID_t(uint8_t* data, int* bytecount, const DC_Sys_UID_t* user)
{
    int byteindex = *bytecount;

    // Vendor ID
    uint16ToBeBytes((uint16_t)user->vid, data, &byteindex);

    // Product ID
    uint16ToBeBytes((uint16_t)user->pid, data, &byteindex);

    // Device serial number
    uint24ToBeBytes((uint32_t)user->serial, data, &byteindex);

    *bytecount = byteindex;

}// encodeDC_Sys_UID_t

/*!
 * \brief Decode a DC_Sys_UID_t structure from a byte array
 *
 * Unique Identifier for device
 * \param data points to the byte array to decoded data from
 * \param bytecount points to the starting location in the byte array, and will be incremented by the number of bytes decoded
 * \param user is the data to decode from the byte array
 * \return 1 if the data are decoded, else 0. If 0 is returned bytecount will not be updated.
 */
int decodeDC_Sys_UID_t(const uint8_t* data, int* bytecount, DC_Sys_UID_t* user)
{
    int byteindex = *bytecount;

    // Vendor ID
    user->vid = (uint16_t)uint16FromBeBytes(data, &byteindex);

    // Product ID
    user->pid = (uint16_t)uint16FromBeBytes(data, &byteindex);

    // Device serial number
    user->serial = (uint32_t)uint24FromBeBytes(data, &byteindex);

    *bytecount = byteindex;

    return 1;

}// decodeDC_Sys_UID_t

/*!
 * \brief Encode a DC_Sys_DevFwVersion_t structure into a byte array
 *
 * Device firmware version information
 * \param data points to the byte array to add encoded data to
 * \param bytecount points to the starting location in the byte array, and will be incremented by the number of encoded bytes.
 * \param user is the data to encode in the byte array
 */
void encodeDC_Sys_DevFwVersion_t(uint8_t* data, int* bytecount, const DC_Sys_DevFwVersion_t* user)
{
    int byteindex = *bytecount;

    // Major release number
    uint8ToBytes((uint8_t)user->major, data, &byteindex);

    // Minor release number
    uint8ToBytes((uint8_t)user->minor, data, &byteindex);

    // Sub release number
    uint8ToBytes((uint8_t)user->sub, data, &byteindex);

    *bytecount = byteindex;

}// encodeDC_Sys_DevFwVersion_t

/*!
 * \brief Decode a DC_Sys_DevFwVersion_t structure from a byte array
 *
 * Device firmware version information
 * \param data points to the byte array to decoded data from
 * \param bytecount points to the starting location in the byte array, and will be incremented by the number of bytes decoded
 * \param user is the data to decode from the byte array
 * \return 1 if the data are decoded, else 0. If 0 is returned bytecount will not be updated.
 */
int decodeDC_Sys_DevFwVersion_t(const uint8_t* data, int* bytecount, DC_Sys_DevFwVersion_t* user)
{
    int byteindex = *bytecount;

    // Major release number
    user->major = (uint8_t)uint8FromBytes(data, &byteindex);

    // Minor release number
    user->minor = (uint8_t)uint8FromBytes(data, &byteindex);

    // Sub release number
    user->sub = (uint8_t)uint8FromBytes(data, &byteindex);

    *bytecount = byteindex;

    return 1;

}// decodeDC_Sys_DevFwVersion_t

/*!
 * \brief Encode a DC_Sys_DevFwDate_t structure into a byte array
 *
 * Device firmware release date information
 * \param data points to the byte array to add encoded data to
 * \param bytecount points to the starting location in the byte array, and will be incremented by the number of encoded bytes.
 * \param user is the data to encode in the byte array
 */
void encodeDC_Sys_DevFwDate_t(uint8_t* data, int* bytecount, const DC_Sys_DevFwDate_t* user)
{
    int byteindex = *bytecount;

    // Year of release
    uint16ToBeBytes((uint16_t)user->year, data, &byteindex);

    // Month of release
    uint8ToBytes((uint8_t)user->month, data, &byteindex);

    // Day of release
    uint8ToBytes((uint8_t)user->day, data, &byteindex);

    *bytecount = byteindex;

}// encodeDC_Sys_DevFwDate_t

/*!
 * \brief Decode a DC_Sys_DevFwDate_t structure from a byte array
 *
 * Device firmware release date information
 * \param data points to the byte array to decoded data from
 * \param bytecount points to the starting location in the byte array, and will be incremented by the number of bytes decoded
 * \param user is the data to decode from the byte array
 * \return 1 if the data are decoded, else 0. If 0 is returned bytecount will not be updated.
 */
int decodeDC_Sys_DevFwDate_t(const uint8_t* data, int* bytecount, DC_Sys_DevFwDate_t* user)
{
    int byteindex = *bytecount;

    // Year of release
    user->year = (uint16_t)uint16FromBeBytes(data, &byteindex);

    // Month of release
    user->month = (uint8_t)uint8FromBytes(data, &byteindex);

    // Day of release
    user->day = (uint8_t)uint8FromBytes(data, &byteindex);

    *bytecount = byteindex;

    return 1;

}// decodeDC_Sys_DevFwDate_t

// end of dc_dev_info.c