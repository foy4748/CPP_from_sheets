set xlabel "Time, t (s)"
set ylabel "Position, x (m)"
set title "Comparing Solution of a DE at different damping coefficient b"
set grid

set terminal png size 1280,720
set output "Function13.png"
plot "Function13.dat" u 1:(column("b=0.3")) w l lw 2, "" u 1:(column("b=4.0")) w l lw 2

set terminal wxt background '#00222222'
plot "Function13.dat" u 1:(column("b=0.3")) w l lw 2, "" u 1:(column("b=4.0")) w l lw 2