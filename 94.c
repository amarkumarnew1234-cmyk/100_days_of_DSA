/*Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter no.of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    int *count=(int*)calloc(max+1,sizeof(int));
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    int *output=(int*)malloc(n*sizeof(int));
    for(int i=n-1;i>=0;i--){
        output[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }
    printf("Sorted array:");
    for(int i=0;i<n;i++){
        printf("%d ",output[i]);
    }
    free(count);
    free(output);
    return 0;
}