/*Problem: Height of Binary Tree

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
struct node* create(int data){
    if(data==-1) return NULL;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* buildTree(int arr[],int n){
    if(n==0||arr[0]==-1) return NULL;
    struct node* root=create(arr[0]);
    struct node* queue[1000];
    int front=0,rear=0;
    queue[rear++]=root;
    int i=1;
    while(i<n){
        struct node* current=queue[front++];
        if(i<n){
            current->left=create(arr[i]);
            if(current->left!=NULL) queue[rear++]=current->left;
            i++;
        }
        if(i<n){
            current->right=create(arr[i]);
            if(current->right!=NULL) queue[rear++]=current->right;
            i++;
        }
    }
    return root;
}
int height(struct node* root){
    if(root==NULL) return 0;
    int left=height(root->left);
    int right=height(root->right);
    if(left>right) return left+1;
    else return right+1;
}
int main(){
    int n;
    printf("Enter no.of nodes:");
    scanf("%d",&n);
    int arr[1000];
    printf("Enter elements:");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    struct node* root=buildTree(arr,n);
    printf("Height:%d",height(root));
    return 0;
}