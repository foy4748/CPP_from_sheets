set title "Solving 2nd Order DE using Runge-Kutta Method"
set xlabel "Time /s"
set grid

set terminal png size 1280,720
set output "ODE5.png"
plot "ODE5.dat" u 1:(column("Position")) w l lw 3, "" u 1:(column("Velocity")) w l lw 3


set terminal wxt background '#00222222'
plot "ODE5.dat" u 1:(column("Position")) w l lw 3, "" u 1:(column("Velocity")) w l lw 3
