// fieldencode.c was generated by ProtoGen version 2.2.d

#include "fieldencode.h"


/*!
* Encode a null terminated string on a byte stream
* \param string is the null termianted string to encode
* \param bytes is a pointer to the byte stream which receives the encoded data.
* \param index gives the location of the first byte in the byte stream, and
*        will be incremented by the number of bytes encoded when this function
*        is complete.
* \param maxLength is the maximum number of bytes that can be encoded. A null
*        terminator is always included in the encoding.
* \param fixedLength should be 1 to force the number of bytes encoded to be
*        exactly equal to maxLength.
*/
void stringToBytes(const char* string, uint8_t* bytes, int* index, int maxLength, int fixedLength)
{
    int i;

    // increment byte pointer for starting point
    bytes += (*index);

    // Reserve the last byte for null termination
    for(i = 0; i < maxLength - 1; i++)
    {
        if(string[i] == 0)
            break;
        else
            bytes[i] = (uint8_t)string[i];
    }

    // Make sure last byte has null termination
    bytes[i++] = 0;

    if(fixedLength)
    {
        // Finish with null bytes
        for(; i < maxLength; i++)
            bytes[i] = 0;
    }

    // Return for the number of bytes we encoded
    (*index) += i;

}// stringToBytes


/*!
 * Copy an array of bytes to a byte stream without changing the order.
 * \param data is the array of bytes to copy.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by num when this function is complete.
 * \param num is the number of bytes to copy
 */
void bytesToBeBytes(const uint8_t* data, uint8_t* bytes, int* index, int num)
{
    // increment byte pointer for starting point
    bytes += (*index);

    // Increment byte index to indicate number of bytes copied
    (*index) += num;

    // Copy the bytes without changing the order
    while(num > 0)
    {
        *(bytes++) = *(data++);
        num--;
    }

}// bytesToBeBytes


/*!
 * Copy an array of bytes to a byte stream while reversing the order.
 * \param data is the array of bytes to copy.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by num when this function is complete.
 * \param num is the number of bytes to copy
 */
void bytesToLeBytes(const uint8_t* data, uint8_t* bytes, int* index, int num)
{
    // increment byte pointer for starting point
    bytes += (*index);

    // Increment byte index to indicate number of bytes copied
    (*index) += num;

    // To encode as "little endian bytes", (a nonsensical statement), reverse the byte order
    bytes += (num - 1);

    // Copy the bytes, reversing the order
    while(num > 0)
    {
        *(bytes--) = *(data++);
        num--;
    }

}// bytesToLeBytes

/*!
 * Encode a 4 byte float on a big endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 */
void float32ToBeBytes(float number, uint8_t* bytes, int* index)
{
    union
    {
        float floatValue;
        uint32_t integerValue;
    }field;

    field.floatValue = number;

    uint32ToBeBytes(field.integerValue, bytes, index);
}


/*!
 * Encode a 4 byte float on a little endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 */
void float32ToLeBytes(float number, uint8_t* bytes, int* index)
{
    union
    {
        float floatValue;
        uint32_t integerValue;
    }field;

    field.floatValue = number;

    uint32ToLeBytes(field.integerValue, bytes, index);
}


/*!
 * Encode a unsigned 4 byte integer on a big endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 */
void uint32ToBeBytes(uint32_t number, uint8_t* bytes, int* index)
{
    // increment byte pointer for starting point
    bytes += (*index) + 3;

    *(bytes--) = (uint8_t)(number);
    number = number >> 8;
    *(bytes--) = (uint8_t)(number);
    number = number >> 8;
    *(bytes--) = (uint8_t)(number);
    number = number >> 8;
    *bytes = (uint8_t)(number);

    (*index) += 4;
}


/*!
 * Encode a unsigned 4 byte integer on a little endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 */
void uint32ToLeBytes(uint32_t number, uint8_t* bytes, int* index)
{
    // increment byte pointer for starting point
    bytes += (*index);

    *(bytes++) = (uint8_t)(number);
    number = number >> 8;
    *(bytes++) = (uint8_t)(number);
    number = number >> 8;
    *(bytes++) = (uint8_t)(number);
    number = number >> 8;
    *bytes = (uint8_t)(number);

    (*index) += 4;
}


/*!
 * Encode a signed 4 byte integer on a big endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 */
void int32ToBeBytes(int32_t number, uint8_t* bytes, int* index)
{
    // increment byte pointer for starting point
    bytes += (*index) + 3;

    *(bytes--) = (uint8_t)(number);
    number = number >> 8;
    *(bytes--) = (uint8_t)(number);
    number = number >> 8;
    *(bytes--) = (uint8_t)(number);
    number = number >> 8;
    *bytes = (uint8_t)(number);

    (*index) += 4;
}


