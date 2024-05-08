#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdbool.h>


typedef struct Elment{
    char name[257];
    int k;
    int in;
    int out;
    struct Elment *next;
}Elment_t;

 /*typedef struct First{
    struct Elment *ptr;
    struct First *next;
    int id;
}First_t;*/

typedef struct Graph{
    char name[256];
    int id;
    struct Graph *next;
}Graph_t;


//creat elemnt
struct Graph* create_Graph (char* name);
//struct Word* insert_end(char* name);
int  search_In_G (char* name);
//struct Elment* add_list (char* name, struct Elment* top, int k);
//void multiplyMatrices(double*  firstMatrix, double* secondMatrix, double* mult, int rowFirst, int columnFirst, int rowSecond, int columnSecond);
//int num_of_outed(int x );
//bool has_outE(int x );
//int has_Ed(int s , int d );
char* search_by_id(int id);

#endif
