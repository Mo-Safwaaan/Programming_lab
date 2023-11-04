approach = MEMOIZATION
all : compile run 
compile : 
	g++ lcs.cpp -D $(approach) -o output 
run : 
	/usr/bin/time -f "User time: %U s\nMemory usage: %M KB" ./output

