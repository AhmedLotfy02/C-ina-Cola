# Define targets
all: a.exe

# Define dependencies
.PHONY: clean

# Rule for generating parser (using bison)
main.tab.c: main.y
	bison main.y -d

# Rule for generating scanner (using flex)
lex.yy.c: main.l
	flex main.l

# Rule for compiling and linking the executable
a.exe: main.tab.c lex.yy.c
	gcc -g ./main.tab.c ./lex.yy.c -o a.exe

# Rule for running with functions.c
run: a.exe ./test/functions.c
	./a.exe < ./test/functions.c

# Rule for cleaning intermediate files
clean:
	rm -f main.tab.c lex.yy.c a.exe


