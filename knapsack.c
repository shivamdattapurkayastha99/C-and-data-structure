#include<stdio.h>
#include<stdlib.h>
void sort(float *p,float *w,float *x,int n)
{
    int i,j;
    float temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(x[j]<x[j+1])
            {
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;

            }
        }
    }
}
void knapsack(float m,int n)
{
    int i,j;
    float tot=0.0;
    float *p=(float *)malloc(n*sizeof(float));
    float *w=(float *)malloc(n*sizeof(float));
    float *r=(float *)malloc(n*sizeof(float));
    float *x=(float *)malloc(n*sizeof(float));
    for(i=0;i<n;i++)
    {
        printf("Enter the price of the objects\n");
        scanf("%f",&p[i]);
        printf("Enter the weights of the objects\n");
        scanf("%f",&w[i]);
        r[i]=p[i]/w[i];
    
    }
    sort(p,w,r,n);
    for(i=0;i<n;i++)
    printf("\n%f    %f  %f",p[i],w[i],r[i]);
    for(i=0;i<n;i++)
    {
        x[i]=0.0;
    }
    float u=m;
    for(i=0;i<n;i++)
    {
        if(w[i]>u)
        break;
        else
        {
            x[i]=1.0;
            tot+=x[i]*p[i];
            u=u-w[i];

        }
    }
    if(i<n)
    {
        x[i]=u/w[i];
        tot+=x[i]*p[i];

    }
    for(i=0;i<n;i++)
    printf("\n%f",x[i]);
    printf("Total profit is\n%f",tot);

}
int main(int argc, char const *argv[])
{
   int n;
   float m;
   int i;
   printf("Enter the no of onjects\n");
   scanf("%d",&n);
   printf("Enter the max weight capacity\n");
   scanf("%f",&m);
   knapsack(m,n);
   

    return 0;
}
