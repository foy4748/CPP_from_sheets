set title "Solving DE with Runge-Kutta Method"
set xlabel "Time /s"
set ylabel "Position /m"
set grid

set terminal png size 1280,720
set output "ODE4.png"
plot "ODE4.dat" u 1:(column("RK-Method")) w l lw 2, "" u 1:(column("Solution")) w l lw 2


set terminal wxt background '#00222222'
plot "ODE4.dat" u 1:(column("RK-Method")) w l lw 2, "" u 1:(column("Solution")) w l lw 2

