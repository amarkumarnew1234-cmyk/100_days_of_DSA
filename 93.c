/*Problem: Sort an array using insertion sort.
Stable sort. Good for nearly sorted arrays.*/
#include<stdio.h>
int main(){
    int n;
    printf("Enter no.of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    printf("Sorted array:");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}