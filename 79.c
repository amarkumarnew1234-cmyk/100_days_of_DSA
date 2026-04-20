/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include<stdio.h>
#include<limits.h>
int main(){
    int n,m,u,v,w,src;
    printf("Enter no. of vertices and edges:");
    scanf("%d%d",&n,&m);
    int cost[105][105];
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cost[i][j]=INT_MAX;
    printf("Enter edges (u v w):");
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        cost[u][v]=w;
    }
    printf("Enter source:");
    scanf("%d",&src);
    int dist[105],vis[105]={0};
    for(int i=1;i<=n;i++)dist[i]=INT_MAX;
    dist[src]=0;
    for(int i=1;i<=n;i++){
        int min=INT_MAX,idx=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dist[j]<min){
                min=dist[j];
                idx=j;
            }
        }
        if(idx==-1)break;
        vis[idx]=1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&cost[idx][j]!=INT_MAX&&dist[idx]+cost[idx][j]<dist[j]){
                dist[j]=dist[idx]+cost[idx][j];
            }
        }
    }
    printf("Output:");
    for(int i=1;i<=n;i++)printf("%d ",dist[i]);
    return 0;
}