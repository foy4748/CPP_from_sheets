set xlabel "x"
set ylabel "erf(x)"
set title "Gaussian Error Function"
set grid

set terminal png size 1280,720
set output "Function17.png"
plot "Function17.dat" u 1:(column("erf(x)")) w l lw 2

set terminal wxt background '#00222222'
plot "Function17.dat" u 1:(column("erf(x)")) w l lw 2
