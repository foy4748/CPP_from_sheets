set grid

set terminal png size 1280,720
set output "Integration10_Bessel.png"
plot "Integration10_Bessel.dat" u 1:(column("n=0")) w l lw 2, "" u 1:(column("n=1")) w l lw 2, "" u 1:(column("n=2")) w l lw 2, "" u 1:(column("n=3")) w l lw 2

set terminal wxt background '#00222222' 1
plot "Integration10_Bessel.dat" u 1:(column("n=0")) w l lw 2, "" u 1:(column("n=1")) w l lw 2, "" u 1:(column("n=2")) w l lw 2, "" u 1:(column("n=3")) w l lw 2



set terminal png size 1280,720
set xlabel "q"
set ylabel "Transmitted(q)"
set output "Integration10_Transmitted.png"
plot "Integration10_Transmitted.dat" u 1:(column("Transmitted(q)")) w l lw 2

set terminal wxt background '#00222222' 2
set xlabel "q"
set ylabel "Transmitted(q)"
plot "Integration10_Transmitted.dat" u 1:(column("Transmitted(q)")) w l lw 2
