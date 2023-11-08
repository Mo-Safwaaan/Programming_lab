approach = MEMOIZATION
all : compile run 
compile : 
	g++ lcs.cpp -D $(approach) -o output 
run : 
	/usr/bin/time -f "time: %E s\nMemory usage: %M KB" ./output 2>&1 | tee result.txt 

