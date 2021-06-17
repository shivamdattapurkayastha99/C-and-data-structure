// divide and conquer approach for max and min 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void maxmin(int *a,int i,int j,int *max,int *min)
{
    int mid;
    int max1;
    int min1;
    if(i==j)
    *max=*min=a[i];
    else if(i==(j-1))
    {
        if(a[i]>a[j])
        {
            *max=a[i];
            *min=a[j];

        }
        else
        {
            *max=a[j];
            *min=a[i];
        }
    }
    else
    {
        mid=(i+j)/2;
        maxmin(a,i,mid,max,min);
        maxmin(a,mid+1,j,&max1,&min1);
        if(max1>*max)
        *max=max1;
        if(min1<*min)
        *min=min1;


    }
}
int main(int argc, char const *argv[])
{
  int n,i;
  clock_t start,end;
  double etime;
  start=clock();
  end=clock();
  etime=(double)(end-start)/CLOCKS_PER_SEC;

  printf("Enter the no of elements\n");
  scanf("%d",&n);
  int *a=(int *)malloc(n*sizeof(int));
  printf("Enter the elements in the array\n");
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
  int max=a[0];
  int min=a[0];
  maxmin(a,0,n-1,&max,&min);
  printf("max is %d",max);
  printf("min is %d",min);
  printf("the execution time is %f",etime);



    return 0;
}
