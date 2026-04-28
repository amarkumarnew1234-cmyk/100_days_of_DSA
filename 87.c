/*Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/
#include<stdio.h>
int main(){
    int n,a[100],x;
    printf("Enter no.of elements:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    printf("Sorted array:");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\nEnter element:");
    scanf("%d",&x);
    int low=0,high=n-1,mid,found=-1;
    while(low<=high){
        mid=low+(high-low)/2;
        if(a[mid]==x){
            found=mid;
            break;
        }else if(a[mid]<x){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    if(found!=-1) printf("Found at index:%d",found);
    else printf("Not found");
    return 0;
}