/*
 * main.c
 *
 * Programmierung 2 - Projekt 3 (PageRank)
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <stdbool.h>

#include "utils.h"

#include "graph.h"



 int n=0 , m = -1, p =10 , r=-1;
 
 int *Arr;
void multiplyMatrices(double*  firstMatrix, double* secondMatrix, double* mult, int rowFirst, int columnFirst, int rowSecond, int columnSecond)
{
int i, j, k;

//malen zwei array
for(i = 0; i < rowFirst; ++i){
for(j = 0; j < columnSecond; ++j)
{
*(mult+i*rowFirst +j)= 0;
}
}

// erste matrix mit zweite  
for(i = 0; i < rowFirst; ++i)
{
for(j = 0; j < columnSecond; ++j)
{
for(k=0; k<columnFirst; ++k)
{
*(mult+i*rowFirst +j)+= *(firstMatrix + i*rowFirst + k )*(*( secondMatrix + k*columnFirst +j));
}
}
}
}
int maxout(){
    int sum =0;
   // int countInmax =0;
    int resl=0;
     for (int i = 0; i <  n; i++){
         sum =0;
      for (int j = 0; j < n; j++){
          
     sum += *(Arr +i*n +j);
     if (sum > resl){
    resl=sum;
         
     }
  
   }
          }
          
return resl;
  }
  int maxIn(){
      int sum =0;
   // int countInmax =0;
    int resl=0;
     for (int j = 0; j <  n; j++){
         sum =0;
      for (int i = 0; i < n; i++){
          
     sum += *(Arr +i*n +j);
     if (sum > resl){
    resl=sum;
         
     }
  
   }
          }
return resl;
      
  }
  int minIn(){
      if (n==0){
          return 0;
      }
      int sum =0;
   // int countInmax =0;
    int resl=-1;
     for (int j = 0; j <  n; j++){
         sum =0;
      for (int i = 0; i < n; i++){
          
     sum += *(Arr +i*n +j);
     if( resl== -1){
         resl= sum;
     }else
     if (sum < resl){
    resl=sum;
         
     }
  
   }
          }
return resl;
  
  }
  int minout(){
      if(n==0){
return 0;
      }
      int sum =0;
   // int countInmax =0;
    int resl=-1;
     for (int i = 0; i <  n; i++){
         sum =0;
      for (int j = 0; j < n; j++){
          
     sum += *(Arr +i*n +j);
     if( resl== -1){
         resl= sum;
     }else
     if (sum < resl){
    resl=sum;
         
     }
  
   }
          }
return resl;
  
  }
 int num_of_outed(int x ){
    int sum = 0;
    for(int i=0; i<n;i++){
        sum+= *(Arr + x*n +i);
        
    }
    return sum;
}
bool has_outE(int x ){
    int sum = 0;
    for(int i=0; i<n;i++){
        sum+= *(Arr + x*n +i);
        
    }
    if(sum == 0){
        return 0;
        
    }
    return 1;
}

int has_Ed(int s , int d ){
    int sum = *(Arr +s*n +d);
    
    return sum;
}

void markov(){
    
 double P= p/100.0;
 double *M = (double*)malloc(n*n *(sizeof(double)));
  for (int i = 0; i <  n; i++){
      for (int j = 0; j < n; j++){
          if(has_outE(i)){
              *(M + i*n +j)= (P/n )+((1-P)*(has_Ed(i ,j )))/num_of_outed(i);
              
          }else{
              *(M + i*n +j)= 1.0/n;
          }
}

 }

 double *V = (double*)malloc(n *(sizeof(double)));
 for(int i =0; i< n; i++){
     *(V+ i) =1.0/n;
     
     
 }
  double *res = (double*)malloc(n *(sizeof(double)));
  
 for(int i = 0; i<m; i++){
 multiplyMatrices( V , M, res, 1, n , n, n); 
 for(int i =0; i< n; i++){
    *( V + i)=res[i];
 }
 }
 
 for(int i =0; i< n; i++){
     printf("%s\t\t %.10f\n",search_by_id(i), V[i]);
     
 }
 free(V);
free(M);
free (res);
}

void stat(char *ss ){
    int countEd = 0;
 for (int i = 0; i <  n; i++){
      for (int j = 0; j < n; j++){
          if (*(Arr +i*n+j)== 1){
              countEd++;
          }
      }
 }
 
 printf("%s:\n",ss);
 printf("- num nodes: %d\n",n); 
  printf("- num edges: %d\n",countEd);
printf("- indegree: %d-%d\n",minIn(), maxIn());  
 //printf("the indegreemin is: %d\n", maxIn());
  printf("- outdegree: %d-%d\n", minout(),maxout());
   //printf("the indegreemin is: %d\n", minout());
  free(Arr);  
}
void rang(){
int *frq= (int*)malloc(n *(sizeof(int)));
for(int i=0; i<n; i++){
    *(frq +i)=0;    
}

int position = randu(n);
frq[position]++;
int nextp;
//printf("we are going to : %s\n",search_by_id(position));
for(int i=0; i<r-1; i++){
    
 do{
     //nextp=rund
     nextp =randu(n);
    // printf("has edge say: %d\n",has_Ed(position, nextp));
 }while(has_Ed(position , nextp)==0);
 //printf("we are going to : %s\n",search_by_id(nextp));
 frq[nextp]++;
 position = nextp;
}

for(int i =0; i< n; i++){
     printf("%s\t\t %.10f\n",search_by_id(i), (double)frq[i]/r);
     
 }
 free(frq);
}


int main(int argc, char *const *argv) {
  // initialize the random number generator
 // rand_init();
int   s=-1, h;
int option;
  //printf("You gave %d command line arguments%c\n",
      //argc-1, argc==1 ? '.' : ':');
  /*for (unsigned i = 1; i < argc; ++i)
    printf("  - %s\n", argv[i]);*/
  //exit(0);
  
 // printf("hir\n");
