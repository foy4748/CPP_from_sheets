set title "Solving Double Pendulum Problem using Runge-Kutta Method"
set xlabel "Time"
set grid

set terminal png size 1280,720
set output "2_RK.png"
plot "2_RK.dat" u 1:(column("String-Length")) w l lw 2, "" u 1:(column("Angular-Position")) w l lw 2

set terminal wxt background '#00222222'
plot "2_RK.dat" u 1:(column("String-Length")) w l lw 2, "" u 1:(column("Angular-Position")) w l lw 2
