/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* adj[100];
int indegree[100];
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
    indegree[v]++;
}
int main(){
    int n,m,u,v,i;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("Enter no. of edges:");
    scanf("%d",&m);
    for(i=0;i<n;i++){
        adj[i]=NULL;
        indegree[i]=0;
    }
    printf("Enter directed edges (u v):\n");
    for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        addEdge(u,v);
    }
    int queue[100],front=0,rear=0;
    for(i=0;i<n;i++){
        if(indegree[i]==0)
            queue[rear++]=i;
    }
    int count=0;
    printf("Topological order:");
    while(front<rear){
        int node=queue[front++];
        printf("%d ",node);
        count++;
        struct Node* temp=adj[node];
        while(temp!=NULL){
            int x=temp->data;
            indegree[x]--;
            if(indegree[x]==0)
                queue[rear++]=x;
            temp=temp->next;
        }
    }
    if(count!=n)
        printf("\nCycle detected");
    return 0;
}