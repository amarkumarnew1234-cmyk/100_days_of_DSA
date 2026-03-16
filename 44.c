/*Problem Statement:
Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 5 2 6 7 3 1*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* create(int arr[],int n,int i)
{
    if(i>=n||arr[i]==-1)
    {
        return NULL;
    }
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=arr[i];
    temp->left=create(arr,n,2*i+1);
    temp->right=create(arr,n,2*i+2);
    return temp;
}

void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main()
{
    int n;
    printf("Enter no. of nodes:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    struct node* root=create(arr,n,0);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}