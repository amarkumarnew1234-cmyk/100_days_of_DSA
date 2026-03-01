/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    int n,i,k;
    struct node *head=NULL,*temp=NULL,*newnode=NULL,*tail=NULL,*curr=NULL;
    printf("Enter no. of nodes:");
    scanf("%d",&n);
    if(n<=0) return 0;
    printf("Enter elements:");
    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    printf("Enter k:");
    scanf("%d",&k);
    k=k%n;
    if(k!=0){
        tail=head;
        while(tail->next!=NULL) tail=tail->next;
        tail->next=head;
        curr=head;
        for(i=1;i<n-k;i++) curr=curr->next;
        head=curr->next;
        curr->next=NULL;
    }
    temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL) printf(" ");
        temp=temp->next;
    }
    return 0;
}