/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};
int main(){
    int n;
    printf("Enter no.:");
    scanf("%d",&n);
    struct Node*head=NULL,*tail=NULL;
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=val;
        newNode->next=NULL;
        newNode->prev=NULL;
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL)printf(" ");
        temp=temp->next;
    }
    return 0;
}