#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int n=10,k=5;
    int n1;
    printf("Enter the no of candies to be sold\n");
    scanf("%d",&n1);
    if (n1>=1&&n1<=5)
    {
       printf("No of candies sold is %d\n",n1);
       printf("No of candies left is %d\n",n-n1);
    }
    else
    {
        printf("Invalid Input\n");
        printf("No of candies left is %d\n",n);
        
    }
    
    
    return 0;
}