/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/
#include<stdio.h>
int main()
{
    int n,i,k;
    printf("Enter no.of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter k:");
    scanf("%d",&k);
    k=k%n;
    for(i=n-k;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    for(i=0;i<n-k;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
