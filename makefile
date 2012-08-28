CC = g++

strict_options = -Wall -pedantic

simulator: main.o event.o building.o elevator.o floor.o passenger.o
	g++ -o simulator main.o event.o building.o elevator.o floor.o passenger.o

main.o: main.cpp event.h building.h elevator.h floor.h passenger.h
	$(CC) -o $@ -c $< $(strict_options)

event.o: event.cpp building.h
	$(CC) -o $@ -c $< $(strict_options)

building.o: building.cpp elevator.h
	$(CC) -o $@ -c $< $(strict_options)

elevator.o: elevator.cpp floor.h
	$(CC) -o $@ -c $< $(strict_options)

floor.o: floor.cpp passenger.h
	$(CC) -o $@ -c $< $(strict_options)

passenger.o: passenger.cpp
	$(CC) -o $@ -c $< $(strict_options)
	
