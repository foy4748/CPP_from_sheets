set title "Comparing Factorial function with Ramanujan Factorial (logscale used)"
set xlabel "n"
set ylabel "(|n! - Ramanujan(n)|)/n!"

set grid
set logscale y 10
set xtics (2,3,4,5,6,7,8,9,10,11,12)

set terminal png size 1280,720
set output "Function20.png"
plot "Function20.dat" u 1:(column("Percentage-Error")) w lp pt 20 lw 2

set terminal wxt background '#00222222'
plot "Function20.dat" u 1:(column("Percentage-Error")) w lp pt 20 lw 2