# target            - output - highest priority
# prerequisites     - monitor changes to main.o Stack.o
# command           - link object files (.o files)
#                   - generate executable named output
output: main.o Queue.o
	g++ -o output main.o Queue.o

# target            - main.o
# prerequisites     - monitor changes to main.cpp
# command           - generate main.o
main.o: main.cpp
	g++ -c main.cpp

# target            - Stack.o
# prerequisites     - monitor changes to Stack.cpp, Stack.h
# command           - generate Stack.o
Stack.o: Queue.h Queue.cpp
	g++ -c Queue.cpp

# target            - clean
# prerequisites     - none
# command           - remove .o files and executable
# command line      - make clean
clean:
	rm output main.o Queue.o