/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>

char stack[100];
int top=-1;

void push(char c){
    stack[++top]=c;
}

char pop(){
    return stack[top--];
}

int precedence(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}

int main(){
    char infix[100],postfix[100];
    int k=0;
    printf("Enter infix expression:");
    scanf("%s",infix);
    for(int i=0;i<strlen(infix);i++){
        char c=infix[i];
        if(isalnum(c)){
            postfix[k++]=c;
        }
        else if(c=='('){
            push(c);
        }
        else if(c==')'){
            while(stack[top]!='('){
                postfix[k++]=pop();
            }
            pop();
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(c)){
                postfix[k++]=pop();
            }
            push(c);
        }
    }
    while(top!=-1){
        postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("Postfix expression:%s",postfix);
}