#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void partition(int x[],int lb,int ub,int *pj)
{
    int temp,a,up,down;
    a=x[lb];
    up=ub;
    down=lb;
    while(down<up)
    {
        while(x[down]<=a)
        down++;
        while(x[up]>a)
        up--;
        if(down<up)
        {
            temp=x[up];
            x[up]=x[down];
            x[down]=temp;
        }
    }
    temp=x[lb];
    x[lb]=x[up];
    x[up]=temp;
    *pj=up;
}
void quicksort(int x[],int lb,int ub)
{
    int j;
    if(lb<ub)
    {
        partition(x,lb,ub,&j);
        quicksort(x,lb,j);
        quicksort(x,j+1,ub);

    }
}
int main(int argc, char const *argv[])
{
  int n,i;
  printf("Enter the number of elements in the array\n");
  scanf("%d",&n);
  int *x=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
  x[i]=rand()%10;
  quicksort(x,0,n-1);
  for(i=0;i<n;i++)
  printf("%d ",x[i]);
  
    return 0;
}
