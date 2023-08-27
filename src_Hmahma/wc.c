#include "mini_lib.h"
#include<sys/types.h>
#include<unistd.h>
#include "inttochar.h"

int wc(char* src){
	MYFILE* file = mini_fopen(src, 'r');
	char* buffer=mini_calloc(1,2048);

	char str[5];
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
	for(int i=0;i<nb;i++){
		if((buffer[i]==' '&& buffer[i+1]!=' '&&buffer[i+1]!='\n'&&buffer[i+1]!='\0')||(buffer[i]=='\n'&&buffer[i+1]!=' '&&buffer[i+1]!='\n'&&buffer[i+1]!='\0'))
			j++;
	}
	
	if(buffer[0]==' ' || buffer[0]=='\n'){
		j--;}
	int_to_char(j+1,str,10);
	mini_printf(str);
	
                

	
	mini_printf("\n");
	mini_free(buffer);

	mini_fclose(file);
	return 0;

}
int main(int argc, char** argv) {


	if (argc == 1) {
		mini_printf("few arguments\n");
		_exit(1);
	}
	else if(argc==2){

		if (wc(argv[1]) != 0)
			_exit(1);
	}

	else{
		mini_printf("lot of arguments\n");
		_exit(1);}
	mini_exit();
}


