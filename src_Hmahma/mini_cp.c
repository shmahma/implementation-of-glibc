#include "mini_lib.h"
#include<sys/types.h>
#include<unistd.h>
#include "inttochar.h"



int  mini_cp(char* src,char* dest){
	MYFILE* fsrc= mini_fopen(src, 'r');
	MYFILE* fdest= mini_fopen(dest, 'w');

	char* buffer=mini_calloc(1,2048);

	if(fsrc == NULL)
	{
		mini_perror(src);

		return -1;
	}
	int nb=mini_fread(buffer,sizeof(char),2048,fsrc);
	if(nb==-1){
		return -1;}

	if(mini_fwrite(buffer,sizeof(char),nb,fdest)==-1){
			return -1;
	}
	mini_free(buffer);

	mini_fclose(fsrc);
	mini_fclose(fdest);
	return 0;
	


}
int main(int argc, char** argv) {


	if (argc == 1 || argc ==2) {
		mini_printf("few arguments\n");
		_exit(1);

	}
	else if(argc ==3){

		if (mini_cp(argv[1],argv[2]) != 0)
			_exit(1);
	}

	else{
		mini_printf("lot of arguments\n");
		_exit(1);
	}
	mini_exit();
}
