CFLAGS=-std=c++11 -Wall

all: vmEmulator

vmEmulator: vmEmulator.o main.o
		$(CXX) $(CFLAGS) main.o -o vmEmulator

main.o: main.cpp
		$(CXX) $(CFLAGS) -c main.cpp

vmEmulator.o: vmEmulator.h vmEmulator.cpp
		$(CXX) $(CFLAGS) -c vmEmulator.cpp

clean:
		rm -f *.o vmEmulator

rm:
		rm -f *.o vmEmulator

run:
		./vmEmulator
