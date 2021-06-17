#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define n 8
void printSolution(int board[n][n])
{
    int i,j;
    static int k=1;
    printf("%d.\n",k++);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}
bool isSafe(int board[n][n],int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    if(board[row][i])
    return false;
    for(i=row,j=col;i>=0&&j>=0;i--,j--)
    if(board[i][j])
    return false;
    for(i=row,j=col;j>=0&&i<n;j--,i++)
    if(board[i][j])
    return false;
return true;
}
bool solve(int board[n][n],int col)
{
    if(col==n)
    {
        printSolution(board);
        return true;
    }
    bool res=false;
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,i,col))
        {
            board[i][col]=1;
            res=solve(board,col+1)||res;
            board[i][col]=0;

        }
    }
    return res;
}
void checking()
{
    int board[n][n]={0};
    if(solve(board,0)==false)
    {
        printf("Solution doesnot exist\n");
        return;
    }
    return;
}
int main(int argc, char const *argv[])
{
    checking();
    return 0;
}
