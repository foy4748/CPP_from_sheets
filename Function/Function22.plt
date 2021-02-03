set xlabel "s"
set title "Reimann-Zeta Function & Euler-Mascheroni Function"


set grid

set terminal png size 1280,720
set output "Function22.png"
plot "Function22.dat" u 1:(column("Zeta(s)")) w l lw 2, "" u 1:(column("Euler-Mascheroni(s)")) w l lw 2

set terminal wxt background '#00222222'
plot "Function22.dat" u 1:(column("Zeta(s)")) w l lw 2, "" u 1:(column("Euler-Mascheroni(s)")) w l lw 2