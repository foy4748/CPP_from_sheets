set xlabel "Angle, ThetaM"
set ylabel "Time Period, T"
set title "Time period of a double pendulum"

set grid

set terminal png size 1280,720
set output "Integration9.png"
plot "Integration9.dat" u 1:(column("Time-Period")) w l lw 2

set terminal wxt background '#00222222'
plot "Integration9.dat" u 1:(column("Time-Period")) w l lw 2