CC = g++
INCLUDE = -Iinclude 
OPTIONS =  -g -O3


all: main.exe exe

main.exe:
	$(CC) $(INCLUDE) $(OPTIONS) -o bin/main.exe src/*.cpp
	
exe:
	time ./bin/main.exe

debug:
	gdb bin/main.exe
	
	