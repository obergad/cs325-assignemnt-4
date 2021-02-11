CC = g++ -std=c++11 -g

all:  main

main: main.o
		$(CC) main.o -o main

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm -f *.o main
