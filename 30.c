/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int coef;
    int exp;
    struct node *next;
};
struct node *head=NULL;
void insert(int c,int e){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->coef=c;
    temp->exp=e;
    temp->next=NULL;
    if(head==NULL||head->exp<e){
        temp->next=head;
        head=temp;
    }else{
        struct node *p=head;
        while(p->next!=NULL&&p->next->exp>e)
            p=p->next;
        temp->next=p->next;
        p->next=temp;
    }
}
void display(){
    struct node *p=head;
    while(p!=NULL){
        if(p->exp==0)
            printf("%d",p->coef);
        else if(p->exp==1)
            printf("%dx",p->coef);
        else
            printf("%dx^%d",p->coef,p->exp);
        if(p->next!=NULL)
            printf(" + ");
        p=p->next;
    }
}
int main(){
    int n,c,e,i;
    printf("Enter no. of terms:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter coefficient and exponent:");
        scanf("%d%d",&c,&e);
        insert(c,e);
    }
    display();
    return 0;
}