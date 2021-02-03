set xrange[0:20]
set yrange [-0.3:1]
set grid

set title "Solving Lane Emden DE using Euler-Cromer method"
set xlabel "Time"
set ylabel "Position"
set grid

set terminal png size 1280,720
set output "3_EC.png"
plot "3_EC.dat" u 1:(column("s=0")) w l lw 2, "" u 1:(column("s=1")) w l lw 2, "" u 1:(column("s=2")) w l lw 2, "" u 1:(column("s=3")) w l lw 2

set terminal wxt background '#00222222'
plot "3_EC.dat" u 1:(column("s=0")) w l lw 2, "" u 1:(column("s=1")) w l lw 2, "" u 1:(column("s=2")) w l lw 2, "" u 1:(column("s=3")) w l lw 2
