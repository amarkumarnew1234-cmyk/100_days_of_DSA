/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/
#include<stdio.h>
int n,m,adj[100][100],vis[100];
void dfs(int v){
    vis[v]=1;
    for(int i=1;i<=n;i++){
        if(adj[v][i]==1&&vis[i]==0)dfs(i);
    }
}
int main(){
    int i,u,v,count=0;
    printf("Enter no. of nodes and edges:");
    scanf("%d%d",&n,&m);
    printf("Enter edges:");
    for(i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        adj[u][v]=adj[v][u]=1;
    }
    for(i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
            count++;
        }
    }
    printf("Output:%d",count);
    return 0;
}