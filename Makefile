CC = g++


all: main.exe

main.o:
	$(CC) -c src/main.cpp -o obj/main.o
	
Layer.o:
	$(CC) -c src/Layer.cpp -o obj/Layer.o
	
main.exe: main.o Layer.o
	$(CC) -o bin/main.exe obj/*.o
	
