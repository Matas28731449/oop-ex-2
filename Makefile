main: clean
	g++ -std=c++17 -O3 -o main main.cpp functions.cpp
functions:
	g++ -std=c++17 -O3 -o functions.cpp
clean:
	rm -f *.o main