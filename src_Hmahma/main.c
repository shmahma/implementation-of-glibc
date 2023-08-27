#include<stdio.h>
#include"mini_lib.h"
#include<string.h>
#include <unistd.h>

#define DEBUG 1


int main(int argc,char **argv){

//////////////////////////
//test pour mini_calloc et mini_free
	char *s=mini_calloc(sizeof(char),7);
	char *s1=mini_calloc(sizeof(char),7);


#ifdef DEBUG

	printf("%p\n",s);
	printf("%p\n",s1);
#endif
	mini_free(s);
	mini_free(s1);

	s=mini_calloc(sizeof(char),7);
	s1=mini_calloc(sizeof(char),7);


#ifdef DEBUG


	printf("%p\n",s);
	printf("%p\n",s1);
		
#endif

        
/////////////////////////////////////////////
//test pour mini_scanf et mini_printf
	char*tst=mini_calloc(sizeof(char),30);
	mini_printf("entrez votre chaine: ");

	if(mini_scanf(tst,40)>30){
		mini_perror("error,tst plus peitte no");
	        _exit(1);	
	}
	else{
	
	mini_printf("valeur de votre chaine est:");

	mini_printf(tst);
	mini_printf("\n");
	}
	
/////////////////////////////////////////////
//test pour mini_strlen et mini_strcpy et mini_strcmp 

	mini_strcpy("hello\n",s);
	mini_printf("valeur de s est:");
	mini_printf(s);
	mini_printf("\n");
	mini_strcpy("hi\n",s1);
	mini_printf("valeur de s1 est:");
	mini_printf(s1);
	mini_printf("\n");
#ifdef DEBUG

	printf("longueur de s1: %d\n",mini_strlen(s1));
	printf("comparaison entre s1 et s:%d\n",mini_strcmp(s1,s));
	printf("comparaison entre votre chaine et s1:%d\n",mini_strcmp(s1,tst));

  

#endif
/////////////////////////////////////////////
//test pour fwrite fread fputc fgetc fopen 
	if(argc!=2)
		mini_printf("réexecuter maintenant en passant un fichier en argument de app\n");
	
	if(argc==2){
		mini_printf("entrez une chaine de caractere que vous voulez ajouter à votre fichier:");
		MYFILE *mf=mini_fopen(argv[1],'b');
		char* string=mini_calloc(sizeof(char),30);
		char* test=mini_calloc(sizeof(char),30);
		mini_scanf(string,30);
		mini_fread(test,sizeof(char),5,mf);
		mini_fwrite(string,sizeof(char),mini_strlen(string),mf);
		mini_printf("c'est fait\n");
		mini_printf("j'ai ajouter en plus  le caractere  1 à la fin pour tester fputc \n");
		mini_fputc(mf,'1');
		mini_printf("je vais afficher les 6 premiers caracteres de votre fichier avec fgetc et fread(si votre fichier est vide au depart rien n'est afficher)\n");
		test[5]=mini_fgetc(mf);
		mini_printf(test);

		mini_fclose(mf);

		
	}


	mini_exit();
}
