set xlabel "Mass Number A"
set ylabel "cos(phi)"
set title "Change of Scatter Angle with increasing Mass Number"

set grid

set terminal png size 1280,720
set output "Integration6.png"
plot "Integration6.dat" u 1:(column("Cosine-of-Scattering-Angle")) w l lw 2

set terminal wxt background '#00222222'
plot "Integration6.dat" u 1:(column("Cosine-of-Scattering-Angle")) w l lw 2