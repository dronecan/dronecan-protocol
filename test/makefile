# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = protocol-test

SRC_DIR = ../src
STATIC_DIR = ../static
MUNIT_DIR = munit

SRC_FILES = *.c $(SRC_DIR)/*.c $(STATIC_DIR)/*.c $(MUNIT_DIR)/munit.c
INC_FILES =  $(SRC_DIR)/*.h $(STATIC_DIR)/*.h $(MUNIT_DIR)/munit.h

$(TARGET): $(SRC_FILES) $(SRC_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_FILES) $(INC_FILES) -Imunit/ -I../src/ -I../static/

clean:
	$(RM) $(TARGET)