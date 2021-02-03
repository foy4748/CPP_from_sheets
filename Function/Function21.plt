set title "Difference between actual and algorithm tan inverse function"
set xlabel "Number of Terms, n"
set ylabel "Difference"

set grid

set terminal png size 1280,720
set output "Function21.png"
plot "Function21.dat" u 1:(column("Difference")) w l lw 2\


set terminal wxt background '#00222222'
plot "Function21.dat" u 1:(column("Difference")) w l lw 2