// bat in a maze using backtracking
#include<stdio.h>
#include<stdlib.h>
#define N 4
int solveMazeUtil(int maze[N][N],int x,int y,int sol[N][N]);
void printSolution(int sol[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ",sol[i][j]);

        }
        printf("\n");

    }
}
int issafe(int maze[N][N],int x,int y)
{
    if(x>=0&&x<N&&y>=0&&y<N&&maze[x][y]==1)
    return 1;
    return 0;
}
int solvemaze(int maze[N][N])
{
    int sol[N][N]={{0}};
    if(solveMazeUtil(maze,0,0,sol)==0)
    {
        printf("Solution does not exist\n");
        return 0;
    }
    printSolution(sol);
    return 1;
}
int solveMazeUtil(int maze[N][N],int x,int y,int sol[N][N])
{
    if(x==N-1&&y==N-1&&maze[x][y]==1)
    {
        sol[x][y]=1;
        return 1;
    }
    if(issafe(maze,x,y))
    {
        sol[x][y]=1;
        if(solveMazeUtil(maze,x+1,y,sol)==1)
        return 1;
        if(solveMazeUtil(maze,x,y+1,sol)==1)
        return 1;
        sol[x][y]=0;


        return 0;
    }
    return 0;

}
int main(int argc, char const *argv[])
{
   int maze[N][N]={{1,0,0,0},
                  {1,1,0,1},
                  {0,1,0,0},
                  {1,1,1,1},};
    solvemaze(maze);
    return 0;
}
