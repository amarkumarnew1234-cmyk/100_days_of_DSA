/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/
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
void zigzag(struct node* root){
    if(root==NULL){
        return;
    }
    struct node* queue[1000];
    int front=0,rear=0;
    queue[rear++]=root;
    int leftToRight=1;
    while(front<rear){
        int size=rear-front;
        int arr[1000];
        for(int i=0;i<size;i++){
            struct node* curr=queue[front++];
            int index=leftToRight?i:(size-1-i);
            arr[index]=curr->data;
            if(curr->left!=NULL){
                queue[rear++]=curr->left;
            }
            if(curr->right!=NULL){
                queue[rear++]=curr->right;
            }
        }
        for(int i=0;i<size;i++){
            printf("%d",arr[i]);
            if(!(front>=rear && i==size-1)){
                printf(" ");
            }
        }
        leftToRight=!leftToRight;
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
    zigzag(root);
    return 0;
}