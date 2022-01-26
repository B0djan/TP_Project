TARGET = ./main.out
HDRS = \
		project/include/

CC = g++

SRCS = \
		project/src/MeetUp.cpp \
		\
	   	project/src/duration.cpp \
	   	project/src/structs.cpp \
	   	project/src/event.cpp \
	   	project/src/day.cpp \
	   	project/main.cpp

.PHONY: all build rebuild clean

all: clean build

build: $(TARGET)

rebuild: clean build

$(TARGET): $(SRCS)
	$(CC) -Wall -Wextra -Werror $(addprefix -I,$(HDRS)) -o $(TARGET) $(CFLAGS) $(SRCS)

clean:
	rm -f $(TARGET)
