/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node* next;
};
struct Node* createNode(int val)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=val;
    newNode->next=NULL;
    return newNode;
}
int main()
{
    int n,m;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("Enter no. of edges:");
    scanf("%d",&m);
    struct Node* adj[n];
    for(int i=0;i<n;i++)
        adj[i]=NULL;
    int type;
    printf("Enter 1 for directed, 0 for undirected:");
    scanf("%d",&type);
    printf("Enter edges (u v):");
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        struct Node* newNode=createNode(v);
        newNode->next=adj[u];
        adj[u]=newNode;
        if(type==0)
        {
            struct Node* newNode2=createNode(u);
            newNode2->next=adj[v];
            adj[v]=newNode2;
        }
    }
    printf("Adjacency List:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d:",i);
        struct Node* temp=adj[i];
        while(temp!=NULL)
        {
            printf("%d ",temp->val);
            temp=temp->next;
        }
        printf("\n");
    }
    return 0;
}