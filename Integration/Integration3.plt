set terminal png size 1280,720
set xlabel "Time /s"
set ylabel "Tempurature / 'C"
set title "Tempurature Vs. Time"

set grid


set output "Integration3.png"
plot "Integration3.dat" u 1:2 w l lw 2

set terminal wxt background '#00222222'
plot "Integration3.dat" u 1:2 w l lw 2

