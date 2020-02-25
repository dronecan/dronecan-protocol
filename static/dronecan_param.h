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

#ifndef _DRONECAN_PARAM_H_
#define _DRONECAN_PARAM_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    //! Data format of the parameter value
    uint8_t format;

    //! Parameter name (up to 96 characters)
    char name[96];

    //! Parameter value (union of possible types)
    union {
        uint8_t     value_bytes[4];     //! Raw bytes
        int8_t      value_sint8;        //! Signed integer, 8 bits
        uint8_t     value_uint8;        //! Unsigned integer, 8 bits
        int16_t     value_sint16;       //! Signed integer, 16 bits
        uint16_t    value_uint16;       //! Unsigned integer, 16 bits
        int32_t     value_sint32;       //! Signed integer, 32 bits
        uint32_t    value_uint32;       //! Unsigned integer, 32 bits
        float       value_float;        //! Floating point, 32 bits
    };

} DroneCAN_Parameter_t;


#ifdef __cplusplus
}
#endif

#endif // _DRONECAN_PARAM_H_