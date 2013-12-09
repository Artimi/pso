CXX=g++
CXXFLAGS=-g -std=c++0x -Wall -pedantic
BIN=pso

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o
	rm $(BIN)

pack:
	zip xsebek02.zip Makefile MathVector.cpp MathVector.hpp Parameters.cpp \
	Parameters.hpp Particle.cpp Particle.hpp Pso.cpp Pso.hpp Testbed.cpp \
	Testbed.hpp main.cpp plot.py report/pso.pdf pso
