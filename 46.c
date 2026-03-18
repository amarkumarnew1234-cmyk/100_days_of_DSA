/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void levelorder(struct node* root){
    if(root==NULL) return;
    struct node* queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        int size=rear-front;
        for(int i=0;i<size;i++){
            struct node* temp=queue[front++];
            printf("%d ",temp->data);
            if(temp->left) queue[rear++]=temp->left;
            if(temp->right) queue[rear++]=temp->right;
        }
        printf("\n");
    }
}
int main(){
    int n;
    printf("Enter no.of nodes:");
    scanf("%d",&n);
    if(n==0) return 0;
    int arr[100];
    printf("Enter level order (-1 for NULL):");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    struct node* nodes[100];
    for(int i=0;i<n;i++){
        if(arr[i]==-1) nodes[i]=NULL;
        else nodes[i]=create(arr[i]);
    }
    for(int i=0;i<n;i++){
        if(nodes[i]!=NULL){
            int l=2*i+1,r=2*i+2;
            if(l<n) nodes[i]->left=nodes[l];
            if(r<n) nodes[i]->right=nodes[r];
        }
    }
    printf("Level order traversal:\n");
    levelorder(nodes[0]);
    return 0;
}