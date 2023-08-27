Compilateur=gcc
Flag=-Wall
Source.c= src_Hmahma/mini_shell.c  src_Hmahma/inttochar.c src_Hmahma/mini_string.c  src_Hmahma/mini_io.c  src_Hmahma/mini_memory.c  src_Hmahma/main.c  src_Hmahma/mini_clean.c src_Hmahma/mini_cp.c  src_Hmahma/mini_grep.c  src_Hmahma/mini_tail.c  src_Hmahma/wc.c src_Hmahma/mini_cat.c   src_Hmahma/mini_echo.c  src_Hmahma/mini_head.c   src_Hmahma/mini_touch.c
 
Source.o= inttochar.o  mini_string.o mini_io.o mini_memory.o



Launch_mini_shell: Clean
	./mini_shell

Clean: Executer
	@rm $(Source.o) main.o mini_shell.o mini_clean.o mini_cp.o mini_grep.o  mini_tail.o  wc.o mini_cat.o  mini_echo.o  mini_head.o  mini_touch.o


Executer: Compiler
	@$(Compilateur)   $(Source.o) wc.o -o  wc
	@$(Compilateur)   $(Source.o) mini_cat.o -o  mini_cat
	@$(Compilateur)   $(Source.o) mini_tail.o -o  mini_tail
	@$(Compilateur)   $(Source.o) mini_head.o -o  mini_head
	@$(Compilateur)   $(Source.o) mini_echo.o -o  mini_echo
	@$(Compilateur)   $(Source.o) mini_grep.o -o  mini_grep
	@$(Compilateur)   $(Source.o) mini_clean.o -o  mini_clean
	@$(Compilateur)   $(Source.o) mini_touch.o -o  mini_touch
	@$(Compilateur)   $(Source.o) mini_cp.o -o  mini_cp





	@$(Compilateur)   $(Source.o) main.o -o  app
	@$(Compilateur)   $(Source.o) mini_shell.o -o  mini_shell


Compiler:
	@$(Compilateur) -c  $(Flag) $(Source.c)


