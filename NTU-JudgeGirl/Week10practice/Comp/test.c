#include<stdio.h>      
#include<stdlib.h>      
int hh[900001]={0};      
int h(int);      
int g(int);      
int f(int);      
main()      
{         
 int n,k,a,b;      
 hh[1]=-1;hh[2]=2;      
 for(a=3,b=0;a<=90000;a++,b++)      
  {      
  hh[a]=2+hh[a-1]-hh[a-2];      
  }      
    while(scanf("%d",&n)==1)      
    {       
      printf("%d\n",f(n));      
           
    }      
  return 0;      
}      
int f(int x)      
{   if(x>h(x))       
       return f(x-1)-h(x);      
    else if(x<h(x))       
       return f(g(x))-g(x);      
    else                  
       return 1;      
}   
int h(int y)      
{         
 if(y<2)               
    return (-1);      
 else                  
    return hh[y];      
}      
int g(int z)      
{         
 if(z<=2) return z*z-1;      
 else return 2;      
}

