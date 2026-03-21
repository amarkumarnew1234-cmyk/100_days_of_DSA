/*Problem: BST Insert

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
    struct node* root=NULL;
    printf("Enter elements:");
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        root=insert(root,x);
    }
    printf("Inorder:");
    inorder(root);
    return 0;
}