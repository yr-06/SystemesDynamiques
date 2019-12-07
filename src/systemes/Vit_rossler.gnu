reset
set terminal svg 
set output "rossler.svg"
set title "Evolution de la vitesse au cours du temps dans le système de Rossler"
set xlabel "Temps"
set ylabel "Vitesse"
set grid

plot '../src/rossler.dat' u 1:5 w l
pause -1

