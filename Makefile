
install: main.o Sorting.o
	g++ main.o Sorting.o -o Sorting

main.o: main.cpp
	g++ -c main.cpp

Sorting.o: Sorting.cpp Sorting.h
	g++ -c Sorting.cpp

clean:
	rm *.o Sorting