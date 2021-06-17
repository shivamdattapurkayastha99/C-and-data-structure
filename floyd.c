#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define V 4
void printSolution(int dist[][V])
{
    int i,j;
    printf("the following matrix shows shortest distance between every pair of vertices\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            if(dist[i][j]==999)
            printf("INF ");
            else
            printf("%d ",dist[i][j]);

        }
        printf("\n");
    }
}
void floyd(int graph[][V])
{
    int dist[V][V],i,j,k;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            dist[i][j]=graph[i][j];
        }
    }
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            for(k=0;k<V;k++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    printSolution(dist);

}
int main(int argc, char const *argv[])
{
   int n,i,j;
   int graph[V][V];
//    printf("Enter the no of vertices\n");
//    scanf("%d",&n);
   printf("Enter the cost matrix\n");
   for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    floyd(graph);

    return 0;
}
