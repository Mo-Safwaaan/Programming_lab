all : compile run
compile: test_cases.o
	g++ -o output test_cases.o
testCases.o:
	g++ -c test_cases.cpp
run:
	./output
