all : compile run
compile: test_cases.o
	g++ -o output test_cases.o
testCases.o:
	g++ -c test_cases.cpp
run:
	/usr/bin/time -f "Time: %e seconds\nMemory: %M KB" ./output 2>&1
