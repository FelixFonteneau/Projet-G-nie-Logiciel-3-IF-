ECHO=@echo
COMP=g++
CPPFLAGS=-g -Wall -ansi -pedantic -std=c++11
INT= 
REAL=$(INT:.h=.cpp)
BINAIRE=$(INT:.h=.o)

main.o: main.cpp
	$(ECHO) "Compilation du fichier <main>"
	$(COMP) -c  $(CPPFLAGS) $<

clean:
	@rm -rf *.o run test
