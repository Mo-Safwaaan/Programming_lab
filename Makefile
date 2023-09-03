all : compile run
compile: insertion_deletion_end.o
	g++ -o output insertion_deletion_end.o
testCases.o:
	g++ -c insertion_deletion_end.cpp
run:
	./output
