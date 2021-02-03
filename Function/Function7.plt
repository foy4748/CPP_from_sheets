set xlabel "Number of Terms"
set ylabel "Difference Between Actual and Algorithm Root"
set title "Comparing an Algorithm for Square root with built-in root function"


set terminal png size 1280,720
set output "Function7.png"
plot "Function7.dat" u 1:(column("Difference")) w l lw 2

set terminal wxt background '#00222222'
plot "Function7.dat" u 1:(column("Difference")) w l lw 2
