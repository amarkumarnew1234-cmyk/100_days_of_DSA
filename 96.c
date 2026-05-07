/*Problem: Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j].*/
#include<stdio.h>
long long merge(int a[],int temp[],int left,int mid,int right){
    int i=left,j=mid,k=left;
    long long inv=0;
    while(i<=mid-1&&j<=right){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }else{
            temp[k++]=a[j++];
            inv+=mid-i;
        }
    }
    while(i<=mid-1){
        temp[k++]=a[i++];
    }
    while(j<=right){
        temp[k++]=a[j++];
    }
    for(i=left;i<=right;i++){
        a[i]=temp[i];
    }
    return inv;
}
long long mergeSort(int a[],int temp[],int left,int right){
    long long inv=0;
    if(right>left){
        int mid=(left+right)/2;
        inv+=mergeSort(a,temp,left,mid);
        inv+=mergeSort(a,temp,mid+1,right);
        inv+=merge(a,temp,left,mid+1,right);
    }
    return inv;
}
int main(){
    int n;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    int a[n],temp[n];
    printf("Enter elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    long long inv=mergeSort(a,temp,0,n-1);
    printf("Inversions:%lld",inv);
    return 0;
}