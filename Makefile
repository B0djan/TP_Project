SRCS=\
		project/src/day.cpp \
		project/src/time.cpp \
		project/src/date.cpp \
		project/src/event.cpp 

HDRS_DIR=project/include

CC=g++
#CFLAGS =-Iinclude
PRNAME=program

$(PRNAME):
	$(CC) -I $(HDRS_DIR) -o $(PRNAME) $(SRCS)

build: $(PRNAME)

clean:
	rm -f $(PRNAME)

test: build
	./$(PRNAME)

.PHONY: clean test build btest all
