CC = g++
INCLUDE = -Iinclude


all: main.exe exe

main.exe:
	$(CC) $(INCLUDE) -o bin/main.exe src/*.cpp
	
exe:
	./bin/main.exe
	
