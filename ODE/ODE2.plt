set title "Comparing Euler Method Result with Actual Solution"
set xlabel "Time /s"
set ylabel "Position /m"
set grid

set terminal png size 1280,720
set output "ODE2.png"
plot "ODE2.dat" u 1:(column("Euler-Method")) w l lw 2, "" u 1:(column("Solution")) w l lw 2

set terminal wxt background '#00222222'
plot "ODE2.dat" u 1:(column("Euler-Method")) w l lw 2, "" u 1:(column("Solution")) w l lw 2