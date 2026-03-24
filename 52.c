/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create(int data){
    if(data==-1){
        return NULL;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* buildTree(int arr[],int n){
    if(n==0 || arr[0]==-1){
        return NULL;
    }
    struct node* root=create(arr[0]);
    struct node* queue[1000];
    int front=0,rear=0;
    queue[rear++]=root;
    int i=1;
    while(i<n){
        struct node* current=queue[front++];
        if(i<n){
            current->left=create(arr[i]);
            if(current->left!=NULL){
                queue[rear++]=current->left;
            }
            i++;
        }
        if(i<n){
            current->right=create(arr[i]);
            if(current->right!=NULL){
                queue[rear++]=current->right;
            }
            i++;
        }
    }
    return root;
}
struct node* lca(struct node* root,int a,int b){
    if(root==NULL){
        return NULL;
    }
    if(root->data==a || root->data==b){
        return root;
    }
    struct node* left=lca(root->left,a,b);
    struct node* right=lca(root->right,a,b);
    if(left!=NULL && right!=NULL){
        return root;
    }
    if(left!=NULL){
        return left;
    }else{
        return right;
    }
}
int main(){
    int n;
    printf("Enter no.of nodes:");
    scanf("%d",&n);
    int arr[1000];
    printf("Enter elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct node* root=buildTree(arr,n);
    int a,b;
    printf("Enter two nodes:");
    scanf("%d%d",&a,&b);
    struct node* ans=lca(root,a,b);
    printf("LCA:%d",ans->data);
    return 0;
}