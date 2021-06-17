#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define V 5
int minkey(int key[],bool mstset[])
{
    int min=INT_MAX,minindex;
    for(int v=0;v<V;v++)
    if(mstset[v]==false&&key[v]<min)
    min=key[v],minindex=v;
    return minindex;

}
int printmst(int parent[],int graph[V][V])
{
    printf("edge\tweight\n");
    for(int i=1;i<V;i++)
    printf("%d-%d\t%d\n",parent[i],i,graph[i][parent[i]]);

}
void primmst(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstset[V];
    for(int i=0;i<V;i++)
    key[i]=INT_MAX,mstset[i]=false;
    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<V-1;count++)
    {
        int u=minkey(key,mstset);
        mstset[u]=true;
        for(int v=0;v<V;v++)
        if(graph[u][v]&&mstset[v]==false&&graph[u][v]<key[v])
        parent[v]=u,key[v]=graph[u][v];

    }
    printmst(parent,graph);

}
int main(int argc, char const *argv[])
{
   int graph[V][V];
   printf("Enter the edge weights of the graph\n");
   for(int i=0;i<V;i++)
   {
       for(int j=0;j<V;j++)
       {
           scanf("%d",&graph[i][j]);

       }
   }
   primmst(graph);
    return 0;
}
