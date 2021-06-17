#include<stdio.h>
#include<stdlib.h>
int jobs(int start[],int end[],int n,int machine[])
{
 int i,j,t;
 for(i=0;i<n-1;i++)
 {
     for(j=0;j<n-1-i;j++)
     {
         if(end[j]<end[j+1])
         {
             t=end[j];
             end[j]=end[j+1];
             end[j+1]=t;

             t=start[j];
             start[j]=start[j+1];
             start[j+1]=t;

         }
     }
 }
 int count=0,flag;
 for(i=0;i<n-1;i++)
 {
     if(i==0)
     {
         machine[i]=end[0];
         count++;

     }
     if(start[i+1]<end[i])
     {
         flag=0;
         for(j=0;j<count;j++)
         {
             if(machine[j]<=start[i+1])
             {
                 machine[j]=end[i+1];
                 flag=1;
                 break;
             }
         }
         if(flag==0)
         {
             count++;
             machine[count-1]=end[i+1];

         }
     }
     else
     {
         for(j=0;j<count;j++)
         {
             if(machine[j]<start[i+1])
             {
                 machine[j]=end[i+1];
                 flag=1;
                 break;
             }
         }
     }
 }
 return count;
}
int main(int argc, char const *argv[])
{
  int start[]={0,3,4,9,7,1,6};
  int end[]={2,7,7,11,10,5,8};
  int machine[10];
  int count=jobs(start,end,7,machine);
  printf("The number of machines is %d",count);
    return 0;
}
