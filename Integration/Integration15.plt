set xlabel "Amplitude, A"
set ylabel "Time Period"
set title "Time Period of an anharmonic oscillator"
set grid

set terminal wxt background '#00222222'
plot "Integration15.dat" u 1:(column("Time-Period")) w l lw 2


set terminal png size 1280,720
set output "Integration15.png"
plot "Integration15.dat" u 1:(column("Time-Period")) w l lw 2

