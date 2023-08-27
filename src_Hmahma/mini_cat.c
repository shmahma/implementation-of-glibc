#include "mini_lib.h"
#include<sys/types.h>
#include<unistd.h>
#include "inttochar.h"





int mini_cat(char* src){
        MYFILE* file = mini_fopen(src, 'r');
        char* buffer=mini_calloc(1,2048);
        if(file == NULL)
        {
                mini_perror(src);

                return -1;
        }
        if(mini_fread(buffer,sizeof(char),2048,file)==-1){
		return -1;
	
	}
        mini_printf(buffer);
       	mini_free(buffer); 

        mini_fclose(file);
	return 0;
}

int main(int argc, char** argv) {
    

    if (argc == 1) {
        mini_printf("few arguments\n");
        _exit(1);
    }
    else {
        for (int i = 1; i < argc; i++) {
            if (mini_cat(argv[i]) != 0)
                _exit(1);
        }
    }
    mini_exit();
}
