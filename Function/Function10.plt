set xlabel "Number of Terms"
set ylabel "Difference between Actual and Algorithm sin(x)"
set title "Comparing Actual value with Algorithm sine function"

set grid

set terminal png size 1280,720
set output "Function10.png"
plot "Function10.dat" u 1:(column("PI/4")) w l lw 2, "" u 1:(column("PI/2")) w l lw 2

set terminal wxt background '#00222222'
plot "Function10.dat" u 1:(column("PI/4")) w l lw 2, "" u 1:(column("PI/2")) w l lw 2