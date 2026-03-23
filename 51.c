/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* insert(struct node* root,int data){
    if(root==NULL){
        return create(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }else{
        root->right=insert(root->right,data);
    }
    return root;
}
struct node* lca(struct node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(n1<root->data && n2<root->data){
        return lca(root->left,n1,n2);
    }
    if(n1>root->data && n2>root->data){
        return lca(root->right,n1,n2);
    }
    return root;
}
int main(){
    int n;
    printf("Enter no.of nodes:");
    scanf("%d",&n);
    struct node* root=NULL;
    printf("Enter elements:");
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        root=insert(root,x);
    }
    int a,b;
    printf("Enter two nodes:");
    scanf("%d%d",&a,&b);
    struct node* ans=lca(root,a,b);
    printf("LCA:%d",ans->data);
    return 0;
}