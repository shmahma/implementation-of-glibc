#include "mini_lib.h"
#include<sys/types.h>
#include<unistd.h>
#include "inttochar.h"





int mini_clean(char *name)
{


	MYFILE* fname = mini_fopen(name, 'w');

	if(fname == NULL)
	{
		mini_perror(name);

		return -1;
	}


	mini_fclose(fname);
	return 0;
}
int main(int argc, char** argv) {


	if (argc == 1) {
		mini_printf("few arguments\n");
		_exit(1);
	}
	else {
		for (int i = 1; i < argc; i++) {
			if (mini_clean(argv[i]) != 0)
				_exit(1);
		}
	}
	mini_exit();
}

