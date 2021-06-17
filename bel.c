#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
// structure for edge containing src,dest and weight of an edge
struct edge{   
    int src;
    int dest;
    int weight;
};
// structure for graph containing no of vertices,no of edges and the edge pointer
struct graph
{
    int V,E;
    struct edge *e;

    
};
// function to create the graph
// g->e is the edge pointer 
struct graph *creategraph(int V,int E)
{
    struct graph *g=(struct graph *)malloc(sizeof(struct graph));
    g->V=V;
    g->E=E;
    g->e=(struct edge*)malloc(E*sizeof(struct edge));
    return g;

}
// function to print the shortest distances between the source and the different vertices
void printarr(int dist[],int n)
{
    printf("vertex distance from source\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\n",i,dist[i]);
    }
}
// belmanford algo implemented
void belmanford(struct graph *g,int src)
{
    int V=g->V;
    int E=g->E;
    int dist[V];
    // initializing distance of source to source=0 and source to other vertices as infinity
    for (int i = 0; i < V; i++)
    dist[i]=INT_MAX;
    dist[src]=0;
    for (int i = 1; i <= V-1; i++)
    {
        for(int j=0;j<E;j++)
        {
            int u=g->e[j].src;
            int v=g->e[j].dest;
            int weight=g->e[j].weight;
            if(dist[u]!=INT_MAX&&dist[u]+weight<dist[v])
            dist[v]=dist[u]+weight;

        }

    }
    for (int i = 0; i <E; i++)
    {
        int u=g->e[i].src;
        int v=g->e[i].dest;
        int weight=g->e[i].weight;
        if(dist[u]!=INT_MAX&&dist[u]+weight<dist[v])
        {
            printf("graph contains negative weight cycle\n");
            return;
        }
    }
    printarr(dist,V);
    return;
}
int main()
{
    int V,E;
    printf("Enter the no of vertices\n");
    scanf("%d",&V);
    printf("Enter the no of edges\n");
    scanf("%d",&E);
    struct graph *g=creategraph(V,E);
    for (int i = 0; i < E; i++)
    {
        printf("Enter the source,destination and weight of the edge\n");
        scanf("%d",&g->e[i].src);
        scanf("%d",&g->e[i].dest);
        scanf("%d",&g->e[i].weight);



    }
    belmanford(g,0);
    return 0;
}
