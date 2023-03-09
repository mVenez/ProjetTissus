CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++17 -pedantic -Wall #J'ai changé avec c++17, si on a des problèmes il suffit de retourner à 11
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