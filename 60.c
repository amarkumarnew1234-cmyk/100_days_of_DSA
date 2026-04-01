/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int val)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node* buildTree(int arr[],int n)
{
    if(n==0)
        return NULL;
    struct Node* root=createNode(arr[0]);
    struct Node* queue[n];
    int front=0,rear=0;
    queue[rear++]=root;
    int i=1;
    while(i<n)
    {
        struct Node* curr=queue[front++];
        if(i<n)
        {
            curr->left=createNode(arr[i]);
            queue[rear++]=curr->left;
            i++;
        }
        if(i<n)
        {
            curr->right=createNode(arr[i]);
            queue[rear++]=curr->right;
            i++;
        }
    }
    return root;
}
int isComplete(struct Node* root,int index,int n)
{
    if(root==NULL)
        return 1;
    if(index>=n)
        return 0;
    return isComplete(root->left,2*index+1,n) && isComplete(root->right,2*index+2,n);
}
int isHeap(struct Node* root)
{
    if(root->left==NULL && root->right==NULL)
        return 1;
    if(root->right==NULL)
        return root->val<=root->left->val;
    else
    {
        if(root->val<=root->left->val && root->val<=root->right->val)
            return isHeap(root->left) && isHeap(root->right);
        else
            return 0;
    }
}
int main()
{
    int n;
    printf("Enter no. of nodes:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter level order:");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    struct Node* root=buildTree(arr,n);
    if(isComplete(root,0,n) && isHeap(root))
        printf("YES");
    else
        printf("NO");
    return 0;
}