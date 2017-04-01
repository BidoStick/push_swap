# push_swap
Projet 42 consistant à trier une pile de nombres.
On a à notre disposition 2 piles A et B. On doit trier la pile A en effectuant une série de commandes.

# Programmes

Usage:
./checker "<nbrs>"
./push_swap "<nbrs>"
ARG="<nbrs>"; ./push_swap $ARG | ./checker $ARG

# Checker
Programme qui reçoit sur l'entrée standards les nombres les placer dans la pile A.
Va lire les commandes reçus sur la sortie standard puis les effectuer.
A la fin aprés un CTRL + D va vérifier si la pile A est trier.
Si c'est le cas checker écris sur la sortie standard "OK" sinon "Error".

# Push_Swap
Programme qui contient un algorithme de tri (pris exemple sur Quicksort).
Il reçoit sur l'entrée standard les nombres.
Il va effectuer une séries de commandes et les écrires sur la sortie standard.
