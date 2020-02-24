TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../src/

SOURCES += \
        ../src/DroneCANProtocol.c \
        ../src/DroneCAN_SystemPackets.c \
        ../src/fielddecode.c \
        ../src/fieldencode.c \
        ../src/scaleddecode.c \
        ../src/scaledencode.c \
        dronecan_packet_glue.c \
        main.c

HEADERS += \
    ../src/DroneCANProtocol.h \
    ../src/DroneCAN_Packets.h \
    ../src/DroneCAN_SystemPackets.h \
    ../src/fielddecode.h \
    ../src/fieldencode.h \
    ../src/scaleddecode.h \
    ../src/scaledencode.h \
    dronecan_packet_glue.h
