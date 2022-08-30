CXX=g++
CXXFLAGS=-std=c++17

main: main.o
	${CXX} ${CXXFLAGS} -o $@ -lm $^

main.o: main.cpp game.h
	${CXX} ${CXXFLAGS} -c main.cpp -o main.o

# The *~ is for the temporary files Emacs creates
clean:
	rm -f *~ *.o main