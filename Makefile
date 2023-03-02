main: functions.o
	g++ -std=c++17 -o main main.cpp functions.o -O3
functions:
	g++ -std=c++17 -c functions.cpp -O3
clean:
	rm *.o main