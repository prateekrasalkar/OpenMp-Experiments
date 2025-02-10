#include<stdio.h>
#include<omp.h>
int main(){
int a=1,b=0,c=0;
int i=0,n=0;
printf ("Enter n for fibonisis series ");
scanf("%d",&n);
int arr[n];
double start=omp_get_wtime();
#pragma omp parallel for 
for(i=0;i<n;i++)
{

 
  c=a+b;
  arr[i]=c;
  a=b;
  b=c;
  
}
double end =omp_get_wtime();
printf("\n Time=%f\n",end-start);
for(i=0;i<n;i++){
printf(" %d",arr[i]);
}
return 0;


}
