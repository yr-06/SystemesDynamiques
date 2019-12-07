reset
set terminal svg 
set output "Vit_li.svg"
set title "Evolution de la vitesse au cours du temps dans le système de Li"
set xlabel "Temps"
set ylabel "Vitesse"
set grid

plot '../src/li.dat' u 1:5 w l
pause -1
