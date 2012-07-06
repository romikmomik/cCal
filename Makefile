CC  = gcc
CXX = g++
STRIP = strip
RM = rm -rf 
#CFLAGS = -o2
#LDFLAGS ?= 

SRC_DIR 	= src

SRC_MAIN_C	= $(wildcard $(SRC_DIR)/*.c)
OBJ_MAIN_C      =$(patsubst %.c, %.o, $(SRC_MAIN_C))
DEP_MAIN_C	=$(patsubst %.c, %.d, $(SRC_MAIN_C))

TARGET		= cCal

.PHONY: all clean 

all: $(TARGET)

default: all

$(OBJ_MAIN_C): %.o: %.c %.d
	$(CC) $(CFLAGS) -c $< -o $@
$(DEP_MAIN_C): %.d: %.c
	$(CC) $(CFLAGS) -M $< -MT "$*.o" -o $@

$(TARGET): $(OBJ_MAIN_C)
	$(CXX) -o $@ $(OBJ_MAIN_C) $(LDFLAGS)

clean:
	$(RM) $(TARGET)
	$(RM) $(OBJ_MAIN_C) $(DEP_MAIN_C)

