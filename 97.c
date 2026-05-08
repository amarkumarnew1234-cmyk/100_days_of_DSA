/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/
#include<stdio.h>
#include<stdlib.h>
int cmpStart(const void* a,const void* b){
    return ((int*)a)[0]-((int*)b)[0];
}
void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}
void heapifyUp(int heap[],int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]<=heap[i]) break;
        swap(&heap[p],&heap[i]);
        i=p;
    }
}
void heapifyDown(int heap[],int size,int i){
    while(1){
        int l=2*i+1,r=2*i+2,small=i;
        if(l<size&&heap[l]<heap[small]) small=l;
        if(r<size&&heap[r]<heap[small]) small=r;
        if(small==i) break;
        swap(&heap[i],&heap[small]);
        i=small;
    }
}
int main(){
    int n;
    printf("Enter no. of meetings:");
    scanf("%d",&n);
    int a[n][2];
    printf("Enter start and end time:");
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    qsort(a,n,sizeof(a[0]),cmpStart);
    int heap[n];
    int size=0;
    heap[size++]=a[0][1];
    for(int i=1;i<n;i++){
        if(a[i][0]>=heap[0]){
            heap[0]=a[i][1];
            heapifyDown(heap,size,0);
        }else{
            heap[size]=a[i][1];
            heapifyUp(heap,size);
            size++;
        }
    }
    printf("Minimum rooms:%d",size);
    return 0;
}