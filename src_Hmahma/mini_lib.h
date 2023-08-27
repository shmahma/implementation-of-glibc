#ifndef MINI_LIB_H
#define MINI_LIB_h

typedef struct MYFILE{

        int fd;
        void* buffer_read;
        void* buffer_write;
        int ind_read;
        int ind_write;
}MYFILE;

//////////////
void* mini_calloc (int size_element, int number_element);
void mini_free(void*);
void mini_exit();
///////////////
void mini_printf(char* string);
void mini_exit_string();
int mini_scanf(char* string ,int size_string);
int mini_strlen(char* s);
int mini_strcpy(char* s, char * d);
int mini_strcmp(char* s1, char* s2);
void mini_perror(char * message);
///////////////
MYFILE* mini_fopen(char* file, char mode );
int mini_fread(void* buffer,int size_element, int number_element, MYFILE* file);
int mini_fwrite(void* buffer,int size_element, int number_element, MYFILE* file);
int mini_fflush(MYFILE* file);
int mini_fclose(MYFILE* file);
int mini_fgetc(MYFILE* file);
int mini_fputc(MYFILE* file, char c);
void mini_exit_buffer_write();
//////////////



#endif
