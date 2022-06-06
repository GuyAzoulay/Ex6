all: main 

main: main.o
	g++ -o main Team.cpp League.cpp Schedule.cpp Game.cpp main.cpp



main.o: Team.cpp League.cpp Schedule.cpp Game.cpp main.cpp
	g++ -c Team.cpp League.cpp Schedule.cpp Game.cpp main.cpp	

.PHONY: main clean

clean:
	rm -f main main.o Game Game.o Team Team.o League League.o Schedule Schedule.o