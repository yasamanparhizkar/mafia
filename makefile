CC = g++
CFLAGS = -std=c++98 -Wall

all: God_helper.cpp myCommand Room Player God
	$(CC) $(CFLAGS) God_helper.cpp God_helper_lib.cpp myCommand.o Room.o Player.o God.o -o a.out && ./a.out

myCommand: myCommand.hpp myCommand.cpp
	$(CC) $(CFLAGS) -c myCommand.cpp -o myCommand.o

Room: Room.hpp Room.cpp
	$(CC) $(CFLAGS) -c Room.cpp -o Room.o

Player: Player.hpp Player.cpp
	$(CC) $(CFLAGS) -c Player.cpp -o Player.o

God: God.hpp God.cpp
	$(CC) $(CFLAGS) -c God.cpp -o God.o

clean:
	rm -r *.out; rm -r *.o;
