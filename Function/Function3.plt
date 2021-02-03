set xlabel "Time, t (s)"
set ylabel "Velocity, v(t) (ms^-1)"
set grid
set title "Velocity Vs. Time Plot"
set terminal png size 1280,720
set output "Function3.png"
plot "Function3.dat" u 1:(column("Velocity")) w l lw 2

set terminal wxt background '#00222222'
plot "Function3.dat" u 1:(column("Velocity")) w l lw 2