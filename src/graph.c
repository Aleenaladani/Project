

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "graph.h"



struct Graph* topGraph = NULL;
struct Graph* create_Graph (char* name){
struct Graph* elm = (struct Graph*)malloc(sizeof(struct Graph));

strcpy(elm->name ,name);
elm->next= NULL;
 struct Graph *Trans= topGraph;
 if (topGraph == NULL){
     elm->id = 0;
      Trans = elm;
     topGraph = elm;
     return elm;
 }else{
     int i = 1;
 while(Trans-> next != NULL){
     
     Trans = Trans->next;
     i++;
     //last elemt
      }
       elm->id = i;
       Trans-> next = elm;
       Trans=elm;
 }
 
return elm;

}
/*struct Word* insert_end(char* name)
{
        struct  Word *temp,*ptr;
        int id = 0;
        temp=(struct Word  *)malloc(sizeof(struct Word ));
        if(temp==NULL)
        {
                printf("nOut of Memory Space:n");
                return NULL;
        }
        strcpy(temp->name , name);
        temp->next =NULL;
        temp->id = id;
        if(topWord ==NULL)
        {
                topWord=temp;
        }
        else
        {
                ptr=topWord;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                        id++;
                }
                temp->id = id+1;
                ptr->next =temp;
                return temp;
        }
}*/
int   search_In_G (char* name){
    int i=-1;
    struct Graph *Trans= topGraph;
    if(Trans == NULL){
        return i;
    }
   
while(Trans != NULL){
     if(strcmp(Trans->name ,name )== 0){
        return Trans->id;
    }
     
     Trans = Trans->next;
     i++;
     //last elemt
      }
      return -1;
}
char* search_by_id(int id){
    char *name;
     
    struct Graph *Trans= topGraph;
    if(Trans == NULL){
        return NULL;
    }
   
while(Trans != NULL){
     if(id == Trans->id){
        return Trans->name;
    }
     
     Trans = Trans->next;
     //last elemt
      }
      return NULL;
}



/*struct Elment* add_list(char* name ,  struct Elment* Top, int k)
{
    printf("hey\n");
    printf("the address is:%d\n",Top);
        struct  Elment *temp,*ptr;
        //
        temp=(struct Elment*)malloc(sizeof( temp));
        if(temp==NULL)
        {
                printf("nOut of Memory Space:n");
                return NULL;
        }
        strcpy(temp->name , name);
        temp->next =NULL;
        temp->k = k;
        if(Top ==NULL)
        {
printf("add is empty\n");

                Top=temp;
        }
        else
        {
             printf("else\n");
                ptr=Top;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                        
                }
                temp->k = k;
                ptr->next =temp;
                return temp;
        }
}*/


