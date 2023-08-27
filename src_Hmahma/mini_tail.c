#include "mini_lib.h"
#include<sys/types.h>
#include<unistd.h>
#include "inttochar.h"

int Atoi(char* str)//char to int
{

	int res = 0;

	for (int i = 0; str[i] != '\0'; ++i)
		res = res * 10 + str[i] - '0';


	return res;
}

int nbr_lignes(char* src)//pour savoir le nombre de lignes d un fichier
{
	MYFILE* file =mini_fopen(src, 'r');
        char* buffer=mini_calloc(1,2048);

        if(file == NULL)
        {

                mini_perror(src);

                _exit(1);
        }
        int nb=mini_fread(buffer,sizeof(char),2048,file);
        if(nb==-1){
                return -1;
        }
        int j=0;
        for(int i=0;i<nb;i++){
                if(buffer[i]=='\n')
                        j++;
        }

        if(buffer[nb-1]!='\0' && buffer[nb-1]!='\n'){
		j++;
	}
	mini_free(buffer);

        mini_fclose(file);
        return j;

}

int  mini_tail(char* src,int n){

	MYFILE* file = mini_fopen(src, 'r');
	char* buffer=mini_calloc(1,2048);

	if(file == NULL)
	{       mini_perror(src);

		return -1;;
	}
	int nb=mini_fread(buffer,sizeof(char),2048,file);
	if(nb==-1){
                return -1;
        }
	if(n<0){
        return -1;}

	if(n>=nbr_lignes(src)){
		if(write(STDOUT_FILENO,buffer,mini_strlen(buffer))==-1){
			mini_perror("ERROR");
			return -1;

		}

	}


	else{

		int j=-1;
		int cnt=0;
		for(int i=0;i<nb;i++){
			if(buffer[i]=='\n' && buffer[i+1]!='\0'){
				j=i;
				cnt++;
				if(cnt==nbr_lignes(src)-n){
					break;
				}



			}
		}
		for(int i=j+1;i<nb;i++){

			if(write(STDOUT_FILENO,buffer+i,1)==-1){
				mini_perror("ERROR");

				return -1;

			}

		}}
	mini_free(buffer);

	mini_fclose(file);
	return 0;

}






int main(int argc, char** argv) {


	if (argc == 1) {
		mini_printf("few arguments\n");
		_exit(1);
	}
	else if(argc==2&&mini_strcmp(argv[1],"-n")!=0){

		if (mini_tail(argv[1],200) != 0)
			_exit(1);
	}
	else if(argc==4&&mini_strcmp(argv[1],"-n")==0){
		int n=Atoi(argv[2]);
		if (n<0 || mini_tail(argv[3],n) != 0)
			_exit(1);}


	else{
		mini_printf("lot or few arguments or fault arguments\n");
		_exit(1);}
	mini_exit();
}                      
