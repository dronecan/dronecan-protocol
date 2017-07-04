// scaledencode.c was generated by ProtoGen version 2.2.d

#include "scaledencode.h"
#include "fieldencode.h"


/*!
 * Scale a float32 to the base integer type used for bitfield
 * \param value is the number to scale.
 * \param min is the minimum value that can be encoded.
 * \param scaler is multiplied by value to create the integer.
 * \return (value-min)*scaler.
 */
unsigned int float32ScaledToBitfield(float value, float min, float scaler)
{
    // Protect from underflow, overflow must be handled by caller
    if(value < min)
        return 0;

    // scale the number
    value = (value - min)*scaler;

    // account for fractional truncation
    return (unsigned int)(value + 0.5f);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 4 unsigned bytes in big
 * endian order.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \param min is the minimum value that can be encoded.
 * \param scaler is multiplied by value to create the encoded integer: encoded = (value-min)*scaler.
 */
void float32ScaledTo4UnsignedBeBytes(float value, uint8_t* bytes, int* index, float min, float scaler)
{
    // scale the number
    float scaledvalue = (float)((value - min)*scaler);
    uint32_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 4294967295uL)
        number = 4294967295uL;
    else if(scaledvalue <= 0)
        number = 0;
    else
        number = (uint32_t)(scaledvalue + 0.5f); // account for fractional truncation

    uint32ToBeBytes((uint32_t)number, bytes, index);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 4 unsigned bytes in
 * little endian order.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \param min is the minimum value that can be encoded.
 * \param scaler is multiplied by value to create the encoded integer: encoded = (value-min)*scaler.
 */
void float32ScaledTo4UnsignedLeBytes(float value, uint8_t* bytes, int* index, float min, float scaler)
{
    // scale the number
    float scaledvalue = (float)((value - min)*scaler);
    uint32_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 4294967295uL)
        number = 4294967295uL;
    else if(scaledvalue <= 0)
        number = 0;
    else
        number = (uint32_t)(scaledvalue + 0.5f); // account for fractional truncation

    uint32ToLeBytes((uint32_t)number, bytes, index);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 4 signed bytes in big
 * endian order.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \param scaler is multiplied by value to create the encoded integer: encoded = value*scaler.
 */
void float32ScaledTo4SignedBeBytes(float value, uint8_t* bytes, int* index, float scaler)
{
    // scale the number
    float scaledvalue = (float)(value*scaler);
    int32_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 0)
    {
        if(scaledvalue >= 2147483647)
            number = 2147483647;
        else
            number = (int32_t)(scaledvalue + 0.5f); // account for fractional truncation
    }
    else
    {
        if(scaledvalue <= (-2147483647 - 1))
            number = (-2147483647 - 1);
        else
            number = (int32_t)(scaledvalue - 0.5f); // account for fractional truncation
    }

    int32ToBeBytes((int32_t)number, bytes, index);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 4 signed bytes in little
 * endian order.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \param scaler is multiplied by value to create the encoded integer: encoded = value*scaler.
 */
void float32ScaledTo4SignedLeBytes(float value, uint8_t* bytes, int* index, float scaler)
{
    // scale the number
    float scaledvalue = (float)(value*scaler);
    int32_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 0)
    {
        if(scaledvalue >= 2147483647)
            number = 2147483647;
        else
            number = (int32_t)(scaledvalue + 0.5f); // account for fractional truncation
    }
    else
    {
        if(scaledvalue <= (-2147483647 - 1))
            number = (-2147483647 - 1);
        else
            number = (int32_t)(scaledvalue - 0.5f); // account for fractional truncation
    }

    int32ToLeBytes((int32_t)number, bytes, index);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 3 unsigned bytes in big
 * endian order.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \param min is the minimum value that can be encoded.
 * \param scaler is multiplied by value to create the encoded integer: encoded = (value-min)*scaler.
 */
void float32ScaledTo3UnsignedBeBytes(float value, uint8_t* bytes, int* index, float min, float scaler)
{
    // scale the number
    float scaledvalue = (float)((value - min)*scaler);
    uint32_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 16777215u)
        number = 16777215u;
    else if(scaledvalue <= 0)
        number = 0;
    else
        number = (uint32_t)(scaledvalue + 0.5f); // account for fractional truncation

    uint24ToBeBytes((uint32_t)number, bytes, index);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 3 unsigned bytes in
 * little endian order.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \param min is the minimum value that can be encoded.
 * \param scaler is multiplied by value to create the encoded integer: encoded = (value-min)*scaler.
 */
void float32ScaledTo3UnsignedLeBytes(float value, uint8_t* bytes, int* index, float min, float scaler)
{
    // scale the number
    float scaledvalue = (float)((value - min)*scaler);
    uint32_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 16777215u)
        number = 16777215u;
    else if(scaledvalue <= 0)
        number = 0;
    else
        number = (uint32_t)(scaledvalue + 0.5f); // account for fractional truncation

    uint24ToLeBytes((uint32_t)number, bytes, index);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 3 signed bytes in big
 * endian order.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \param scaler is multiplied by value to create the encoded integer: encoded = value*scaler.
 */
void float32ScaledTo3SignedBeBytes(float value, uint8_t* bytes, int* index, float scaler)
{
    // scale the number
    float scaledvalue = (float)(value*scaler);
    int32_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 0)
    {
        if(scaledvalue >= 8388607)
            number = 8388607;
        else
            number = (int32_t)(scaledvalue + 0.5f); // account for fractional truncation
    }
    else
    {
        if(scaledvalue <= (-8388607 - 1))
            number = (-8388607 - 1);
        else
            number = (int32_t)(scaledvalue - 0.5f); // account for fractional truncation
    }

    int24ToBeBytes((int32_t)number, bytes, index);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 3 signed bytes in little
 * endian order.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \param scaler is multiplied by value to create the encoded integer: encoded = value*scaler.
 */
void float32ScaledTo3SignedLeBytes(float value, uint8_t* bytes, int* index, float scaler)
{
    // scale the number
    float scaledvalue = (float)(value*scaler);
    int32_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 0)
    {
        if(scaledvalue >= 8388607)
            number = 8388607;
        else
            number = (int32_t)(scaledvalue + 0.5f); // account for fractional truncation
    }
    else
    {
        if(scaledvalue <= (-8388607 - 1))
            number = (-8388607 - 1);
        else
            number = (int32_t)(scaledvalue - 0.5f); // account for fractional truncation
    }

    int24ToLeBytes((int32_t)number, bytes, index);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 2 unsigned bytes in big
 * endian order.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \param min is the minimum value that can be encoded.
 * \param scaler is multiplied by value to create the encoded integer: encoded = (value-min)*scaler.
 */
void float32ScaledTo2UnsignedBeBytes(float value, uint8_t* bytes, int* index, float min, float scaler)
{
    // scale the number
    float scaledvalue = (float)((value - min)*scaler);
    uint16_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 65535u)
        number = 65535u;
    else if(scaledvalue <= 0)
        number = 0;
    else
        number = (uint16_t)(scaledvalue + 0.5f); // account for fractional truncation

    uint16ToBeBytes((uint16_t)number, bytes, index);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 2 unsigned bytes in
 * little endian order.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \param min is the minimum value that can be encoded.
 * \param scaler is multiplied by value to create the encoded integer: encoded = (value-min)*scaler.
 */
void float32ScaledTo2UnsignedLeBytes(float value, uint8_t* bytes, int* index, float min, float scaler)
{
    // scale the number
    float scaledvalue = (float)((value - min)*scaler);
    uint16_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 65535u)
        number = 65535u;
    else if(scaledvalue <= 0)
        number = 0;
    else
        number = (uint16_t)(scaledvalue + 0.5f); // account for fractional truncation

    uint16ToLeBytes((uint16_t)number, bytes, index);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 2 signed bytes in big
 * endian order.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \param scaler is multiplied by value to create the encoded integer: encoded = value*scaler.
 */
void float32ScaledTo2SignedBeBytes(float value, uint8_t* bytes, int* index, float scaler)
{
    // scale the number
    float scaledvalue = (float)(value*scaler);
    int16_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 0)
    {
        if(scaledvalue >= 32767)
            number = 32767;
        else
            number = (int16_t)(scaledvalue + 0.5f); // account for fractional truncation
    }
    else
    {
        if(scaledvalue <= (-32767 - 1))
            number = (-32767 - 1);
        else
            number = (int16_t)(scaledvalue - 0.5f); // account for fractional truncation
    }

    int16ToBeBytes((int16_t)number, bytes, index);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 2 signed bytes in little
 * endian order.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \param scaler is multiplied by value to create the encoded integer: encoded = value*scaler.
 */
void float32ScaledTo2SignedLeBytes(float value, uint8_t* bytes, int* index, float scaler)
{
    // scale the number
    float scaledvalue = (float)(value*scaler);
    int16_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 0)
    {
        if(scaledvalue >= 32767)
            number = 32767;
        else
            number = (int16_t)(scaledvalue + 0.5f); // account for fractional truncation
    }
    else
    {
        if(scaledvalue <= (-32767 - 1))
            number = (-32767 - 1);
        else
            number = (int16_t)(scaledvalue - 0.5f); // account for fractional truncation
    }

    int16ToLeBytes((int16_t)number, bytes, index);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 1 unsigned byte.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 1 when this function is complete.
 * \param min is the minimum value that can be encoded.
 * \param scaler is multiplied by value to create the encoded integer: encoded = (value-min)*scaler.
 */
void float32ScaledTo1UnsignedBytes(float value, uint8_t* bytes, int* index, float min, float scaler)
{
    // scale the number
    float scaledvalue = (float)((value - min)*scaler);
    uint8_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 255u)
        number = 255u;
    else if(scaledvalue <= 0)
        number = 0;
    else
        number = (uint8_t)(scaledvalue + 0.5f); // account for fractional truncation

    uint8ToBytes((uint8_t)number, bytes, index);
}


/*!
 * Encode a float on a byte stream by scaling to fit in 1 signed byte.
 * \param value is the number to encode.
 * \param bytes is a pointer to the byte stream which receives the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 1 when this function is complete.
 * \param scaler is multiplied by value to create the encoded integer: encoded = value*scaler.
 */
void float32ScaledTo1SignedBytes(float value, uint8_t* bytes, int* index, float scaler)
{
    // scale the number
    float scaledvalue = (float)(value*scaler);
    int8_t number;

    // Make sure number fits in the range
    if(scaledvalue >= 0)
    {
        if(scaledvalue >= 127)
            number = 127;
        else
            number = (int8_t)(scaledvalue + 0.5f); // account for fractional truncation
    }
    else
    {
        if(scaledvalue <= (-127 - 1))
            number = (-127 - 1);
        else
            number = (int8_t)(scaledvalue - 0.5f); // account for fractional truncation
    }

    int8ToBytes((int8_t)number, bytes, index);
}


// end of scaledencode.c
