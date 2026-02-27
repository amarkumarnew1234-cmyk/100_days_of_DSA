/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* create(int val)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=val;
    temp->next=NULL;
    return temp;
}

int length(struct Node* head)
{
    int c=0;

    while(head!=NULL)
    {
        c++;
        head=head->next;
    }

    return c;
}

struct Node* intersection(struct Node* h1,struct Node* h2)
{
    int l1=length(h1);
    int l2=length(h2);

    int diff;
    struct Node *p1=h1,*p2=h2;

    if(l1>l2)
    {
        diff=l1-l2;

        for(int i=0;i<diff;i++)
            p1=p1->next;
    }
    else
    {
        diff=l2-l1;

        for(int i=0;i<diff;i++)
            p2=p2->next;
    }

    while(p1!=NULL && p2!=NULL)
    {
        if(p1==p2)
            return p1;

        p1=p1->next;
        p2=p2->next;
    }

    return NULL;
}

int main()
{
    int n,m,x;

    printf("Enter no. of nodes in first list:");
    scanf("%d",&n);

    struct Node *h1=NULL,*t1=NULL;

    printf("Enter elements of first list:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        struct Node* temp=create(x);

        if(h1==NULL)
        {
            h1=temp;
            t1=temp;
        }
        else
        {
            t1->next=temp;
            t1=temp;
        }
    }

    printf("Enter no. of nodes in second list:");
    scanf("%d",&m);

    struct Node *h2=NULL,*t2=NULL;

    printf("Enter elements of second list:");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        struct Node* temp=create(x);

        if(h2==NULL)
        {
            h2=temp;
            t2=temp;
        }
        else
        {
            t2->next=temp;
            t2=temp;
        }
    }

    struct Node* ans=intersection(h1,h2);

    if(ans!=NULL)
        printf("Intersection:%d",ans->data);
    else
        printf("No Intersection");

    return 0;
}