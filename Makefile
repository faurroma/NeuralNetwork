CC = g++
INCLUDE = -Iinclude 
OPTIONS =  -g -O3


all: main.exe exe

main:
	mkdir -p bin
	$(CC) $(INCLUDE) $(OPTIONS) -o bin/main.exe src/main.cpp

mnist:
	$(CC) $(INCLUDE) $(OPTIONS) -o bin/mnist.exe src/MNIST.cpp

XOR:
	$(CC) $(INCLUDE) $(OPTIONS) -o bin/xor.exe src/XOR.cpp
	
exe:
	./bin/main.exe

debug:
	gdb bin/main.exe
	
	
