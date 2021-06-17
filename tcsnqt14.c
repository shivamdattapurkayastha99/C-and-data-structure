// maths teacher problem
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int armstrong(int n)
{
    int count=0,d,sum=0,n1=n,n2=n;
    while (n1>0)
    {
       count++;
       n1/=10;

    }
    while (n2>0)
    {
       d=n2%10;
       sum+=pow(d,count);

       n2/=10;
       
    }
    if (sum==n)
    {
       return 1;
    }
    else
    {
        return 0;
    }
    
}
int main(int argc, char const *argv[])
{
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    if (n1<=0||n2<=0)
    {
        printf("Invalid Input\n");

    }
    else
    {
        for (int i = n1; i <=n2; i++)
        {
            if (armstrong(i))
            {
                printf("%d ",i);

            }
            
        }
        
    }
    
    return 0;
}
