/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/
#include<stdio.h>
#include<string.h>
#define MAX 100
int heap[MAX];
int size=0;
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void heapify_up(int i)
{
    while(i>0 && heap[(i-1)/2]>heap[i])
    {
        swap(&heap[(i-1)/2],&heap[i]);
        i=(i-1)/2;
    }
}
void heapify_down(int i)
{
    int l,r,small;
    while(1)
    {
        l=2*i+1;
        r=2*i+2;
        small=i;
        if(l<size && heap[l]<heap[small]) small=l;
        if(r<size && heap[r]<heap[small]) small=r;
        if(small!=i)
        {
            swap(&heap[i],&heap[small]);
            i=small;
        }
        else
        break;
    }
}
void insert(int x)
{
    if(size==MAX) return;
    heap[size]=x;
    heapify_up(size);
    size++;
}
int extractMin()
{
    if(size==0) return -1;
    int root=heap[0];
    heap[0]=heap[size-1];
    size--;
    heapify_down(0);
    return root;
}
int peek()
{
    if(size==0) return -1;
    return heap[0];
}
int main()
{
    int n,x;
    char op[20];
    printf("Enter no.of operations:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",op);
        if(strcmp(op,"insert")==0)
        {
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"extractMin")==0)
        {
            printf("%d\n",extractMin());
        }
        else if(strcmp(op,"peek")==0)
        {
            printf("%d\n",peek());
        }
    }
    return 0;
}