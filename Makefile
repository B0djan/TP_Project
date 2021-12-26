TARGET = HttpServer

IP = 127.0.0.1

IP2 = 192.168.31.207

IP3 = 192.168.31.233

PORT = 8080


.PHONY: all build rebuild check clean launch launch_client test launch_Peter launch_Peter_2

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

launch_client:
	curl -vvv http://$(IP):$(PORT)

launch_Peter:
	./build/project/$(TARGET) $(IP2) $(PORT)

launch_Peter_2:
	./build/project/$(TARGET) $(IP3) $(PORT)

test:
	curl -vvv  -H 'Content-Type: application/json' --data '{"autorization":{"login":"piter","password":"123456789"}}' http://$(IP):$(PORT)/

