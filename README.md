# SystemesDynamiques
Projet L2S3 Informatique

Membres du binôme :
Alicia CANDE, nom github : Alicia105
Yaël RUIMY, nom github : yr-06

Le but de ce projet est de modéliser la trajectoire d'un point dans l'espace à l'aide des équations de différents systèmes
dynamiques décrivant ses coordonnées au cours du temps.

L'utilisation du programme se fait normalement en entrant cette commande cd/SystemesDynamiques/src pour parvenir au bon sous-dossier.
On executera ensuite l'éxécutable main.exe avec la commande suivante:  ./main.exe

Le programme va ainsi demander à l'utlisateur de choisir les coordonnées du point ainsi que le temps sur lequel on observe sa trajectoire
et l'incrément de temps entre 2 positions succesives noté dt.
L'utilisateur devra ensuite choisir le système dynamique qu'il veut et en entrer les paramètres.
Des paramètres indicatifs sont donnés dans les commentaires des .c des sytèmes dynamiques.

Le programme génèrera ensuite un fichier qui sera ensuite utiliser par gnuplot pour afficher une image de la trajectoire obtenu et la courbe de
la vitesse du point.


Si le programme ne fonctionne pas en premier lieu il sera nécessaire de regénérer les différentes bibliothèques en se plaçant dans le sous-dossier
SystemesDynamiques/src/systemes

On utilisera ensuite la commande   make -f lib"nom de la bibliotheques".mk en commençant par la bibliothèque libpoint.a (ont appliquera la
commande dans le sous-dossier point) puis par la bibliothèque libtemps.a (la commande se fera alors dans le sous-dossier Temps).
On fera de même avec les bibliothèques des différents systèmes dynamiques se trouvant dans le sous-dossier systemes.

Une fois réaliser on se place dans le sous-dossier src et on entre la commande make avant de pouvoir utiliser l'executable.

