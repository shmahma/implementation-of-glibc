
#include<unistd.h>
#include"mini_lib.h"
#include <sys/types.h>
struct malloc_element{

        void* point;
        int size_element;
        int number_element;
        int stat;
        struct malloc_element* my_malloc;

};



struct malloc_element* malloc_list=NULL;


//fonction

void* mini_calloc (int size_element, int number_element)
{

	struct malloc_element* temp=sbrk(sizeof(struct malloc_element));
	void* pt=NULL;
	if (size_element<0 || number_element<0)
	{
		mini_printf("taille ou nombre d element inferieur a 0");
		return NULL;

	}

	

	if(malloc_list==NULL)
	{
		
		temp->stat=1;
		temp->size_element=size_element;
		temp->number_element=number_element;
		temp->my_malloc=NULL;
		
		if((pt=sbrk(size_element*number_element))==(void*) (-1)  )
		{
			mini_printf("allocation non reussie");
			return NULL;
		}


		for(int i=0;i<number_element;i++)
		{
			*((char*)(pt+i))='\0';
		}
		temp->point=pt;
		malloc_list=temp;

	
	}


	else
	{
		struct malloc_element* temp2=malloc_list;

		while(temp2!=NULL)
		{
			if((temp2->size_element*temp2->number_element>=size_element*number_element) && temp2->stat==0){
				break;
			}
			temp2=temp2->my_malloc;
		}

		if(temp2!=NULL&&temp2->stat==0){
			pt=temp2->point;
			temp2->stat=1;
		}
		else{
			temp->my_malloc=malloc_list;
			temp->stat=1;
			temp->size_element=size_element;
			temp->number_element=number_element;
			
			if((pt=sbrk(size_element*number_element))==(void*) (-1)  )
			{
				mini_printf("allocation non reussie");
				return NULL;
			}


			for(int i=0;i<number_element;i++)
			{
				*((char*)(pt+i))='\0';
			}
			temp->point=pt;
			malloc_list=temp;
		}
	}


	return pt;
}



void mini_free(void* ptr){
	if (ptr!=NULL){
		struct malloc_element* temp=malloc_list;
		while(temp!=NULL)
		{
			if(temp->point==ptr){
				break;
			}
			temp=temp->my_malloc;
		}
		if(temp!=NULL){		
			temp->stat=0;
			for(int i=0;i<temp->number_element;i++)
			{
				*((char*)(temp->point+i))='\0';
			}
		}
	}}


void mini_exit()
{
	mini_exit_string();
	mini_exit_buffer_write();
	_exit(0);

}
