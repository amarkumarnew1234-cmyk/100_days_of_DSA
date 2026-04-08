/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* adj[100];
int visited[100],stack[100],top=-1;
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
void dfs(int v){
    visited[v]=1;
    struct Node* temp=adj[v];
    while(temp!=NULL){
        int x=temp->data;
        if(!visited[x])
            dfs(x);
        temp=temp->next;
    }
    stack[++top]=v;
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
    printf("Enter directed edges (u v):\n");
    for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        addEdge(u,v);
    }
    for(i=0;i<n;i++){
        if(!visited[i])
            dfs(i);
    }
    printf("Topological order:");
    while(top!=-1)
        printf("%d ",stack[top--]);
    return 0;
}