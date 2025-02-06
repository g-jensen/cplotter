CC = gcc
DIR = .
SRC = $(DIR)/src
SPEC = $(DIR)/spec
SPECC = $(DIR)/spec/src
MAIN = $(DIR)/main.c
SRC_FILES != find $(SRC) -name '*.c'
SPEC_FILES != find $(SPEC) -name '*.c'

CSFML = -lcsfml-window -lcsfml-system -lcsfml-graphics

main: compile-main
	$(CC) *.o -o cplotter $(CSFML) -lm
	rm -f *.o

spec-auto:
	find . -name '*.[ch]' | entr make spec

spec: compile-spec
	$(CC) *.o -o specc $(CSFML) -lm
	rm -f *.o
	./specc

compile-spec:
	$(CC) -c -DSPECC $(SRC_FILES)
	$(CC) -c $(SPEC_FILES) $(SPECC)/specc.c

compile-main: compile-src
	$(CC) -c $(MAIN)

compile-src:
	$(CC) -c $(SRC_FILES)

clean:
	rm -f *.o