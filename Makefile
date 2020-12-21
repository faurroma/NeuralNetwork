CC = g++


all: main.exe

main.o:
	$(CC) -c src/main.cpp -o obj/main.o
	
main.exe: main.o
	$(CC) -o bin/main.exe obj/main.o