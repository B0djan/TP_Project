TARGET = ./HttpServer

PORT = 8080

HDRS_DIR = \
 	   project*/include/*/*.hpp

SRCS = \
       project*/src/*.cpp

.PHONY: all build rebuild check clean launch

all: clean check

build:
	g++ -I $(HDRS_DIR) -lmagic $(SRCS) -o $(TARGET)

rebuild: clean build

check:
	./linters/run_linters.sh

launch:
	./HttpServer 127.0.0.1 $(PORT)

clean:
	rm -rf $(TARGET)