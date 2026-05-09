/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/
#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b){
    return ((int*)a)[0]-((int*)b)[0];
}
int main(){
    int n;
    printf("Enter no.of intervals:");
    scanf("%d",&n);
    int a[n][2];
    printf("Enter start and end:");
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int res[n][2];
    int k=0;
    res[0][0]=a[0][0];
    res[0][1]=a[0][1];
    for(int i=1;i<n;i++){
        if(a[i][0]<=res[k][1]){
            if(a[i][1]>res[k][1]){
                res[k][1]=a[i][1];
            }
        }else{
            k++;
            res[k][0]=a[i][0];
            res[k][1]=a[i][1];
        }
    }
    printf("Merged intervals:\n");
    for(int i=0;i<=k;i++){
        printf("%d %d\n",res[i][0],res[i][1]);
    }
    return 0;
}
