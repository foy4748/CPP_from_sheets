set grid

set terminal png size 1280,720
set output "Integration4_Bessel.png"
plot "Integration4_Bessel.dat" u 1:(column("n=0")) w l lw 2, "" u 1:(column("n=1")) w l lw 2, "" u 1:(column("n=2")) w l lw 2, "" u 1:(column("n=3")) w l lw 2, "" u 1:(column("n=4")) w l lw 2, "" u 1:(column("n=5")) w l lw 2

set output "Integration4_Fresnel.png"
plot "Integration4_Fresnel.dat" u 1:(column("Spherical-Bessel-Function")) w l lw 2


set terminal wxt background '#00222222' 1
plot "Integration4_Bessel.dat" u 1:(column("n=0")) w l lw 2, "" u 1:(column("n=1")) w l lw 2, "" u 1:(column("n=2")) w l lw 2, "" u 1:(column("n=3")) w l lw 2, "" u 1:(column("n=4")) w l lw 2, "" u 1:(column("n=5")) w l lw 2

set terminal wxt background '#00222222' 2
plot "Integration4_Fresnel.dat" u 1:(column("Spherical-Bessel-Function")) w l lw 2