/*!
 * Encode a signed 4 byte integer on a little endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 */
void int32ToLeBytes(int32_t number, uint8_t* bytes, int* index)
{
    // increment byte pointer for starting point
    bytes += (*index);

    *(bytes++) = (uint8_t)(number);
    number = number >> 8;
    *(bytes++) = (uint8_t)(number);
    number = number >> 8;
    *(bytes++) = (uint8_t)(number);
    number = number >> 8;
    *bytes = (uint8_t)(number);

    (*index) += 4;
}


/*!
 * Encode a unsigned 3 byte integer on a big endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 */
void uint24ToBeBytes(uint32_t number, uint8_t* bytes, int* index)
{
    // increment byte pointer for starting point
    bytes += (*index) + 2;

    *(bytes--) = (uint8_t)(number);
    number = number >> 8;
    *(bytes--) = (uint8_t)(number);
    number = number >> 8;
    *bytes = (uint8_t)(number);

    (*index) += 3;
}


/*!
 * Encode a unsigned 3 byte integer on a little endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 */
void uint24ToLeBytes(uint32_t number, uint8_t* bytes, int* index)
{
    // increment byte pointer for starting point
    bytes += (*index);

    *(bytes++) = (uint8_t)(number);
    number = number >> 8;
    *(bytes++) = (uint8_t)(number);
    number = number >> 8;
    *bytes = (uint8_t)(number);

    (*index) += 3;
}


/*!
 * Encode a signed 3 byte integer on a big endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 */
void int24ToBeBytes(int32_t number, uint8_t* bytes, int* index)
{
    // increment byte pointer for starting point
    bytes += (*index) + 2;

    *(bytes--) = (uint8_t)(number);
    number = number >> 8;
    *(bytes--) = (uint8_t)(number);
    number = number >> 8;
    *bytes = (uint8_t)(number);

    (*index) += 3;
}


/*!
 * Encode a signed 3 byte integer on a little endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 */
void int24ToLeBytes(int32_t number, uint8_t* bytes, int* index)
{
    // increment byte pointer for starting point
    bytes += (*index);

    *(bytes++) = (uint8_t)(number);
    number = number >> 8;
    *(bytes++) = (uint8_t)(number);
    number = number >> 8;
    *bytes = (uint8_t)(number);

    (*index) += 3;
}


/*!
 * Encode a unsigned 2 byte integer on a big endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 */
void uint16ToBeBytes(uint16_t number, uint8_t* bytes, int* index)
{
    // increment byte pointer for starting point
    bytes += (*index) + 1;

    *(bytes--) = (uint8_t)(number);
    number = number >> 8;
    *bytes = (uint8_t)(number);

    (*index) += 2;
}


/*!
 * Encode a unsigned 2 byte integer on a little endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 */
void uint16ToLeBytes(uint16_t number, uint8_t* bytes, int* index)
{
    // increment byte pointer for starting point
    bytes += (*index);

    *(bytes++) = (uint8_t)(number);
    number = number >> 8;
    *bytes = (uint8_t)(number);

    (*index) += 2;
}


/*!
 * Encode a signed 2 byte integer on a big endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 */
void int16ToBeBytes(int16_t number, uint8_t* bytes, int* index)
{
    // increment byte pointer for starting point
    bytes += (*index) + 1;

    *(bytes--) = (uint8_t)(number);
    number = number >> 8;
    *bytes = (uint8_t)(number);

    (*index) += 2;
}


/*!
 * Encode a signed 2 byte integer on a little endian byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 */
void int16ToLeBytes(int16_t number, uint8_t* bytes, int* index)
{
    // increment byte pointer for starting point
    bytes += (*index);

    *(bytes++) = (uint8_t)(number);
    number = number >> 8;
    *bytes = (uint8_t)(number);

    (*index) += 2;
}


/*!
 * Encode a unsigned 1 byte integer on a byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 1 when this function is complete.
 */
void uint8ToBytes(uint8_t number, uint8_t* bytes, int* index)
{
    bytes[(*index)++] = (uint8_t)(number);
}


/*!
 * Encode a signed 1 byte integer on a byte stream.
 * \param number is the value to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 1 when this function is complete.
 */
void int8ToBytes(int8_t number, uint8_t* bytes, int* index)
{
    bytes[(*index)++] = (uint8_t)(number);
}


// end of fieldencode.c
