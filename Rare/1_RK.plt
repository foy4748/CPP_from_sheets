set title "Solving SHM DE using Runge Kutta Rule"
set xlabel "Time, t (s)"
set grid

set yrange [-1:1]

set terminal png size 1280,720
set output "1_RK.png"
plot "1_RK.dat" u 1:(column("Position")) w l lw 2, "" u 1:(column("Velocity")) w l lw 2

set terminal wxt background '#00222222'
plot "1_RK.dat" u 1:(column("Position")) w l lw 2, "" u 1:(column("Velocity")) w l lw 2
