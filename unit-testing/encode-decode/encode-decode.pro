TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../../src \
               ../../static

SOURCES += main.cpp \
    ../../src/dc_pkt_cmd.c \
    ../../src/DC_Sys_UID.c \
    ../../static/drone_can_packet.c \
    ../../static/drone_can_protocol_glue.c \
    ../../src/fieldencode.c \
    ../../src/fielddecode.c \
    ../../src/scaledencode.c \
    ../../static/drone_can_classes.c
    ../../src/scaleddecode.c \

HEADERS += \
    ../../src/dc_pkt_cmd.h \
    ../../src/DC_Sys_UID.h \
    ../../src/DC_TelemetryDeviceStatusField.h \
    ../../src/DroneCAN_CommandProtocol.h \
    ../../src/DroneCAN_SystemProtocol.h \
    ../../src/DroneCAN_TelemetryProtocol.h \
    ../../static/drone_can_packet.h \
    ../../static/drone_can_protocol_glue.h \
    ../../static/drone_can_classes.h \
    ../../src/DC_CommandProtocol.h \
    ../../src/fieldencode.h \
    ../../src/fielddecode.h \
    ../../src/scaledencode.h
    ../../src/scaleddecode.h \
