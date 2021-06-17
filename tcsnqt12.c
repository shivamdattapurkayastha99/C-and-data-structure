// mountain array
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
    if (n<3)
    {
        printf("False\n");

    }
    else
    {
        int j=0;
        while (j-1<n&&a[j]<a[j-1])
        {
            j++;
        }
        if (j==0||j==n-1)
        {
            printf("False\n");
        }
        else
        {
            while (j+1<n&&a[j]>a[j+1])
            {
                j++;

            }
            if (j==n-1)
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");

            }
            
        }
        
    }
    
    return 0;
}
