set xlabel "x"
set ylabel "erf(x)"
set title "Gaussian Error Function"

set grid

set terminal png size 1280,720
set output "Integration7.png"
plot "Integration7.dat" u 1:(column("Error-Function")) w l lw 2


set terminal wxt background '#00222222'
plot "Integration7.dat" u 1:(column("Error-Function")) w l lw 2