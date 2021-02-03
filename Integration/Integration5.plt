set grid

set terminal png size 1280,720

set output "Integration5_Fresnel.png"
plot "Integration5_Fresnel.dat" u 1:(column("Fresnel-Sin")) w l lw 2, "" u 1:(column("Fresnel-Cos")) w l lw 2

set output "Integration5_Diffraction.png"
set xlabel "Relative distance from the edge of the knife, u0"
set ylabel "Relative Intensity I/I0"
plot "Integration5_Diffraction.dat" u 1:(column("I/Io")) w l lw 2


set terminal wxt background '#00222222' 1
plot "Integration5_Fresnel.dat" u 1:(column("Fresnel-Sin")) w l lw 2, "" u 1:(column("Fresnel-Cos")) w l lw 2


set terminal wxt background '#00222222' 2
set xlabel "Relative distance from the edge of the knife, u0"
set ylabel "Relative Intensity I/I0"
plot "Integration5_Diffraction.dat" u 1:(column("I/Io")) w l lw 2
