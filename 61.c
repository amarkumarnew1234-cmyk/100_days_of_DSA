/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/
#include<stdio.h>
int main()
{
    int n,m;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("Enter no. of edges:");
    scanf("%d",&m);
    int adj[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            adj[i][j]=0;
    }
    int type;
    printf("Enter 1 for directed, 0 for undirected:");
    scanf("%d",&type);
    printf("Enter edges (u v):");
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u][v]=1;
        if(type==0)
            adj[v][u]=1;
    }
    printf("Adjacency Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
    return 0;
}