set xlabel "Angle x"
set ylabel "Fourier Outcome"
set grid
set title "Fourier Series"

set xrange [-3.1416:3.1416]

set terminal png size 1280,720
set output "Function18.png"
plot "Function18.dat" u 1:(column("n=2")) w l lw 2, "" u 1:(column("n=3")) w l lw 2, "" u 1:(column("n=4")) w l lw 2, "" u 1:(column("n=5")) w l lw 2, "" u 1:(column("n=6")) w l lw 2, "" u 1:(column("n=7")) w l lw 2, "" u 1:(column("n=8")) w l lw 2

set terminal wxt background '#00222222'
plot "Function18.dat" u 1:(column("n=2")) w l lw 2, "" u 1:(column("n=3")) w l lw 2, "" u 1:(column("n=4")) w l lw 2, "" u 1:(column("n=5")) w l lw 2, "" u 1:(column("n=6")) w l lw 2, "" u 1:(column("n=7")) w l lw 2, "" u 1:(column("n=8")) w l lw 2