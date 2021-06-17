#include<stdio.h>
#include<stdlib.h>
void sort(int *a,int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
    for(int j=0;j<n-1-i;j++)
    {
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
    }
}
int linearsearch(int a[],int n,int x)
{
    int pos;
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        pos=i;
    }
    return pos;

}
int binarysearch(int a[],int n,int x)
{
    int pos,mid,lb=0,ub=n-1;
    

    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(a[mid]<x)
        lb=mid+1;
        if(a[mid]>x)
        ub=mid-1;
        if(a[mid]==x)
        return mid;
    }
    
    return -1;
    
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the no of elements in the array\n");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    int x;
    printf("Enter the element to be searched in the array\n");
    scanf("%d",&x);
    int linpos=linearsearch(a,n,x);
    printf("the element %d is found at %dth position by linear search\n",x,linpos+1);
    sort(a,n);
    int binpos=binarysearch(a,n,x);
    printf("the element %d is found at %dth position by binary search\n",x,binpos+1);
    return 0;
}
