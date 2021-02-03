set xlabel "Angle x"
set ylabel "Fourier Outcome"
set grid
set title "Fourier Series"


set terminal png size 1280,720
set output "Function19.png"
plot "Function19.dat" u 1:(column("n=2")) w l, "" u 1:(column("n=3")) w l, "" u 1:(column("n=4")) w l, "" u 1:(column("n=5")) w l, "" u 1:(column("n=6")) w l

set terminal wxt background '#00222222'
plot "Function19.dat" u 1:(column("n=2")) w l, "" u 1:(column("n=3")) w l, "" u 1:(column("n=4")) w l, "" u 1:(column("n=5")) w l, "" u 1:(column("n=6")) w l