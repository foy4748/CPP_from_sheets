set title "Solving SHM DE using Euler-Cromer Rule"
set xlabel "Time, t (s)"
set grid

set yrange [-1:1]
set xrange [0:10]

set terminal png size 1280,720
set output "1_EC.png"
plot "1_EC.dat" u 1:(column("Position")) w l lw 2, "" u 1:(column("Velocity")) w l lw 2

set terminal x11 background '#00222222'
plot "1_EC.dat" u 1:(column("Position")) w l lw 2, "" u 1:(column("Velocity")) w l lw 2
