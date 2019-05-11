ECHO=@echo
COMP=g++
CPPFLAGS=-g -Wall -ansi -pedantic -std=c++11
INT= Service.h
REAL=$(INT:.h=.cpp)
BINAIRE=$(INT:.h=.o)

all: $(BINAIRE)

%.o: %.cpp
	$(ECHO) "Compilation du fichier <$<>"
	$(COMP) -c  $(CPPFLAGS) $<

clean:
	@rm -rf *.o run test
