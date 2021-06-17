// fibonacci series
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int num,sum=0,odd=0,even=0,i;
    scanf("%d",&num);
    if (num>5&&num<=20)
    {
        int num1=1;
        int num2=1;
        for (int i = 1; i <=num; i++)
        {
            printf(" %d ",num1);
            if (num1%2==0)
            {
                even++;
            }
            else
            {
                odd++;
            }
            sum=num1+num2;
            num1=num2;
            num2=sum;

        }
        
    }
    else
    {
        printf("Invalid Input\n");
        return 0;
    }
    
   printf("\n%d %d ",even,odd);
}
