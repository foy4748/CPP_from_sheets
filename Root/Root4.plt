set grid
set yrange[-5:5]

set terminal png
set output "Root4.png"
plot "Root4.dat" u 1:(column("-cot(x)")) w l lw 2, "" u 1:(column("Potential")) w l lw 2

set terminal wxt background '#00222222'
plot "Root4.dat" u 1:(column("-cot(x)")) w l lw 2, "" u 1:(column("Potential")) w l lw 2