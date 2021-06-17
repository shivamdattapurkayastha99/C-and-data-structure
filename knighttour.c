// backtracking knight tour problem
#include<stdio.h>
#include<stdlib.h>
#define N 8

int solveKTUtil(int x,int y,int movei,int sol[N][N],int xMove[],int yMove[]);
int isSafe(int x,int y,int sol[N][N])
{
    return x>=0&&x<N&&y>=0&&y<N&&sol[x][y]==-1;

}
void printSolution(int sol[N][N])
{
    for(int x=0;x<N;x++)
    {
        for(int y=0;y<N;y++)
        {
            printf("%d ",sol[x][y]);
        }
        printf("\n");
    }
}
int solveKT()
{
    int sol[N][N],n;
    for(int x=0;x<N;x++)
    {
        for(int y=0;y<N;y++)
        {
            sol[x][y]=-1;
        }
    }
   printf("Enter the no of moves\n");
   scanf("%d",&n);
//    xMove[] and yMove[] define the x and y coordinates of the next move of Knight
int *xMove=(int *)malloc(n*sizeof(int));
int *yMove=(int *)malloc(n*sizeof(int));
printf("Enter the x-coordinates of the moves of the Knight\n");
for(int i=0;i<n;i++)
scanf("%d",&xMove[i]);
printf("Enter the y-coordinates of the moves of the Knight\n");
for(int i=0;i<n;i++)
scanf("%d",&yMove[i]);
sol[0][0]=0;
if(solveKTUtil(0,0,1,sol,xMove,yMove)==0)
{
    printf("Solution does not exist\n");
    return 0;
}
else
printSolution(sol);
return 1;
}
int solveKTUtil(int x,int y,int movei,int sol[N][N],int xMove[N],int yMove[N])
{
    int k,next_x,next_y;
    if(movei==N*N)
    return 1;
    for(k=0;k<8;k++)
    {
        next_x=x+xMove[k];
        next_y=y+yMove[k];
        if(isSafe(next_x,next_y,sol))
        {
            sol[next_x][next_y]=movei;
            if(solveKTUtil(next_x,next_y,movei+1,sol,xMove,yMove)==1)
            return 1;
            else
            sol[next_x][next_y]=-1;

        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    solveKT();
    
    return 0;
}
