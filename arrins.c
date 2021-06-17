#include<stdio.h>
#include<stdlib.h>
void display(int *a,int n)
{
    for(int i=0;i<n;i++)
   printf("%d\n",a[i]);
}
int insertion(int *a,int n,int element,int capacity,int index)
{
     if(n>=capacity){
        return -1;
    }
    for (int i = n-1; i >=index; i--)
    {
        a[i+1] = a[i];
    }
    a[index] = element;
    return 1; 
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the no of terms\n");
    scanf("%d",&n);

   int *a=(int *)malloc((n+2)*sizeof(int));
   printf("Enter the array\n");
   for(int i=0;i<n;i++)
   scanf("%d",&a[i]);
   display(a,n);
    int i;
    printf("Enter the position you want to insert an element\n");
    scanf("%d",&i);
    int element;
    printf("Enter the element you want to insert\n");
    scanf("%d",&element);
    insertion(a,n,element,n+2,i);
    n+=1;
    display(a,n);
    return 0;
}
