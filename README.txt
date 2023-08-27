//Dans les fichiers sources vous trouverez deux fichiers en plus qui sont:
//inttochar.c/.h:qui permet de transformer un entier en char.
//j'ai créé un Makefile qui va tout compiler et génerer les éxecutables qui sont mini_shell(pour mini_shell.c) , app(pour main.c) ,mini_cp(mini_cp.c),etc.



//Réponse aux questions:

QUESTION 5:On initialise le buffer avec des '\0' comme ça on est sûr qu'on aura pas des carcteres ajouter à la fin de chaque  buffer(c'est plus sécurisé d'ajouter les '\0').

QUESTION 6:La fonction "free" sert à restituer l'espace que l'on avait alloué avec calloc ou malloc.Free ne libère pas vraiment la mémoire,juste il modifie l'état de l'espace memoire alloué pour informer le compilateur qu'il n'est plus utilisable,comme ça cet espace peut etre utiliser par un autre pointeur après le free,et si cette espace est déjà plein il sera remplacer par des '\0'.

QUESTION 12:Pour tester mini_calloc et mini_free il suffit de créer un pointeur et lui allouer la mémoire avec mini_calloc,après on affiche l'adresse pointer par ce pointeur,après on applique mini_free sur ce pointeur,et on realloue la mémoire pour ce meme pointeur avec mini_calloc(avec une taille inférieur ou égale à la taille précedente)et on verifie qu'il pointe sur la meme adresse précédente. 

QUESTION 17:Si on essaye d'afficher une unique chaîne de caractères qui ne contient pas de saut de ligne on ne va pas arriver,en effet on aura le buffer qui contient la chaine qu'on veut afficher mais rien ne va etre afficher,pour résoudre ce probléme on peut créer une variable j pour savoir si une chaine contient un \n (j==1:contient un \n,j==0:ne contient pas de \n) et donc si j=0 on affiche le contenu avec write et on remet l'indice à 0.

QUESTION 18: j'ai créer un mini_exit_string() qui va etre ensuite appeler par mini_exit() et cette fonction va libere l'espace allouer par le buffer et va remettre l'indice à -1;  

Question 20:dans mini_scanf,si le nombre de caractères saisis est égal(ou superieur) à la taille du buffer, premierement on aura pas de place pour ajouter '\0' à la fin,ainsi on peut entrer dans une zone memoire non allouée et cela peut generer des segmentation fault,donc il faut toujours allouer la bonne taille memoire pour notre buffer qui va contenir la chaine saisie.

QUESTION 22:
-mini_strlen(char* s) retourne le nombre de caractère de s jusqu’a un '\0',donc si la chaine s ne contient pas de '\0' on peut avoir des resultas non attendu(voire des segmentation faults),donc 
il faut tout le temps verifier si on ajouter un '\0' à la fin ou non.
-mini_strcpy(char* s, char *d) copie la chaîne s dans d donc si la taille de d est plus inferieur que la taille de s cela peut generer des erreurs.donc il faut toujours passé en argument une chaine de caractere d de taille plus grande que s.
-mini_strcmp(char* s1, char* s2) compare les chaînes s1 et s2, donc il faut commencer d'abord par comparer mini_strlen(s1) et mini_strlen(s2),s'il sont different on retourne 1(ca veut dire different)
et cela va diminuer la complexité de la fonction (ca veut dire on ne va pas entrer dans une boucle pour rien).

En plus,ces fonctions renvoient à chaque fois un nombre qui correspond soit au nombre de caractere lu,soit à autre chose,donc pour la sécurité il faut renvoyer un -1 au cas d'erreur.

QUESTION 34:Si le programme se termine alors que le buffer d’écriture n'est pas plein,le contenu du buffer ne sera pas ajouter au fichier.Donc pour corriger ce problème il faut forcer l'écritutre du contenu du buffer non plein,pour cela j'ai ajouter une fonction mini_exit_buffer_write() qui va etre en suite appelé par mini_exit() et a comme role d'ajouter le contenu du buffer non plein dans le fichier et de vider la mémoire(j'ai passé par un pointeur temp qui contient l'adresse de MYFILE courente).

Question 40: On peut comparer le temps d'execution de deux programmes et voir lequel est le plus rapide (comme on a fait lors du td sur cp).
:wq! 
