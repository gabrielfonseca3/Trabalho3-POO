renner_ci: main.o functions.o
	g++ main.o functions.o -o renner_ci

main.o: main.cpp
	g++ -c main.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

clean:
	rm *.o renner_ci