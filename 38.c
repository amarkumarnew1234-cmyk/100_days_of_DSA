/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include<stdio.h>
#include<string.h>
#define MAX 100
int deque[MAX];
int front=-1,rear=-1;
void push_front(int val)
{
    if(front==0)
    {
        printf("Overflow\n");
        return;
    }
    if(front==-1)
    {
        front=rear=0;
    }
    else
    {
        front--;
    }
    deque[front]=val;
}
void push_back(int val)
{
    if(rear==MAX-1)
    {
        printf("Overflow\n");
        return;
    }
    if(front==-1)
    {
        front=rear=0;
    }
    else
    {
        rear++;
    }
    deque[rear]=val;
}
void pop_front()
{
    if(front==-1)
    {
        printf("Underflow\n");
        return;
    }
    printf("%d\n",deque[front]);
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}
void pop_back()
{
    if(rear==-1)
    {
        printf("Underflow\n");
        return;
    }
    printf("%d\n",deque[rear]);
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        rear--;
    }
}
void get_front()
{
    if(front==-1)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n",deque[front]);
}
void get_back()
{
    if(rear==-1)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n",deque[rear]);
}
void get_size()
{
    if(front==-1)
    {
        printf("0\n");
        return;
    }
    printf("%d\n",rear-front+1);
}
void is_empty()
{
    if(front==-1)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
}
int main()
{
    int n,i,val;
    char op[20];
    printf("Enter no.:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",op);
        if(strcmp(op,"push_front")==0)
        {
            printf("Enter no.:");
            scanf("%d",&val);
            push_front(val);
        }
        else if(strcmp(op,"push_back")==0)
        {
            printf("Enter no.:");
            scanf("%d",&val);
            push_back(val);
        }
        else if(strcmp(op,"pop_front")==0)
        {
            pop_front();
        }
        else if(strcmp(op,"pop_back")==0)
        {
            pop_back();
        }
        else if(strcmp(op,"front")==0)
        {
            get_front();
        }
        else if(strcmp(op,"back")==0)
        {
            get_back();
        }
        else if(strcmp(op,"size")==0)
        {
            get_size();
        }
        else if(strcmp(op,"empty")==0)
        {
            is_empty();
        }
    }
    return 0;
}
