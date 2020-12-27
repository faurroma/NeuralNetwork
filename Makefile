CC = g++
INCLUDE = -Iinclude 
OPTIONS =  -g


all: main.exe exe

main.exe:
	$(CC) $(INCLUDE) $(OPTIONS) -o bin/main.exe src/*.cpp
	
exe:
	./bin/main.exe
	
