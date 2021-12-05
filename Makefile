TARGET = ./main.out
HDRS = \
		project/include \
		project/include/include_parse_json 


CC = g++

SRCS = \
		project/src/parse_json/parse_event.cpp \
       	project/src/parse_json/parse_group.cpp \
	   	project/src/parse_json/parse_person_data.cpp \
	   	project/src/parse_json/parse_registration.cpp \
	   	project/parse_json/main.cpp

.PHONY: all build rebuild clean

all: clean build

build: $(TARGET)

rebuild: clean build

$(TARGET): $(SRCS)
	$(CC) -Wall -Wextra -Werror $(addprefix -I,$(HDRS)) -o $(TARGET) $(CFLAGS) $(SRCS)

clean:
	rm -f $(TARGET)