while((option = getopt(argc, argv , "m:r:p:hs"))!= -1){
    
    switch(option){
         case'h':
          printf("Folgende Parmeter sind erlaubr:\n\ -m N :Berechnung der Markow-Kette\n\
          -p N :Berechnung des PageRank\n\
          -r N : Berechnung eine Simulation des Zufallssurfer\n\
          Hierbei müssen -m, -r , -p gegeben sein!\n");
          exit(0);
            break;
        case'm':
          
          m= atoi(argv[optind -1]);
            break;
             case'p':
          p = atoi(argv[optind -1]);
            break;
             case'r':
          r = atoi(argv[optind -1]);
            break;
          case's':
          s=1;
        break;
    }
}
//char *file_name = argv[optind];
  FILE* f;
  //printf("hi\n");

    f = fopen(argv[optind], "r");
    if (f== NULL)
    return EXIT_FAILURE;
    //char Bez[256];
   char fs[256];
   char ss[256];
   char es[256];
   char file_name[256];
   
   
   fscanf(f,"%s %s %s\n",fs,ss,es);
   for(int i=0; i<256; i++){
       file_name[i]= ss[i];
    
   }

 
while(fscanf(f,"%s %s %[^;]%*c\n",fs,ss,es)!=-1){
    if (fs[0] =='}'){
        break;
    }
    if (search_In_G(fs) == -1){
        n++;
        create_Graph(fs);
        
    }
    if (search_In_G(es) == -1){
        n ++;
        create_Graph(es);
        
    }
    //printf("%s %s %s\n",fs,ss,es);
   // printf("%d\n", (fs[0]-'A'));
    
    
}
 Arr = (int*)malloc(n*n *(sizeof(int)));

 //printf("the total:%d\n",n);
   
//   printf("the char is:%c\n", (list+1)->next->value);
 
    fclose(f);

    f = fopen(argv[optind], "r");
    if (f== NULL)
    return EXIT_FAILURE;
   fscanf(f,"%s %s %s\n",fs,ss,es);
   for(int i=0; i<256; i++){
       file_name[i]= ss[i];
       
    
   }


   for(int i=0; i< n;i++){
       for(int j=0 ; j< n; j++){
           *(Arr +i*n+j)= 0;
           
       }
   }
   
while(fscanf(f,"%s %s %[^;]%*c\n",fs,ss,es)!=-1){
    if (fs[0] =='}'){
        break;
    }
    //zeile
  int s =  search_In_G(fs) ;
  //spaltels
   int d=  search_In_G(es);
   // printf("%s %s %s\n",fs,ss,es);
    
    *(Arr +s*n+d)=1;
    
   // printf("%d\n", (fs[0]-'A'));
    
    
}
/*
 for (int i = 0; i <  n; i++){
      for (int j = 0; j < n; j++){
         printf("%d ", *(Arr + i*n + j));
    
}
printf("\n");

 }*/
 //zahl der kanten
 
 
 if(m != -1){
     markov();
 }
 
 if (s == 1){
     stat(file_name);
}
if (r!= -1){
    rang();
}


//printf("%d\n", randu(n));

}




