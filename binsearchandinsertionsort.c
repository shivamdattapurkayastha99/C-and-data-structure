// performing insertion sort and then binary search
#include<stdio.h>
#include<stdlib.h>
void insertionsort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        j=i;
        while(j>0 && a[j]<a[j-1])
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            j--;
        }
    }
}
int binsearch(int a[],int l,int r,int x)
{
    if(r>=l)
    {
        int mid=l+(r-1)/2;
        if(a[mid]==x)
        return mid;
        if(a[mid]>x)
        return binsearch(a,l,mid-1,x);
        if(a[mid]<x)
        return binsearch(a,mid+1,r,x);

    }
    return -1;
}
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    printf("%d",a[i]);

}
int main(int argc, char const *argv[])
{
  int n,key;
  printf("Enter the size of the array\n");
  scanf("%d",&n);
  int a[n];
  int l=0,r=n-1;
  printf("Enter the array\n");
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
  insertionsort(a,n);
  display(a,n);
  printf("Enter the key\n");
  scanf("%d",&key);
  int x=binsearch(a,l,r,key);
  if(x>=0)
  {
      printf("Element %d is found at %d th position\n",key,x+1);
  }
  else
  printf("Not found\n");
    return 0;
}
