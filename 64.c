/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* adj[100];
int visited[100];
int queue[100];
int front=0;
int rear=0;
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
void enqueue(int v)
{
    queue[rear]=v;
    rear++;
}
int dequeue()
{
    int val=queue[front];
    front++;
    return val;
}
int isEmpty()
{
    if(front==rear)
    {
        return 1;
    }
    return 0;
}
void bfs(int s)
{
    struct Node* temp;
    visited[s]=1;
    enqueue(s);
    while(!isEmpty())
    {
        int v=dequeue();
        printf("%d ",v);
        temp=adj[v];
        while(temp!=NULL)
        {
            if(!visited[temp->data])
            {
                visited[temp->data]=1;
                enqueue(temp->data);
            }
            temp=temp->next;
        }
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
    printf("BFS traversal:");
    bfs(s);
    return 0;
}