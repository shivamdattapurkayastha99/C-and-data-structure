// monkey banana,peanut
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int n,k,j,m,p;
    scanf("%d%d%d%d%d",&n,&k,&j,&m,&p);
    int ans=0;
    if (n<0||k<0||m<0||j<0||p<0)
    {
        printf("Invalid Input");
        return 0;
    }
    ans+=(m/k);
    ans+=(p/j);
    printf("No of monkeys left on the tree is %d",n-ans);
    
    return 0;
}
