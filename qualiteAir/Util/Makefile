ECHO=@echo
COMP=g++
CPPFLAGS=-g -Wall -ansi -pedantic -std=c++11 -D MAP
INT= Factory.h Messages.h Algo.h
REAL=$(INT:.h=.cpp) test.cpp
BINAIRE=$(INT:.h=.o) test.o
EXE= testOut

$(EXE): $(BINAIRE) 
	$(ECHO) "Editions des liens, création de <$<>"
	$(COMP) -o $(EXE) $(BINAIRE) 

all: $(BINAIRE) test.o

%.o: %.cpp
	$(ECHO) "Compilation du fichier <$<>"
	$(COMP) -c  $(CPPFLAGS) $<

clean:
	@rm -rf *.o run test
