#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main(int argc, char const *argv[])
{
    float ne,ni,ce=12,ci=18,cost=0,temp;
    scanf("%d %d",&ni,&ne);
    if (ni<0||ne<0)
    {
       printf("Invalid Input\n");
    }
    else if (ni==0&&ne==0)
    {
        printf("Total estimated cost is 0.0");
    }
    else
    {
        for (int i = 0; i < ni; i++)
        {
            scanf("%f",&temp);
            cost+=ci*temp;
        }
        for (int j = 0; j < ne; j++)
        {
            scanf("%f",&temp);
            cost+=ce*temp;
        }
        printf("Total estimated cost is %0.1f",cost);
    }
    
    return 0;
}
