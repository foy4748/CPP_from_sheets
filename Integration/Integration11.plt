set grid

set terminal png size 1280,720
set output "Integration11_Bessel.png"
plot "Integration11_Bessel.dat" u 1:(column("n=0")) w l lw 2, "" u 1:(column("n=1")) w l lw 2, "" u 1:(column("n=2")) w l lw 2, "" u 1:(column("n=3")) w l lw 2

set terminal wxt background '#00222222' 1
plot "Integration11_Bessel.dat" u 1:(column("n=0")) w l lw 2, "" u 1:(column("n=1")) w l lw 2, "" u 1:(column("n=2")) w l lw 2, "" u 1:(column("n=3")) w l lw 2

set terminal png size 1280,720
set xlabel "Distance"
set ylabel "Radiation"
set title "Radiation Vs. Distance"
set output "Integration11_Radiation.png"
plot "Integration11_Radiation.dat" u 1:(column("Radiation")) w l lw 2

set terminal wxt background '#00222222' 2
plot "Integration11_Radiation.dat" u 1:(column("Radiation")) w l lw 2