CC=g++
CXXFLAGS=-std=c++98 -Iinclude -Wall -pedantic
CXXLDFLAGS=-ldiscord-rpc -pthread
DISCORD-RPC-PATH=-Idiscord-rpc\build\include -Ldiscord-rpc\build\lib

TARGET=presenceutil

.PHONY: discord-rpc

all: $(TARGET)

$(TARGET): clean wait.o handlers.o main.o
	mkdir bin obj
	mv *.o obj
	$(CC) $(CXXFLAGS) $(DISCORD-RPC-PATH) obj/$(word 2, $^) obj/$(word 3, $^) obj/$(word 4, $^) -o bin/$(TARGET) $(CXXLDFLAGS)

main.o: discord-rpc src/main.cpp
	$(CC) $(DISCORD-RPC-PATH) $(CXXFLAGS) -c $^

wait.o: src/wait.cpp
	$(CC) $(CXXFLAGS) -c $^

handlers.o: discord-rpc src/handlers.cpp
	$(CC) $(DISCORD-RPC-PATH) $(CXXFLAGS) -c $^
	
discord-rpc: discord-rpc/CMakeLists.txt
	cd discord-rpc; \
	mkdir build; \
	cd build; \
	cmake .. -DCMAKE_INSTALL_PREFIX=.; \
	cmake --build . --config Release --target install; \

clean:
	rm -rf bin obj *.log discord-rpc/build
