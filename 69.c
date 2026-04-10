/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node{
    int v,weight;
    struct Node* next;
};
struct Node* adj[100];
struct Node* createNode(int v,int w){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->v=v;
    newNode->weight=w;
    newNode->next=NULL;
    return newNode;
}
void addEdge(int u,int v,int w){
    struct Node* newNode=createNode(v,w);
    newNode->next=adj[u];
    adj[u]=newNode;
}
struct HeapNode{
    int vertex,dist;
};
struct MinHeap{
    int size;
    struct HeapNode arr[100];
};
void swap(struct HeapNode* a,struct HeapNode* b){
    struct HeapNode temp=*a;
    *a=*b;
    *b=temp;
}
void heapifyUp(struct MinHeap* h,int i){
    while(i>0 && h->arr[(i-1)/2].dist>h->arr[i].dist){
        swap(&h->arr[i],&h->arr[(i-1)/2]);
        i=(i-1)/2;
    }
}
void heapifyDown(struct MinHeap* h,int i){
    int smallest=i;
    int l=2*i+1,r=2*i+2;
    if(l<h->size && h->arr[l].dist<h->arr[smallest].dist)
        smallest=l;
    if(r<h->size && h->arr[r].dist<h->arr[smallest].dist)
        smallest=r;
    if(smallest!=i){
        swap(&h->arr[i],&h->arr[smallest]);
        heapifyDown(h,smallest);
    }
}
void push(struct MinHeap* h,int v,int dist){
    h->arr[h->size].vertex=v;
    h->arr[h->size].dist=dist;
    heapifyUp(h,h->size);
    h->size++;
}
struct HeapNode pop(struct MinHeap* h){
    struct HeapNode root=h->arr[0];
    h->arr[0]=h->arr[h->size-1];
    h->size--;
    heapifyDown(h,0);
    return root;
}
int isEmpty(struct MinHeap* h){
    return h->size==0;
}
int main(){
    int n,m,u,v,w,i,src;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("Enter no. of edges:");
    scanf("%d",&m);
    for(i=0;i<n;i++)
        adj[i]=NULL;
    printf("Enter edges (u v weight):\n");
    for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        addEdge(u,v,w);
    }
    printf("Enter source:");
    scanf("%d",&src);
    int dist[100];
    for(i=0;i<n;i++)
        dist[i]=INT_MAX;
    struct MinHeap heap;
    heap.size=0;
    dist[src]=0;
    push(&heap,src,0);
    while(!isEmpty(&heap)){
        struct HeapNode node=pop(&heap);
        int u=node.vertex;
        int d=node.dist;
        if(d>dist[u])
            continue;
        struct Node* temp=adj[u];
        while(temp!=NULL){
            int v=temp->v;
            int weight=temp->weight;
            if(dist[u]+weight<dist[v]){
                dist[v]=dist[u]+weight;
                push(&heap,v,dist[v]);
            }
            temp=temp->next;
        }
    }
    printf("Shortest distances:\n");
    for(i=0;i<n;i++)
        printf("%d -> %d\n",i,dist[i]);
    return 0;
}