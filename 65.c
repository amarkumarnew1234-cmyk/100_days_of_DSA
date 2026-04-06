/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* adj[100];
int visited[100];
struct Node* createNode(int v){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=v;
    newNode->next=NULL;
    return newNode;
}
void addEdge(int u,int v){
    struct Node* newNode=createNode(v);
    newNode->next=adj[u];
    adj[u]=newNode;
}
int dfs(int v,int parent){
    visited[v]=1;
    struct Node* temp=adj[v];
    while(temp!=NULL){
        int x=temp->data;
        if(!visited[x]){
            if(dfs(x,v))
                return 1;
        }
        else if(x!=parent)
            return 1;
        temp=temp->next;
    }
    return 0;
}
int main(){
    int n,m,u,v,i;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("Enter no. of edges:");
    scanf("%d",&m);
    for(i=0;i<n;i++){
        adj[i]=NULL;
        visited[i]=0;
    }
    printf("Enter edges (u v):\n");
    for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    for(i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(i,-1)){
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}