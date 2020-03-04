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

#include <string.h>

#include "dronecan_packet_descriptor.h"


/**
 * Lookup the label for a given packet. Search through the available packet enumerations.
 * 
 * When a new packet enumeration is added, ensure that it is referenced here.
 */
const char* DroneCAN_PacketLabel(int pktId)
{
    if (strlen(DroneCAN_System_Packets_EnumLabel(pktId)) > 0)
    {
        return DroneCAN_System_Packets_EnumLabel(pktId);
    }

    // No packet label found
    return "";
}


/**
 * Lookup the description for a given packet. Search through the available packet enumerations.
 * 
 * When a new packet enumeration is added, ensure that it is referenced here.
 */
const char* DroneCAN_PacketDescription(int pktId)
{
    if (strlen(DroneCAN_System_Packets_EnumTitle(pktId)) > 0)
    {
        return DroneCAN_System_Packets_EnumTitle(pktId);
    }

    // No packet descriptor found
    return "";
}