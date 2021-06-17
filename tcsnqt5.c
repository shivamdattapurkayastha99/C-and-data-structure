// Washing Machine
// 1 to 2000->25min 
// 2001 to 4000 35min 
// 4001 to 7000 45min 
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int weight;
    printf("Enter the weight\n");
    scanf("%d",&weight);
    if (weight==0)
    {
        printf("Time estimated is 0 minutes\n");

    }
    else if(weight>7000)
    printf("OVERLOADED\n");
    else if(weight>=1&&weight<=2000)
    printf("Time estimated is 25 minutes\n");
    else if(weight>=2001&&weight<=4000)
    printf("Time estimated is 35 minutes\n");
    else if(weight>=4001&&weight<=7000)
    printf("Time estimated is 45 minutes\n");
    else if(weight<0)
    {
        printf("Invalid Input\n");
    }
    
    return 0;
}
