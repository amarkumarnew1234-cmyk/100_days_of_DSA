/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/
#include<stdio.h>
#include<limits.h>
int main(){
    int n,m,i,u,v,w;
    printf("Enter no. of nodes and edges:");
    scanf("%d%d",&n,&m);
    int cost[100][100];
    for(i=1;i<=n;i++)for(int j=1;j<=n;j++)cost[i][j]=INT_MAX;
    printf("Enter edges (u v w):");
    for(i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        cost[u][v]=cost[v][u]=w;
    }
    int vis[100]={0},mincost=0,edges=0;
    vis[1]=1;
    while(edges<n-1){
        int min=INT_MAX,a=-1,b=-1;
        for(i=1;i<=n;i++){
            if(vis[i]){
                for(int j=1;j<=n;j++){
                    if(!vis[j]&&cost[i][j]<min){
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        if(a!=-1&&b!=-1){
            vis[b]=1;
            mincost+=min;
            edges++;
        }
    }
    printf("Output:%d",mincost);
    return 0;
}