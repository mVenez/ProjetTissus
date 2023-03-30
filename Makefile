CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall
LDLIBS = -lm

all: testVecteur3D testMasse testRessort testIntegrateur1 testIntegrateur2 testIntegrateur3
	@echo "Wow Mais qui donc à fais ce merveilleux code ? Il fonctionne super bien, je doit être codé par des beau gosse absolu, l’Executable est construit trop fort"
	
Vecteur3D.o: Vecteur3D.cc Vecteur3D.h

Masse.o: Masse.cc Masse.h Constantes.h Vecteur3D.h 

testMasse.o : testMasse.cc

Ressort.o: Ressort.cc Ressort.h Masse.h

Integrateur.o: Integrateur.cc Integrateur.h Masse.h Vecteur3D.h

Constantes.o: Constantes.cc Constantes.h

testVecteur3D.o: testVecteur3D.cc Vecteur3D.h

testVecteur3D: testVecteur3D.o Vecteur3D.o

testMasse: testMasse.o Masse.o Vecteur3D.o Constantes.o Ressort.o

testRessort: testRessort.o Ressort.o Masse.o Vecteur3D.o Constantes.o

testIntegrateur1: testIntegrateur1.o Integrateur.o Masse.o Vecteur3D.o Constantes.o Ressort.o

testIntegrateur2: testIntegrateur2.o Integrateur.o Masse.o Vecteur3D.o Constantes.o Ressort.o

testIntegrateur3: testIntegrateur3.o Integrateur.o Masse.o Vecteur3D.o Constantes.o Ressort.o


clean:
	rm -f *.o
	rm testVecteur3D
	rm testMasse
	rm testRessort
	@echo "Fichiers de construction et executable eliminés"

wclean:
	del -f *.o
	del testVecteur3D.exe
	del testMasse.exe
	del testRessort.exe
	@echo "Fichiers de construction et executable eliminés"