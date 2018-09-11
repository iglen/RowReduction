

main: matrix.o main.o
	g++ matrix.o main.o -o main

main.o: main.cpp matrix.h
	g++ -g -Wall -c main.cpp

matrix.o: matrix.cpp matrix.h
	g++ -g -Wall -c matrix.cpp

clean:
	rm -r main.o matrix.o main
