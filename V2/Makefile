ECHO=@echo
COMP=g++
CPPFLAGS=-g -Wall -ansi -pedantic -std=c++11
INT= Util/Algo.h Util/Factory.h Util/Messages.h
REAL=$(INT:.h=.cpp)
BINAIRE= Algo.o Factory.o 
EXE=qualiteAir

$(EXE): $(BINAIRE) Vue/main.o
	$(ECHO) "Editions des liens, création de <$<>"
	$(COMP) -o $(EXE) $(BINAIRE) main.o

%.o: %.cpp
	$(ECHO) "Compilation du fichier <$<>"
	$(COMP) -c  $(CPPFLAGS) $<	

clean:
	@rm -rf *.o run test

