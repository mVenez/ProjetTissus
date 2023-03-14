CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall #Je suis retourné à c++11
LDLIBS = -lm

all: testVecteur3D
	@echo "Executable construit"
	
Vecteur3D.o: Vecteur3D.cc Vecteur3D.h

testVecteur3D.o: testVecteur3D.cc Vecteur3D.h

testVecteur3D: testVecteur3D.o Vecteur3D.o

clean:
	rm -f *.o
	rm testVecteur3D
	@echo "Fichiers de construction et executable eliminés"

wclean:
	del -f *.o
	del testVecteur3D.exe
	@echo "Fichiers de construction et executable eliminés"