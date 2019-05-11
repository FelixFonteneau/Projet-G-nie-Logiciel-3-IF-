ECHO=@echo
COMP=g++
CPPFLAGS=-g -Wall -ansi -pedantic -std=c++11
INT= Mesure.h
REAL=$(INT:.h=.cpp)
BINAIRE=$(INT:.h=.o)
EXE=qualiteAir

$(EXE): $(BINAIRE) main.o
	$(ECHO) "Editions des liens, création de <$<>"
	$(COMP) -o $(EXE) $(BINAIRE) main.o

%.o: %.cpp
	$(ECHO) "Compilation du fichier <$<>"
	$(COMP) -c  $(CPPFLAGS) $<

clean:
	@rm -rf *.o run test
