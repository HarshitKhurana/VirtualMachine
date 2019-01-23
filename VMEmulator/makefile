CFLAGS=-std=c++11 -Wall

all: stack-vm

stack-vm: stack-vm.o main.o
		$(CXX) $(CFLAGS) main.o -o stack-vm

main.o: main.cpp
		$(CXX) $(CFLAGS) -c main.cpp

stack-vm.o: stack-vm.h stack-vm.cpp
		$(CXX) $(CFLAGS) -c stack-vm.cpp

clean:
		rm -f *.o stack-vm

rm:
		rm -f *.o stack-vm

run:
		./stack-vm
