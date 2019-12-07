reset
set terminal svg 
set output "Vit_lorenz.svg"
set title "Evolution de la vitesse au cours du temps dans le système de Lorenz"
set xlabel "Temps"
set ylabel "Vitesse"
set grid

plot '../src/lorenz.dat' u 1:5 w l
pause -1

