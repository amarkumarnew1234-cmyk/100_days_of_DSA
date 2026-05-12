/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int val;
    int idx;
}Pair;
void merge(Pair a[],int left,int mid,int right,int count[]){
    int n=right-left+1;
    Pair temp[n];
    int i=left,j=mid+1,k=0,rc=0;
    while(i<=mid&&j<=right){
        if(a[j].val<a[i].val){
            temp[k++]=a[j++];
            rc++;
        }else{
            count[a[i].idx]+=rc;
            temp[k++]=a[i++];
        }
    }
    while(i<=mid){
        count[a[i].idx]+=rc;
        temp[k++]=a[i++];
    }
    while(j<=right){
        temp[k++]=a[j++];
    }
    for(i=0;i<n;i++){
        a[left+i]=temp[i];
    }
}
void mergeSort(Pair a[],int left,int right,int count[]){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(a,left,mid,count);
        mergeSort(a,mid+1,right,count);
        merge(a,left,mid,right,count);
    }
}
int main(){
    int n;
    printf("Enter no.of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    Pair a[n];
    int count[n];
    for(int i=0;i<n;i++){
        a[i].val=arr[i];
        a[i].idx=i;
        count[i]=0;
    }
    mergeSort(a,0,n-1,count);
    printf("Counts:");
    for(int i=0;i<n;i++){
        printf("%d ",count[i]);
    }
    return 0;
}