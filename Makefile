CC=g++
CXXFLAGS=-std=c++98 -Iinclude -Llib -Wall -pedantic
CXXLDFLAGS=-ldiscord-rpc -pthread

TARGET=presenceutil

all: $(TARGET)

$(TARGET): clean main.o
	mkdir bin obj
	mv *.o obj
	$(CC) $(CXXFLAGS) -g -s obj/$(word 2, $^) -o bin/$(TARGET) $(CXXLDFLAGS)

main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c $^

clean:
	rm -rf bin obj *.log
