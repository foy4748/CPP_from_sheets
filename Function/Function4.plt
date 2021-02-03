set grid

set yrange [-30:40]
set xrange [-2:2]
set xlabel "x"
set title "Hermite Function (first 5 orders)"

set terminal png size 1280,720
set output "Function4.png"
plot "Function4.dat" u 1:(column("n=0")) w l lw 2, "" u 1:(column("n=1")) w l lw 2, "" u 1:(column("n=2")) w l lw 2, "" u 1:(column("n=3")) w l lw 2, "" u 1:(column("n=4")) w l lw 2

set terminal wxt background '#00222222'
plot "Function4.dat" u 1:(column("n=0")) w l lw 2, "" u 1:(column("n=1")) w l lw 2, "" u 1:(column("n=2")) w l lw 2, "" u 1:(column("n=3")) w l lw 2, "" u 1:(column("n=4")) w l lw 2