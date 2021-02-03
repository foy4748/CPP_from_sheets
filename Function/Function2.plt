set logscale x 10

set xlabel "Number of Terms Added"
set ylabel "Difference between actual and Program value"
set title "Exponentially reduction of error with increasing terms"

set terminal png size 1280,720
set output "Function2.png"
plot "Function2.dat" u 1:(column("Difference")) w l lw 2

set terminal wxt background '#00222222'
plot "Function2.dat" u 1:(column("Difference")) w l lw 2