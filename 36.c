/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/
#include<stdio.h>
#define MAX 100
int main()
{
    int q[MAX],front=0,rear=-1,n,m,i;
    printf("Enter no.of elements:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(i=0;i<n;i++)
    {
        rear=(rear+1)%MAX;
        scanf("%d",&q[rear]);
    }
    printf("Enter no.of dequeue operations:");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        front=(front+1)%MAX;
        rear=(rear+1)%MAX;
        q[rear]=q[(front-1+MAX)%MAX];
    }
    printf("Queue elements:");
    i=front;
    while(i!=((rear+1)%MAX))
    {
        printf("%d ",q[i]);
        i=(i+1)%MAX;
    }
    return 0;
}