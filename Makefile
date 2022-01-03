TARGET = ./main.out
HDRS = \
		project/include/include_business

CC = g++

SRCS = \
		project/src/business/MeetUp.cpp \
		\
	   	project/src/business/duration.cpp \
	   	project/src/business/structs.cpp \
	   	project/src/business/event.cpp \
	   	project/src/business/day.cpp \
	   	project/main.cpp

.PHONY: all build rebuild clean

all: clean build

build: $(TARGET)

rebuild: clean build

$(TARGET): $(SRCS)
	$(CC) -Wall -Wextra -Werror $(addprefix -I,$(HDRS)) -o $(TARGET) $(CFLAGS) $(SRCS)

clean:
	rm -f $(TARGET)
