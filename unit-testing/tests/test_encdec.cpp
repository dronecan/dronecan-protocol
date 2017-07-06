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

#include "test_encdec.h"

#include <QDebug>

QList<int> ListAllClasses()
{
    QList<int> classes;

    classes << DC_MSG_CLASS_AUTOPILOT;
    classes << DC_MSG_CLASS_COMMAND;
    classes << DC_MSG_CLASS_TELEMETRY;
    classes << DC_MSG_CLASS_SYSTEM;
    classes << DC_MSG_CLASS_DEBUG;
    classes << DC_MSG_CLASS_BLOCK;

    return classes;
}

int Test_EncDecAllId()
{
    qDebug() << "Test_EncDecAllId";

    int errorCount = 0;

    auto classes = ListAllClasses();

    uint32_t id;
    uint8_t idClass;
    uint16_t  idMsg;

    for (auto classId : classes)
    {
        for (int msgId = 0; msgId <= 0xFFFF; msgId++)
        {
            id = DC_EncodeID(classId, msgId, 0x00, 0x00);

            idClass = DC_GetClassFromID(id);
            idMsg = DC_GetMessageFromID(id);

            if (idClass != classId)
            {
                qDebug() << "Error encoding class ID -" << classId << "->" << idClass;
                errorCount++;
            }

            if (idMsg != msgId)
            {
                qDebug() << QString::number(id, 16).rightJustified(8,'0');
                qDebug() << "Error encoded message ID -" << msgId << "->" << idMsg;
                errorCount++;
            }
        }
    }

    return errorCount;
}

int Test_InvalidMsg()
{
    qDebug() << "Running Test_InvalidMsg";

    auto classes = ListAllClasses();

    DC_Packet_t pkt;

    int errorCount = 0;

    const uint16_t MSG_ID = 0xABCD;

    uint16_t tmp;

    for (auto a : classes)
    {
        for (auto b : classes)
        {
            if (a == b)
                continue;

            finishDC_ClassPacket(&pkt, 0, MSG_ID, a);

            tmp = DC_GetClassFromID(pkt.id);

            // Test that it was encoded correctly
            if (tmp != a)
            {
                errorCount++;
                qDebug() << "Error encoding class -" << a << "->" << tmp;
            }

            // Test decoding of correct class
            tmp = getDC_ClassID(&pkt, a);
            if (tmp != MSG_ID)
            {
                errorCount++;
                qDebug() << "Mismatch on class decode -" << a << "results in" << tmp;
            }

            // Test decoding of incorrect class
            tmp = getDC_ClassID(&pkt, b);
            if (tmp != DC_MSG_INVALID)
            {
                errorCount++;
                qDebug() << "Invalid class did not return DC_MSG_INVALID:" << tmp;
            }
        }
    }

    return errorCount;
}
