#include "mini_lib.h"
#include<sys/types.h>
#include<unistd.h>
#include "inttochar.h"

void  mini_echo(char* string){

	mini_printf(string);


}

int main(int argc, char* argv[])
{

	if(argc ==1 ){
		mini_printf("few arguments\n");
		_exit(1);

	}
	else if(argc >= 2){
		for(int i=1;i<argc;i++){
			mini_echo(argv[i]);
			mini_echo(" ");
		
			}
		mini_printf("\n");}
		
	
	mini_exit();
}





