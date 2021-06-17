// bill dinner
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    int b,sum=0,avg;
    scanf("%d",&b);
    for (int i = 0; i < n; i++)
    {
        if (i==k)
        {
            continue;

        }
        else
        {
            sum+=a[i];
        }
        
    }
    avg=sum/2;
    if (avg==b)
    {
        printf("Correctly calculated\n");
    }
    else
    {
        printf("%d",b-avg);
        
    }
    
    return 0;
}
