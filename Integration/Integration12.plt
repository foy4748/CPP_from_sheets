set grid
set terminal png size 1280,720
set output "Integration12_Elliptic.png"
set xlabel "m"
set title "Elliptic Integrals"
plot "Integration12_Elliptic.dat" u 1:(column("K(m)")) w l lw 2, "" u 1:(column("E(m)")) w l lw 2

reset

set grid
set terminal png size 1280,720
set output "Integration12_Period.png"
set xlabel "Angle, thetaM"
set ylabel "Period"
set title "Change of Time Period with thetaM"
plot "Integration12_Period.dat" u 1:(column("Time-Period")) w l lw 2

reset

set terminal wxt background '#00222222' 1
set xlabel "m"
set title "Elliptic Integrals"
plot "Integration12_Elliptic.dat" u 1:(column("K(m)")) w l lw 2, "" u 1:(column("E(m)")) w l lw 2

reset

set terminal wxt background '#00222222' 2
set xlabel "Angle, thetaM"
set ylabel "Period"
set title "Change of Time Period with thetaM"
plot "Integration12_Period.dat" u 1:(column("Time-Period")) w l lw 2