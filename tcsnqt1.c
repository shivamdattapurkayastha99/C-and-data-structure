// max distance marathon runner
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char const *argv[])
{
    char str[10];
    double a[50];
    int index=0;
    while (1)
    {
        printf("Enter the distances covered\n");
        gets(str);
       if(strcmp(str,"q")==0)
       break;
       else
       a[index++]=atof(str);

    }
    for (int i = 0; i < index-1; i++)
    {
        for (int j = 0; j < index-1-i; j++)
        {
           if(a[j]<a[j+1])
           {
               float temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
           }
        }
        
    }
    int count=0,flag=1;
    for (int i = 0; i < index; i++)
    {
       if(a[i]<0.0||a[i]>42.195)
       {
           printf("Invalid input\n");
           return 0;
       }
    }

    for (int i = 0; i < index; i++)
    {
       if(a[i]==42.195)
       {
           continue;
       }
       else
       {
           if(count<3)
           {
               printf("%f ",a[i]);
               count++;
               flag=0;

           }
       }
       
    }
    if(flag==1)
    printf("Invalid Input\n");
    return 0;
}
