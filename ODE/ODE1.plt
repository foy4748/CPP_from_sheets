set xlabel "Time /s"
set ylabel "Position /m"
set title "Comparing Euler method solution with actual solution"
set grid

set terminal wxt background '#00222222'
plot "ODE1.dat" u 1:(column("Euler_Method")) w l lw 2, "" u 1:(column("Actual_Solution")) w l lw 2 

set terminal png size 1280,720
set output "ODE1.png"
plot "ODE1.dat" u 1:(column("Euler_Method")) w l lw 2, "" u 1:(column("Actual_Solution")) w l lw 2 

set terminal wxt