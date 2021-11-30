TARGET = ./main.out
HDRS = project/include

CC = g++

SRCS = \
	   project/src/date.cpp \
       project/src/day.cpp \
	   project/src/duration.cpp \
	   project/src/event.cpp \
	   project/src/group.cpp \
	   project/src/main.cpp

.PHONY: all build rebuild clean

all: clean build

build: $(TARGET)

rebuild: clean build

$(TARGET): $(SRCS)
	$(CC) -Wall -Wextra -Werror $(addprefix -I,$(HDRS)) -o $(TARGET) $(CFLAGS) $(SRCS)

clean:
	rm -f $(TARGET)
