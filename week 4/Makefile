approach = TABULATION 
all : compile run 
compile : 
	g++ matrix_chain.cpp -D $(approach) -o output
run : 
	/usr/bin/time -f "time : %e second \nMemory : %M KB" ./output 2>&1
