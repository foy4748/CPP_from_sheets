set xlabel "x"
set ylabel "Error Function"
set title "Gaussian Error Function"

set grid

set terminal png size 1280,720
set output "Integration8.png"
plot "Integration8.dat" u 1:(column("Error-Function")) w l lw 2

set terminal wxt background '#00222222'
plot "Integration8.dat" u 1:(column("Error-Function")) w l lw 2