TARGET = ./HttpServer

IP = 127.0.0.1

PORT = 8080

HDRS_DIR = \
 	   project*/include

SRCS = \
       project*/src/*.cpp

CC = g++

CFLAGS = -lmagic

.PHONY: build rebuild check clean launch

build:
	$(CC) $(CFLAGS) -I $(HDRS_DIR) -o $(TARGET) $(SRCS)

rebuild: clean build

check:
	./linters/run_linters.sh

launch:
	./HttpServer $(IP) $(PORT)

clean:
	rm -rf $(TARGET)