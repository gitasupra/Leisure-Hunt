CXX=g++
CXXFLAGS=-std=c++17

main: main.o game.o
	${CXX} ${CXXFLAGS} -o $@ -lm $^

main.o: main.cpp game.h house.h
	${CXX} ${CXXFLAGS} -c main.cpp -o main.o

game.o: game.cpp game.h house.h
	${CXX} ${CXXFLAGS} -c game.cpp -o game.o

# The *~ is for the temporary files Emacs creates
clean:
	rm -f *~ *.o main