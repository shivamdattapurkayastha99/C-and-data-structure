// mcoloring or graph coloring problem
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define V 4
void printSolution(int color[]);
bool isSafe(int v,int graph[V][V],int color[],int c)
{
    for(int i=0;i<V;i++)
    if(graph[v][i]&&c==color[i])//edge between vertex v and i if adjacent colors are same return false
    return false;
    return true;

}
bool graphcoloring(int graph[V][V],int m,int color[],int v)
{
    if(v==V)
    return true;
    for(int c=1;c<=m;c++)
    {
        if(isSafe(v,graph,color,c))
        {
            color[v]=c;
            if(graphcoloring(graph,m,color,v+1)==true)
            return true;
            color[v]=0;
        }
    }
    return false;

}
bool checking(int graph[V][V],int m)
{
    int color[V];
    for(int i=0;i<V;i++)
    color[i]=0;
    if(graphcoloring(graph,m,color,0)==false)
    {
        printf("Solution doesnot exist\n");
        return false;
    }
    printSolution(color);
    return true;
}
void printSolution(int color[])
{
    printf("These are the assigned colors\n");
    for(int i=0;i<V;i++)
    printf("%d",color[i]);
    printf("\n");

}
int main(int argc, char const *argv[])
{
    int graph[V][V];
    printf("Enter the adjacency matrix of the graph\n");
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
        scanf("%d",&graph[i][j]);
        }
    }
    int m;
    printf("Enter the atmost no of colors with which graph can be colored\n");
    scanf("%d",&m);
    checking(graph,m);
    return 0;
}
