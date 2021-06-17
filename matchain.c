#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int matrixchain(int p[],int n)
{
    int i,j,k,l,q;
    int s[n][n];
    int m[n][n];
    for(i=1;i<=n;i++)
    m[i][i]=0;
    for(l=2;l<=n;l++)
    {
        for(i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    return m[1][n];

}
void paren(int i,int j,int n,int *bracket,char name)
{
    if(i==j)
    {
        printf("%c",name++);
        return;
    }
    printf("(");
    paren(i,*((bracket+i*n)+j),n,bracket,name);
    paren(*((bracket+i*n)+j)+1,j,n,bracket,name);
}
int main()
{
    int n,i;
    char name='A';
    printf("Enter the no of matrices\n");
    scanf("%d",&n);
    int bracket[n][n];
    int *p=(int *)malloc((n+1)*sizeof(int));
    printf("Enter the order of the matrices\n");
    for(int i=0;i<=n;i++)
    scanf("%d",&p[i]);
    int x=matrixchain(p,n);
    printf("The number of multiplications is %d\n",x);
    printf("parenthesis are\n");
    paren(1,n-1,n,(int *)bracket,name);
    return 0;
}