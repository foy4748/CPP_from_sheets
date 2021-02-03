set grid
set xlabel "Angle, x"
set ylabel "Value of tan(x)"
set title "Generating tan(x) function using Bernoulli"

set terminal png size 1280,720
set output "Function6.png"
plot "Function6.dat" u 1:(column("Using-Bernoulli")) w l lw 2, "" u 1:(column("Actual")) w l lw 2

set terminal wxt background '#00222222'
plot "Function6.dat" u 1:(column("Using_Bernoulli")) w l lw 2, "" u 1:(column("Actual")) w l lw 2