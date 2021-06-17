// MPCS test question
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char const *argv[])
{
    int i,x,T1=0,T2=0,T3=0,count=1;
    double a1,a2,a3;
    while (count<=9)
    {
       printf("Enter the oxygen value\n");
       scanf("%d",&x);
       if (x>=1&&x<=100)
       {
           if (count%3==1)
           {
              T1=T1+x;
           }
           else if(count%3==2)
           {
               T2=T2+x;

           }
           else if(count%3==0)
           {
               T3=T3+x;
           }
           count++;
           
       }
       else
       {
           printf("INVALID INPUT\n");
           count++;
           return 0;
       }
       
       
    }
    a1=ceil(T1/3);
    a2=ceil(T2/3);
    a3=ceil(T3/3);
    if (a1<=70&&a2<=70&&a3<=70)
    {
      printf("All are unfit\n");
      return 0;
    }
    if(a1>=a2&&a1>=a3)
    printf("Trainee Number:1\n");
    if (a2>=a1&&a2>=a3)
    {
        printf("Trainee Number:2\n");
    }
    if (a3>=a1&&a3>=a2)
    {
        printf("Trainee Number:3\n");
    }
    
     return 0;
}
