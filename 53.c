/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
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
void verticalOrder(struct node* root){
    if(root==NULL){
        return;
    }
    struct node* qnode[1000];
    int qhd[1000];
    int front=0,rear=0;
    int col[2000][100];
    int count[2000]={0};
    int min=1000,max=1000;
    qnode[rear]=root;
    qhd[rear]=1000;
    rear++;
    while(front<rear){
        struct node* curr=qnode[front];
        int hd=qhd[front];
        front++;
        col[hd][count[hd]++]=curr->data;
        if(hd<min){
            min=hd;
        }
        if(hd>max){
            max=hd;
        }
        if(curr->left!=NULL){
            qnode[rear]=curr->left;
            qhd[rear]=hd-1;
            rear++;
        }
        if(curr->right!=NULL){
            qnode[rear]=curr->right;
            qhd[rear]=hd+1;
            rear++;
        }
    }
    for(int i=min;i<=max;i++){
        for(int j=0;j<count[i];j++){
            printf("%d",col[i][j]);
            if(j<count[i]-1){
                printf(" ");
            }
        }
        printf("\n");
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
    verticalOrder(root);
    return 0;
}