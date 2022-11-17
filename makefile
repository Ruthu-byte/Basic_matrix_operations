main: vector.o matrix.o main.o arithmetic.o
	g++ -std=c++98 main.o matrix.o vector.o arithmetic.o -o out

main.o: main.cpp
	g++ -std=c++98 -c main.cpp

matrix.o: arithmetic.h matrix.h matrix.cpp
	g++ -std=c++98 -c matrix.cpp

vector.o: arithmetic.h vector.h vector.cpp
	g++ -std=c++98 -c vector.cpp

arithmetic.o: arithmetic.h arithmetic.cpp
	g++ -std=c++98 -c arithmetic.cpp

run:
	valgrind ./out
	
clean:
	rm *.o out