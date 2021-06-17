// array deletion
#include<stdio.h>
#include<stdlib.h>
void display(int *a,int n)
{
    for(int i=0;i<n;i++)
    printf("%d\n",a[i]);
}
void deletion(int *a,int n,int index)
{
    for (int i = index; i <n-1; i--)
    {
        a[i] = a[i+1];
    }
   
}
int main(int argc, char const *argv[])
{
   int n;
   printf("Enter the no of elements\n");
   scanf("%d",&n);
   int *a=(int *)malloc(n*sizeof(int));
   printf("Enter the elements of the array\n");
   for(int i=0;i<n;i++)
   scanf("%d",&a[i]);
   int index;
   printf("Enter the index in which you want to delete the element\n");
   scanf("%d",&index);
   
   
    display(a,n);
    deletion(a,n,index);
    n--;
    display(a,n);
    
     return 0;
}


