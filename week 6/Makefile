approach = LINEAR 
all : compile run 
compile : 
	g++ matrix_multiplication.cpp -D $(approach) -o output

run :
	/usr/bin/time -f "time : %E s  Memory : %M KB" ./output 2>result.txt
