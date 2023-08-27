#include "mini_lib.h"
#include<sys/types.h>
#include<unistd.h>
#include "inttochar.h"


int mini_grep(char* string,char* src){

	MYFILE* file =mini_fopen(src, 'r');
	char* buffer=mini_calloc(1,2048);

	if(file == NULL)
	{
		mini_perror(src);

		return -1;
	}

	int nb=mini_fread(buffer,sizeof(char),2048,file);
	if(nb==-1){
		return -1;
	}
	int j=0;
	int cnt=1;
	int ind_saut_ligne=-1;
	for(int i=0;i<nb;i++){
		if(buffer[i]=='\n'){
			ind_saut_ligne=i;
			cnt=1;
		}
		if(string[j]==buffer[i]){
			j++;
		}
		else{
			j=0;}
		if(j==mini_strlen(string)){
			if(cnt==1){
				for(int i=ind_saut_ligne+1;buffer[i]!='\n'&&buffer[i]!='\0';i++){
					if(write(STDOUT_FILENO,buffer+i,1)==-1){
						mini_perror("ERROR");
						return -1;

					}

				}
				cnt=0;
				mini_printf("\n");
			}
			else{;}
			j=0;

		}

	}
	mini_free(buffer);

	mini_fclose(file);
	return 0;

}




int main(int argc, char** argv) {


	if (argc == 1||argc==2) {
		mini_printf("few arguments\n");
		_exit(1);
	}
	else if(argc==3){

		if (mini_grep(argv[1],argv[2]) != 0)
			_exit(1);
	}

	else{
		mini_printf("lot of arguments\n");
		_exit(1);}
	_exit(0);
}

