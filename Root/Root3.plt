set grid
set yrange[-35:35]
set xrange[-32:32]
set title "Ploting Fraunhofer Diffraction Maxium Irridiance"
set xlabel "theta"

set terminal png size 1280,720
set output "Root3.png"
plot "Root3.dat" u 1:(column("beta")) w l lw 2, "" u 1:(column("tan(beta)")) w l lw 2

set terminal wxt background '#00222222'
plot "Root3.dat" u 1:(column("beta")) w l lw 2, "" u 1:(column("tan(beta)")) w l lw 2