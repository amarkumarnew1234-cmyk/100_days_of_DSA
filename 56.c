/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/
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
int isMirror(struct node* a,struct node* b){
    if(a==NULL && b==NULL){
        return 1;
    }
    if(a==NULL || b==NULL){
        return 0;
    }
    if(a->data!=b->data){
        return 0;
    }
    return isMirror(a->left,b->right) && isMirror(a->right,b->left);
}
int isSymmetric(struct node* root){
    if(root==NULL){
        return 1;
    }
    return isMirror(root->left,root->right);
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
    if(isSymmetric(root)){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}