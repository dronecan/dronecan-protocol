TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

INCLUDEPATH += tests \
               ../src \
               ../static

SOURCES += main.cpp \
    ../src/dc_pkt_cmd.c \
    ../static/drone_can_packet.c \
    ../src/fieldencode.c \
    ../src/fielddecode.c \
    ../src/scaledencode.c \
    ../static/drone_can_classes.c \
    ../src/dc_pkt_sys.c \
    ../src/dc_dev_info.c \
    ../src/DC_BlockProtocol.c \
    ../src/DC_CommandProtocol.c \
    ../src/dc_pkt_block.c \
    ../src/dc_pkt_telem.c \
    ../src/DC_SystemProtocol.c \
    ../src/DC_TelemetryProtocol.c \
    ../src/scaleddecode.c \
    ../static/drone_can_protocol.c \
    tests/test_encdec.cpp \
    packet_printer.cpp \
    ../static/drone_can_vendors.c
    ../src/scaleddecode.c \

HEADERS += \
    ../src/dc_pkt_cmd.h \
    ../src/DC_TelemetryDeviceStatusField.h \
    ../src/DroneCAN_CommandProtocol.h \
    ../src/DroneCAN_SystemProtocol.h \
    ../src/DroneCAN_TelemetryProtocol.h \
    ../static/drone_can_packet.h \
    ../static/drone_can_classes.h \
    ../src/DC_CommandProtocol.h \
    ../src/fieldencode.h \
    ../src/fielddecode.h \
    ../src/scaledencode.h \
    ../src/dc_pkt_sys.h \
    ../src/DC_SystemProtocol.h \
    ../static/drone_can_device.h \
    ../src/dc_dev_info.h \
    ../src/DC_AutopilotProtocol.h \
    ../src/DC_BlockProtocol.h \
    ../src/dc_pkt_block.h \
    ../src/dc_pkt_telem.h \
    ../src/DC_TelemetryProtocol.h \
    ../src/scaleddecode.h \
    ../static/drone_can_protocol.h \
    tests/test_encdec.h \
    packet_printer.h \
    ../static/drone_can_vendors.h
    ../src/scaleddecode.h \
