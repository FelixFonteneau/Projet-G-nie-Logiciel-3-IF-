ECHO=echo
COMP=g++
CPPFLAGS=-g -o3 -Wall -ansi -pedantic -std=c++11
INT= Modeles/Mesure.h Modeles/MesureO3.h Modeles/MesureSO2.h Modeles/MesureNO2.h Modeles/MesurePM10.h  Modeles/Capteur.h  Modeles/Moment.h  Services/Service.h Util/Algo.h Util/Messages.h Util/Factory.h 
REAL=$(INT:.h=.cpp)
BINAIRE= $(INT:.h=.o)
EXE= bin/qualiteAir
TEST=test

$(EXE): $(BINAIRE) Vue/main.o
	$(ECHO) "Editions des liens, création de <$<>"
	$(COMP) -o $(EXE) $(BINAIRE) Vue/main.o
	
$(TEST):
	cd Tests ; bash ./mktest.sh

all:
	make -C Modeles
	make -C Services
	make -C Util
	make -C Vue

clean:
	make clean -C Modeles
	make clean -C Services
	make clean -C Util
	make clean -C Vue
	
	
