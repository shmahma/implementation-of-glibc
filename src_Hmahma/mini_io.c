#include "mini_lib.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int IOBUFFER_SIZE=2048;



MYFILE* temp=NULL;//pour proposer une solution si le buffer_write n'est pas plein 


MYFILE* mini_fopen(char* file, char mode){

	MYFILE* mf=mini_calloc(sizeof(struct MYFILE),1);
	if(mf!=NULL){
		mf->ind_read=-1;
		mf->ind_write=-1;
		mf->buffer_read=NULL;
		mf->buffer_write=NULL;

		if(mode=='r'){

			mf->fd=open(file, O_RDONLY);

		}
		else if(mode=='w'){

			mf->fd=open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH |S_IWOTH);

		}
		else if(mode=='b'){

			mf->fd=open(file, O_RDWR| O_APPEND| O_CREAT,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |S_IROTH | S_IWOTH );

		}
		else if(mode=='a'){
			mf->fd=open(file, O_WRONLY | O_APPEND | O_CREAT,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |S_IROTH | S_IWOTH);

		}


		else
			return NULL;


		if(mf->fd==-1){
			return NULL;}
		return mf;}
	return NULL;
}

int mini_fread(void* buffer,int size_element, int number_element, MYFILE* file){

	if(file!=NULL && buffer!=NULL && size_element >=0 && number_element >=0)
	{
		if(file->buffer_read==NULL){	
			file->buffer_read=mini_calloc(size_element,IOBUFFER_SIZE);
			file->ind_read=0;
			if(read(file->fd,file->buffer_read,IOBUFFER_SIZE)==-1){
				mini_perror("ERROR");
				_exit(1);

			}

		}

		int i;
		for( i=0;i<number_element &&((char*)file->buffer_read)[file->ind_read]!='\0';i++){
			if (file->ind_read==IOBUFFER_SIZE-1){

                                break;}

			((char*)buffer)[i]=((char*)file->buffer_read)[file->ind_read];
			file->ind_read++;
		}

		return i;
	}
	return -1;


}
int mini_fwrite(void* buffer,int size_element, int number_element, MYFILE* file){

	if(file!=NULL && buffer!=NULL && size_element >=0 && number_element >=0)
	{
		if(file->buffer_write==NULL){
			file->buffer_write=mini_calloc(size_element,IOBUFFER_SIZE);
			file->ind_write=0;
		}
		for(int i=0;i<number_element && ((char*)buffer)[i]!='\0';i++){
			if (file->ind_write==IOBUFFER_SIZE-1){

                                break;}

			((char *)file->buffer_write)[file->ind_write]=((char*)buffer)[i];
			file->ind_write++;
		}

		if(file->ind_write==IOBUFFER_SIZE-1){
		
			if(write(file->fd,file->buffer_write,IOBUFFER_SIZE)==-1){
				mini_perror("ERROR");
				_exit(1);

			}

		}
		temp=file;

		return file->ind_write;


	}
	return -1;


}


int mini_fflush(MYFILE* file){

	if(file!=NULL && file->buffer_write!=NULL){

		if(write(file->fd,file->buffer_write,file->ind_write)==-1){
			mini_perror("ERROR");
			_exit(1);

		}

		return file->ind_write;

	}
	return -1;
}

int mini_fclose(MYFILE* file){
	if(file!=NULL){
		if(file->buffer_read!=NULL){
			mini_free(file->buffer_read);


		}
		if(file->buffer_write!=NULL){
			if(file->ind_write!=IOBUFFER_SIZE){

				mini_fflush(file);
				mini_free(file->buffer_write);	

			}

		}	

		file->ind_write=-1;
		file->ind_read=-1;




		close(file->fd);
		mini_free(file);

		return 0;

	}
	return -1;


}
int mini_fgetc(MYFILE* file){

	if(file!=NULL)
	{
		if(file->buffer_read==NULL){
			file->buffer_read=mini_calloc(1,IOBUFFER_SIZE);
			file->ind_read=0;
			if(read(file->fd,file->buffer_read,IOBUFFER_SIZE)==-1){
				mini_perror("ERROR");
				_exit(1);

			}

		}



		if (file->ind_read!=IOBUFFER_SIZE-1){

			return ((char *)file->buffer_read)[file->ind_read++];
		}



	}
	return -1;


}




int mini_fputc(MYFILE* file, char c){

	if(file!=NULL)
	{  
                if(file->buffer_write==NULL){
			file->buffer_write=mini_calloc(1,IOBUFFER_SIZE);
			file->ind_write=0;
		}
		
		if(file->ind_write!=IOBUFFER_SIZE-1){
			((char*)file->buffer_write)[file->ind_write]=c;
			file->ind_write++;}
		if(file->ind_write==IOBUFFER_SIZE-1){
                        if(write(file->fd,file->buffer_write,file->ind_write)==-1){
                                mini_perror("ERROR");
                                _exit(1); 

                        }

                }

		return 0;}
			




	return -1;
}







void mini_exit_buffer_write(){

	if(temp!=NULL && temp->buffer_write!=NULL && temp->ind_write!=-1){
		mini_fflush(temp);
		mini_free(temp->buffer_write);
		mini_free(temp);

	}







}











