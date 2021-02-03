set xlabel "Time, t (s)"
set ylabel "Height, h (m)"
set title "Change of height with time of a falling object"
set grid


set label 't = 14.7380, h = 0' at 14.7380,0 point pt 20 offset 1,1

set terminal png size 1280,720
set output "Function11.png"
plot "Function11.dat" u 1:(column("Height")):(sprintf("%d",$1)) w l lw 2

set terminal wxt background '#00222222'
plot "Function11.dat" u 1:(column("Height")) w l lw 2
