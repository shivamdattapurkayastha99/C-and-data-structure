// greedy algorithm activity selection problem
#include<stdio.h>
#include<stdlib.h>
void sort(int *s,int *f,int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(f[j]>f[j+1])
            {
             temp=f[j];
             f[j]=f[j+1];
             f[j+1]=temp;
             temp=s[j];
             s[j]=s[j+1];
             s[j+1]=temp;

            }
        }
    }
}
void printmaxActivities(int s[],int f[],int n)
{
    sort(s,f,n);
    int i,j;
    printf("Following activities sre selected\n");
    i=0;
    printf("%d",i);
    
    for(j=1;j<n;j++)
    {
        if(s[j]>=f[i])
        {
            printf("%d",j);
            i=j;

        }
    }

}
int main()
{
    int n;
    printf("Enter the number of tasks\n");
    scanf("%d",&n);
    int *s=(int *)malloc(n*sizeof(int));
    int *f=(int *)malloc(n*sizeof(int));
    printf("Enter the starting times of the tasks\n");
    for(int i=0;i<n;i++)
    scanf("%d",&s[i]);
    printf("Enter the ending times of the tasks\n");
    for(int i=0;i<n;i++)
    scanf("%d",&f[i]);
    printmaxActivities(s,f,n);

}