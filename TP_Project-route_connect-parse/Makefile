TARGET = ./main.out
HDRS = \
		project/libs/database_connector/postgresql \
		project/database_connect/include/impl \
		project/parser/include


CC = g++

SRCS = \
		project/database_connect/src/pgconnection.cpp \
		project/database_connect/src/main.cpp

.PHONY: all build rebuild clean

all: clean build

build: $(TARGET)

rebuild: clean build

$(TARGET): $(SRCS)
#	$(CC) $(addprefix -I,$(HDRS)) -o $(TARGET) $(CFLAGS) $(SRCS)
	$(CC) $(addprefix -I,$(HDRS)) -o $(TARGET) $(CFLAGS) $(SRCS) -lpq

clean:
	rm -f $(TARGET)