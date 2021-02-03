set grid
set xlabel "Angle, theta (rad)"
set ylabel "Acceleration, a (m/s^2)"
set title "Change of Acceleration with Angle"


set terminal png size 1280,720
set output "Function1.png"
plot "Function1.dat" u 1:(column("Acceleration")) w l lw 2

set terminal wxt background '#00222222'
plot "Function1.dat" u 1:(column("Acceleration")) w l lw 2