/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/
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
struct Node*build(int preorder[],int inorder[],int start,int end,int*index){
    if(start>end){
        return NULL;
    }
    struct Node*root=create(preorder[*index]);
    (*index)++;
    if(start==end){
        return root;
    }
    int pos=search(inorder,start,end,root->val);
    root->left=build(preorder,inorder,start,pos-1,index);
    root->right=build(preorder,inorder,pos+1,end,index);
    return root;
}
void postorder(struct Node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}
int main(){
    int n;
    printf("Enter no.of nodes:");
    scanf("%d",&n);
    int preorder[n],inorder[n];
    int i;
    printf("Enter preorder:");
    for(i=0;i<n;i++){
        scanf("%d",&preorder[i]);
    }
    printf("Enter inorder:");
    for(i=0;i<n;i++){
        scanf("%d",&inorder[i]);
    }
    int index=0;
    struct Node*root=build(preorder,inorder,0,n-1,&index);
    printf("Postorder:");
    postorder(root);
    return 0;
}
