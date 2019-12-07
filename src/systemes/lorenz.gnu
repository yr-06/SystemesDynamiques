reset
set terminal svg 
set output "lorenz.svg"
set autoscale fix
set title " Système Dynamique de Lorenz"
set xlabel "Coordonnée x"
set ylabel "Coordonnée y"
set zlabel "Coordonnée z"
set colorbox

splot '../src/lorenz.dat' u 2:3:4 w l
pause -1

