# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = protocol-test

SRC = ../src

SRC_FILES = *.c
PROTOCOL_FILES = $(SRC)/*.c

INC_DIR = ../src
DEPS = main.h $(INC_DIR)/*.h

HEADER_FILES = $(SRC)/*.h

$(TARGET): $(SRC_FILES) $(PROTOCOL_FILES) $(DEPS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_FILES) $(PROTOCOL_FILES) $(DEPS) -I../src/

clean:
	$(RM) $(TARGET)