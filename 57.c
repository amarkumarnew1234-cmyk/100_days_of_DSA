/*Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.*/
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
        struct node* curr=queue[front++];
        if(i<n){
            curr->left=create(arr[i]);
            if(curr->left!=NULL){
                queue[rear++]=curr->left;
            }
            i++;
        }
        if(i<n){
            curr->right=create(arr[i]);
            if(curr->right!=NULL){
                queue[rear++]=curr->right;
            }
            i++;
        }
    }
    return root;
}
void mirror(struct node* root){
    if(root==NULL){
        return;
    }
    struct node* temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirror(root->left);
    mirror(root->right);
}
void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
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
    mirror(root);
    inorder(root);
    return 0;
}