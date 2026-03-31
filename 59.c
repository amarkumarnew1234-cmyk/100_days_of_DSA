/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node*left;
    struct Node*right;
};
struct Node*create(int val){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
int search(int inorder[],int start,int end,int val){
    int i;
    for(i=start;i<=end;i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}
struct Node*build(int inorder[],int postorder[],int start,int end,int*index){
    if(start>end){
        return NULL;
    }
    struct Node*root=create(postorder[*index]);
    (*index)--;
    if(start==end){
        return root;
    }
    int pos=search(inorder,start,end,root->val);
    root->right=build(inorder,postorder,pos+1,end,index);
    root->left=build(inorder,postorder,start,pos-1,index);
    return root;
}
void preorder(struct Node*root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int n;
    printf("Enter no.of nodes:");
    scanf("%d",&n);
    int inorder[n];
    int postorder[n];
    int i;
    printf("Enter inorder:");
    for(i=0;i<n;i++){
        scanf("%d",&inorder[i]);
    }
    printf("Enter postorder:");
    for(i=0;i<n;i++){
        scanf("%d",&postorder[i]);
    }
    int index=n-1;
    struct Node*root=build(inorder,postorder,0,n-1,&index);
    printf("Preorder:");
    preorder(root);
    return 0;
}