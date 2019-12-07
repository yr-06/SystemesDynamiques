reset
set terminal svg 
set output "li.svg"
set autoscale fix
set title " Système Dynamique de Li"
set xlabel "Coordonnée x"
set ylabel "Coordonnée y"
set zlabel "Coordonnée z"
set colorbox

splot '../src/li.dat' u 2:3:4 w l
pause -1
