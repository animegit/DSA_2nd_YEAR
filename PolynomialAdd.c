#include<stdio.h>
typedef struct{
    int expon;
    int coeff;
}polynomial;

polynomial p[100]; //Array of structure polynomial.
int avail=0;
 
 void attach(int c,int e){
     p[avail].coeff=c;  
     // Attaches both cofficient and exponents and assign in array.
     p[avail++].expon=e;
 }
 void add(int sa,int ea,int sb,int eb,int *sd,int *ed){
     while(sa<=ea&&sb<=eb){
         if(p[sa].expon==p[sb].expon){
             if(p[sa].coeff+p[sb].coeff){
                 attach(p[sa].coeff+p[sb].coeff,p[sa].expon);
                
             }
              sa++;
            sb++;
         }
         else if(p[sa].expon<p[sb].expon){
             attach(p[sa].coeff,p[sa].expon);
             sa++;
         }
         else{
             attach(p[sb].coeff,p[sb].expon);
             sb++;
         }
     }
     for(int i=sa;i<=ea;i++){
         attach(p[i].coeff,p[i].expon); //remaining elements
     }
     for(int i=sb;i<=eb;i++){
         attach(p[i].coeff,p[i].expon);
     }
     
     *ed=avail-1;
 }
 
 void main(){
     int a,b;
     printf("Enter the number of elements in polynomial A");
     scanf("%d",&a);
     printf("Enter the number of elements in polynomial B");
     scanf("%d",&b);
     printf("Enter the polynomial A:-\n");
     for(int i=0;i<a;i++){
         int c,e;
         printf("Cofficient:-\n");
         scanf("%d",&c);
         printf("Exponent:-\n");
         scanf("%d",&e);
         attach(c,e);
         
     }
     printf("Enter the polynomial B:-\n");
     for(int i=0;i<b;i++){
         int c,e;
         printf("Cofficient:-\n");
         scanf("%d",&c);
         printf("Exponent:-\n");
         scanf("%d",&e);
         attach(c,e);
     }
    
     int sd,ed;
      add(0,a-1,a,a+b-1,&sd,&ed);
     printf("Added Polynomial is:-\n");
       for(int i=a+b;i<=ed-1;i++){
    printf(" %d x^%d +",p[i].coeff,p[i].expon);
  }
  printf(" %d x^%d ",p[ed].coeff,p[ed].expon);
     
     
 }
