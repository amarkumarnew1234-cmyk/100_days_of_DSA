/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/
#include<stdio.h>
int n,m,adj[100][100],vis[100];
void dfs(int v){
    vis[v]=1;
    for(int i=1;i<=n;i++){
        if(adj[v][i]==1&&vis[i]==0)dfs(i);
    }
}
int main(){
    int i,u,v;
    printf("Enter no. of nodes and edges:");
    scanf("%d%d",&n,&m);
    printf("Enter edges:");
    for(i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        adj[u][v]=adj[v][u]=1;
    }
    dfs(1);
    for(i=1;i<=n;i++){
        if(vis[i]==0){
            printf("Output:NOT CONNECTED");
            return 0;
        }
    }
    printf("Output:CONNECTED");
    return 0;
}