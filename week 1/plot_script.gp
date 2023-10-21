set title "Performance Analysis" 
set xlabel "time"
set ylabel "probability of insertions" 
plot "data.txt" using 2:1 with lines
