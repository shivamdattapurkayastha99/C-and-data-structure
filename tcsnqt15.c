// leaders in an array
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);

    }
    for (int i = 0; i < n; i++)
    {
        int j;
        for ( j = i+1; j < n; j++)
        {
           if (a[j]>a[i])
           {
              break;
           }
           
           
        }
        if (j==n)
        {
            printf(" %d ",a[i]);

        }
       
    }
    
    return 0;
}
