data_structure = DYNAMIC_ARRAY
all : compile run plot
compile: 
	g++ test_cases.cpp -D $(data_structure) -o output
run:
	/usr/bin/time -f "Time: %e seconds\nMemory: %M KB" ./output 2>&1
plot:
	gnuplot plot_script.gp
