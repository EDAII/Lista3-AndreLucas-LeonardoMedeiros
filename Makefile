CC := g++
CFLAGS := -W -Wall -o prog -std=c++14

all:
	$(CC) $(CFLAGS) main.cpp
clean:
	rm prog

run:
	./prog > rank.txt