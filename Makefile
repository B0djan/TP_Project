TARGET = HttpServer

IP = 127.0.0.1

PORT = 9999


.PHONY: all build rebuild check clean launch

all: rebuild launch

build:
	./build.sh

rebuild: clean build

check:
	./linters/run_linters.sh

clean:
	rm -rf build

launch:
	./build/project/$(TARGET) $(IP) $(PORT)