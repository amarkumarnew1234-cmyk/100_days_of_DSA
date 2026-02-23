/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create(int n)
{
    struct node *head=NULL,*temp=NULL,*newnode=NULL;
    int i;

    printf("Enter %d elements:",n);

    for(i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    return head;
}

struct node* merge(struct node *h1,struct node *h2)
{
    struct node *head=NULL,*temp=NULL,*newnode=NULL;

    while(h1!=NULL && h2!=NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;

        if(h1->data<h2->data)
        {
            newnode->data=h1->data;
            h1=h1->next;
        }
        else
        {
            newnode->data=h2->data;
            h2=h2->next;
        }

        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    while(h1!=NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=h1->data;
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }

        h1=h1->next;
    }

    while(h2!=NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=h2->data;
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }

        h2=h2->next;
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp=head;

    printf("Merged list:");

    while(temp!=NULL)
    {
        printf("%d",temp->data);
        if(temp->next!=NULL)
        {
            printf(" ");
        }
        temp=temp->next;
    }
}

int main()
{
    int n,m;
    struct node *head1=NULL,*head2=NULL,*result=NULL;

    printf("Enter no. of elements in first list:");
    scanf("%d",&n);
    head1=create(n);

    printf("Enter no. of elements in second list:");
    scanf("%d",&m);
    head2=create(m);

    result=merge(head1,head2);

    display(result);

    return 0;
}