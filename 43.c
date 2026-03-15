/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* queue[MAX];
int front=0,rear=0;
void enqueue(struct node* n)
{
    queue[rear++]=n;
}
struct node* dequeue()
{
    return queue[front++];
}
struct node* createNode(int val)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(struct node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main()
{
    int n,i,arr[MAX];
    printf("Enter no. of nodes:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    if(arr[0]==-1)
    return 0;
    struct node* root=createNode(arr[0]);
    enqueue(root);
    i=1;
    while(i<n)
    {
        struct node* temp=dequeue();
        if(arr[i]!=-1)
        {
            temp->left=createNode(arr[i]);
            enqueue(temp->left);
        }
        i++;
        if(i<n && arr[i]!=-1)
        {
            temp->right=createNode(arr[i]);
            enqueue(temp->right);
        }
        i++;
    }
    inorder(root);
    return 0;
}
