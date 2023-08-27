
#include "mini_lib.h"
#include <unistd.h>
#include <errno.h>
#include"inttochar.h"

int BUF_SIZE=100;
char* buffer=NULL;
int ind=-1;
int j=0;//pour savoir si une chaine contient '\n',j==0:ne contient pas '\n',j==1:contient '\n'

void mini_printf(char* string){
	if(ind==-1){

		buffer=mini_calloc(sizeof(char),BUF_SIZE);
		if(buffer==NULL){
			mini_perror("ERROR\n");

			_exit(1);

		}
		ind=0;
	}

	for(int i=0;string[i]!='\0';i++){

		j=0;	
		if(string[i]=='\n'||ind==BUF_SIZE){
			if(string[i]=='\n' && string[i+1]=='\0'){
				j=1;

			}
			if(write(STDOUT_FILENO,buffer,ind)==-1 || write(STDOUT_FILENO,"\n",1)==-1){
				mini_perror("ERROR\n");


			}
			ind=0;
		}
		if(string[i]!='\n'){

			buffer[ind]=string[i];
			ind++;
		}

	}	

//pour gerer le cas:on a pas de retour a la ligne 
//on peut déplacer le code au dessous dans mini_exit_string() mais c'est mieux de le laisser ici comme ca la chaine va etre afficher tout de suite  pas à la fin de programme 
	if(j==0){
		if(write(STDOUT_FILENO,buffer,ind)==-1){
			mini_perror("ERROR\n");




		}
	ind=0;
	}


}

int mini_scanf(char* string ,int size_string)
{

	int n=read(STDIN_FILENO,string,size_string);
	if(n==-1){
		mini_perror("ERROR");
		_exit(1);
	}
	return n;
}


int mini_strlen(char* s){
	int i=0;
	if(s!=NULL){
		while(s[i]!='\0'){
			i++;
		}
		return i;
	}
	return -1;

}

int mini_strcpy(char* s , char* d){
	int i=0;
	if(s!=NULL && d!=NULL){
		while(s[i]!='\0'){
			d[i]=s[i];
			i++;
		}
		d[i]='\0';
		return i;
	}
	return -1;
}
int mini_strcmp(char* s1 , char* s2){

	if(s1!=NULL && s2!=NULL){
		if(mini_strlen(s1)==mini_strlen(s2)){
			for(int i=0;i<mini_strlen(s1);i++){
				if(s1[i]!=s2[i]){
					return 1;//ne sont pas egaux
				}
			}
			return 0;//sont egaux
		}
		else 
			return 1;//ne sont pas egaux
	}

return -1;


}

void mini_perror(char * message){
	
	char buffer[20];
	int_to_char(errno,buffer,3);

	if(errno==ENOENT){
		if(write(STDERR_FILENO,message,mini_strlen(message))==-1||write(STDERR_FILENO,":Aucun fichier ou répertoire de ce type:",mini_strlen(":Aucun fichier ou répertoire de ce type:"))==-1||write(STDERR_FILENO,buffer,mini_strlen(buffer))==-1||write(STDERR_FILENO,"\n",1)==-1){
                        _exit(1);}
	}
	if(errno==EACCES){
                if(write(STDERR_FILENO,message,mini_strlen(message))==-1||write(STDERR_FILENO,":Autorisation refusée. Le paramètre d’autorisation du fichier n’autorise pas l’accès spécifié:",mini_strlen(":Autorisation refusée. Le paramètre d’autorisation du fichier n’autorise pas l’accès spécifié:"))==-1||write(STDERR_FILENO,buffer,mini_strlen(buffer))==-1||write(STDERR_FILENO,"\n",1)==-1){
                        _exit(1);}
        }
	

	
	
	if(errno==EAGAIN){
		if(write(STDERR_FILENO,message,mini_strlen(message))==-1||write(STDERR_FILENO,":le descripteur de flux est marqué comme non-bloquant et aucune données n'est disponible pour l'instant:",mini_strlen(":le descripteur de flux est marqué comme non-bloquant et aucune données n'est disponible pour l'instant:"))==-1||write(STDERR_FILENO,buffer,mini_strlen(buffer))==-1||write(STDERR_FILENO,"\n",1)==-1){
			_exit(1);}

	if(errno==EBADF){

                if(write(STDERR_FILENO,message,mini_strlen(message))==-1||write(STDERR_FILENO,":le descripteur de flux (MYFILE *) passé en paramètre est invalide:",mini_strlen(":le descripteur de flux (MYFILE *) passé en paramètre est invalide:"))==-1||write(STDERR_FILENO,buffer,mini_strlen(buffer))==-1||write(STDERR_FILENO,"\n",1)==-1){
                        _exit(1);}}
	if(errno==EDOM){

                if(write(STDERR_FILENO,message,mini_strlen(message))==-1||write(STDERR_FILENO,":certaines fonctions mathématiques peuvent déclencher une erreur de domaine:" ,mini_strlen(":certaines fonctions mathématiques peuvent déclencher une erreur de domaine:"))==-1||write(STDERR_FILENO,buffer,mini_strlen(buffer))==-1||write(STDERR_FILENO,"\n",1)==-1){
                        _exit(1);}}
	if(errno==EFAULT){

                if(write(STDERR_FILENO,message,mini_strlen(message))==-1||write(STDERR_FILENO,":un pointeur manipulé par votre programme n'adresse pas un espace mémoire valide:",mini_strlen(":un pointeur manipulé par votre programme n'adresse pas un espace mémoire valide:"))==-1||write(STDERR_FILENO,buffer,mini_strlen(buffer))==-1||write(STDERR_FILENO,"\n",1)==-1){
                        _exit(1);}}
	if(errno==EIO){

                if(write(STDERR_FILENO,message,mini_strlen(message))==-1||write(STDERR_FILENO,":une erreur d'accès physique au flux vient d'être générée:",mini_strlen(":une erreur d'accès physique au flux vient d'être générée:"))==-1||write(STDERR_FILENO,buffer,mini_strlen(buffer))==-1||write(STDERR_FILENO,"\n",1)==-1){
                        _exit(1);}}
	 if(errno==ERANGE){

                if(write(STDERR_FILENO,message,mini_strlen(message))==-1||write(STDERR_FILENO,":la valeur, spécifiée à la fonction ayant déclenchée l'erreur,n'est pas dans une plage de valeurs autorisées:",mini_strlen(":la valeur, spécifiée à la fonction ayant déclenchée l'erreur,n'est pas dans une plage de valeurs autorisées:"))==-1||write(STDERR_FILENO,buffer,mini_strlen(buffer))==-1||write(STDERR_FILENO,"\n",1)==-1){
                        _exit(1);}}


}
}


void mini_exit_string()
{

	if(buffer!=NULL){
		mini_free(buffer);
        	ind=-1;}
	
}
