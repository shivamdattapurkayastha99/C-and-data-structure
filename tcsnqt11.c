#include<stdio.h>
#include<stdlib.h>
int fib(int n)
{
    if (n==1)
    {
        return 0;
    }
    if (n==2)
    {
        return 1;
    }
    else
    {
        return fib(n-1)+fib(n-2);

    }
    
    
}
int main(int argc, char const *argv[])
{
    int n,ce=0,co=0;
    printf("Enter no of terms\n");
    scanf("%d",&n);
    for (int i = 1; i <=n; i++)
    {
        printf("%d ",fib(i));
        if (fib(i)%2==0)
        {
            ce++;
        }
        else
        {
            co++;
        }
        

    }
    printf("\n%d",ce);
    printf("\n%d",co);
    
    return 0;
}