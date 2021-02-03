set grid
set terminal png size 1280,720
set output "Integration13_Fresnel.png"
set title "Fresnel Integrals"
set xlabel "x"
plot "Integration13_Fresnel.dat" u 1:(column("C(u)")) w l lw 2, "" u 1:(column("S(u)")) w l lw 2

reset

set grid
set terminal png size 1280,720
set title "Change Intensity due to Diffraction"
set xlabel "Relative Distance"
set ylabel "Intensity"
set output "Integration13_Diffraction.png"
plot "Integration13_Diffraction.dat" u 1:(column("Diffraction")) w l lw 2

reset

set terminal wxt background '#00222222' 1
set title "Fresnel Integrals"
set xlabel "x"
plot "Integration13_Fresnel.dat" u 1:(column("C(u)")) w l lw 2, "" u 1:(column("S(u)")) w l lw 2

reset

set title "Change Intensity due to Diffraction"
set xlabel "Relative Distance"
set ylabel "Intensity"
set terminal wxt background '#00222222' 2
plot "Integration13_Diffraction.dat" u 1:(column("Diffraction")) w l lw 2
