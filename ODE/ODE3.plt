set grid

set xlabel "Time"
set yrange [-2.5:2.5]

set terminal png size 1280,720
set output "ODE3_Euler.png"
set title "Solving DE of SHM using Euler Method"
plot "ODE3_Euler.dat" u 1:(column("Angular_Position")) w l lw 2, "" u 1:(column("Angular_Velocity")) w l lw 2

set output "ODE3_Euler_Cromer.png"
set title "Solving DE of SHM using Euler-Cromer Method"
plot "ODE3_Euler_Cromer.dat" u 1:(column("Angular_Position")) w l lw 2, "" u 1:(column("Angular_Velocity")) w l lw 2


set terminal wxt background '#00222222' 1
set title "Solving DE of SHM using Euler Method"
plot "ODE3_Euler.dat" u 1:(column("Angular_Position")) w l lw 2, "" u 1:(column("Angular_Velocity")) w l lw 2


set terminal wxt background '#00222222' 2
set title "Solving DE of SHM using Euler-Cromer Method"
plot "ODE3_Euler_Cromer.dat" u 1:(column("Angular_Position")) w l lw 2, "" u 1:(column("Angular_Velocity")) w l lw 2