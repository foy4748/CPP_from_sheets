set xlabel "x"
set title "Legendre Function"
set grid

set terminal png size 1280,720
set output "Function14.png"
plot "Function14.dat" u 1:(column("n=0")) w l lw 2, "" u 1:(column("n=1")) w l lw 2, "" u 1:(column("n=2")) w l lw 2, "" u 1:(column("n=3")) w l lw 2

set terminal wxt background '#00222222'
plot "Function14.dat" u 1:(column("n=0")) w l lw 2, "" u 1:(column("n=1")) w l lw 2, "" u 1:(column("n=2")) w l lw 2, "" u 1:(column("n=3")) w l lw 2