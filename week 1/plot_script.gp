set term x11
set title "Performance Analysis" 
set xlabel "Probability of Insertions"
set ylabel "Time" 
set term pngcairo 
set output "output.png"
plot "data.txt" using 1:2 with lines
