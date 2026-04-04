/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* adj[100];
int visited[100];
struct Node* createNode(int v)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=v;
    newNode->next=NULL;
    return newNode;
}
void addEdge(int u,int v)
{
    struct Node* newNode=createNode(v);
    newNode->next=adj[u];
    adj[u]=newNode;
}
void dfs(int v)
{
    struct Node* temp;
    visited[v]=1;
    printf("%d ",v);
    temp=adj[v];
    while(temp!=NULL)
    {
        if(!visited[temp->data])
        {
            dfs(temp->data);
        }
        temp=temp->next;
    }
}
int main()
{
    int n,m,u,v,s,i;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("Enter no. of edges:");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        adj[i]=NULL;
        visited[i]=0;
    }
    printf("Enter edges (u v):");
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    printf("Enter starting vertex:");
    scanf("%d",&s);
    printf("DFS traversal:");
    dfs(s);
    return 0;
}