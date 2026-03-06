/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{int data;struct node* next;};
struct node* top=NULL;
void push(int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top;
    top=temp;
}
int pop(){
    struct node* temp=top;
    int val=temp->data;
    top=top->next;
    free(temp);
    return val;
}
int main(){
    char exp[100];
    int i=0;
    printf("Enter postfix expression:");
    fgets(exp,sizeof(exp),stdin);
    while(exp[i]!='\0'){
        if(isdigit(exp[i])) push(exp[i]-'0');
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            int b=pop();
            int a=pop();
            int r;
            if(exp[i]=='+') r=a+b;
            else if(exp[i]=='-') r=a-b;
            else if(exp[i]=='*') r=a*b;
            else r=a/b;
            push(r);
        }
        i++;
    }
    printf("Result:%d",pop());
    return 0;
}