set title "Comparing Algorithm cos(x) with actual function"
set xlabel "Number of Terms"
set ylabel "Difference"
set grid

set terminal png size 1280,720
set output "Function16.png"
plot "Function16.dat" u 1:(column("x=PI/4.0")) w l lw 2, "" u 1:(column("x=PI/3.0")) w l lw 2

set terminal wxt background '#00222222'
plot "Function16.dat" u 1:(column("x=PI/4.0")) w l lw 2, "" u 1:(column("x=PI/3.0")) w l lw 2