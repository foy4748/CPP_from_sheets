set grid
set xrange[-12:12]
set yrange[-7:9]

set terminal png size 1280,720
set output "Root_Improved.png"
plot "Root_function.txt" u 1:(column("Function-Values")) w l lw 2
set output "Root_Improved.png"
replot "Root_values.txt" u 1:(column("Roots")):(sprintf("(%f)", $1)) with labels point  pt 7 offset char 5,-1 notitle


set terminal wxt
plot "Root_function.txt" u 1:(column("Function-Values")) w l lw 2
replot "Root_values.txt" u 1:(column("Roots")):(sprintf("(%f)", $1)) with labels point  pt 7 offset char 5,-1 notitle