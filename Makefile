CC = g++
INCLUDE = -Iinclude

all: main.exe

main.exe:
	$(CC) $(INCLUDE) -o bin/main.exe src/*.cpp
	
