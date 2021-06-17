#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int quadruplet(int a[],int n)
{
    if(n<4)
    return 0;
    else
    {
        int p,q,r,s,max=0;
        for (int p = 0; p < n-3; p++)
        {
            for (int q = p+1; q < n-2; q++)
            {
                for (int r = q+1; r < n-1; r++)
                {
                    for (int s = r+1; s < n; s++)
                    {
                        if((a[p]*a[q]*a[r]*a[s])>max)
                        max=a[p]*a[q]*a[r]*a[s];
                    }
                }
            }
        }
        return max;

    }
    
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
       scanf("%d",&a[i]);

    }
    int x=quadruplet(a,n);
    if(x==0)
    printf("Invalid input\n");
    else
    {
        printf("%d ",x);
    }
    
    
    return 0;
}
