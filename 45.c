/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node* newnode(int val)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node* buildtree(int arr[],int n)
{
    if(n==0||arr[0]==-1)
    return NULL;
    struct node *root=newnode(arr[0]);
    struct node *queue[n];
    int front=0,rear=0;
    queue[rear++]=root;
    int i=1;
    while(i<n)
    {
        struct node *curr=queue[front++];
        if(arr[i]!=-1)
        {
            curr->left=newnode(arr[i]);
            queue[rear++]=curr->left;
        }
        i++;
        if(i<n&&arr[i]!=-1)
        {
            curr->right=newnode(arr[i]);
            queue[rear++]=curr->right;
        }
        i++;
    }
    return root;
}
int height(struct node *root)
{
    if(root==NULL)
    return 0;
    int l=height(root->left);
    int r=height(root->right);
    if(l>r)
    return l+1;
    else
    return r+1;
}
int main()
{
    int n,i;
    printf("Enter no. of nodes:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    struct node *root=buildtree(arr,n);
    printf("%d",height(root));
    return 0;
}