/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include<stdio.h>
#include<string.h>
#define SIZE 100
int table[SIZE];
int m;
int hash(int key){return key%m;}
void insert(int key)
{
    int h=hash(key);
    for(int i=0;i<m;i++)
    {
        int idx=(h+i*i)%m;
        if(table[idx]==-1)
        {
            table[idx]=key;
            return;
        }
    }
}
void search(int key)
{
    int h=hash(key);
    for(int i=0;i<m;i++)
    {
        int idx=(h+i*i)%m;
        if(table[idx]==key)
        {
            printf("FOUND\n");
            return;
        }
        if(table[idx]==-1)break;
    }
    printf("NOT FOUND\n");
}
int main()
{
    int q;
    printf("Enter table size:");
    scanf("%d",&m);
    for(int i=0;i<m;i++)table[i]=-1;
    printf("Enter no. of operations:");
    scanf("%d",&q);
    char op[10];
    int key;
    for(int i=0;i<q;i++)
    {
        scanf("%s%d",op,&key);
        if(strcmp(op,"INSERT")==0)insert(key);
        else if(strcmp(op,"SEARCH")==0)search(key);
    }
    return 0;
}