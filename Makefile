# A simple makefile for CSE 100 P3

CC=g++
CXXFLAGS=-std=c++11 -g -Wall
LDFLAGS=-g

all: test util.o

test: util.o DictionaryTrie.o DictionaryBST.o DictionaryHashtable.o

benchdict: util.o DictionaryTrie.o DictionaryBST.o DictionaryHashtable.o

benchhash: util.o DictionaryTrie.o DictionaryBST.o DictionaryHashtable.o

DictionaryTrie.o: DictionaryTrie.h

DictionaryBST.o: DictionaryBST.h

DictionaryHashtable.o: DictionaryHashtable.h

util.o: util.h

clean:
	rm -f test *.o *.gch core* *~

