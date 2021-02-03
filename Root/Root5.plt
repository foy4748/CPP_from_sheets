set grid

set terminal png size 1280,720
set output "Root5.png"
plot "Root5.dat" u 1:(column("m")) w l lw 2, "" u 1:(column("tanh(J*m/T)")) w l lw 2

set terminal wxt background '#00222222'
plot "Root5.dat" u 1:(column("m")) w l lw 2, "" u 1:(column("tanh(J*m/T)")) w l lw 2