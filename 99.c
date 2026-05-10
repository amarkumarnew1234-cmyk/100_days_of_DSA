/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target. */
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int pos;
    int speed;
}Car;
int cmp(const void* a,const void* b){
    return ((Car*)b)->pos-((Car*)a)->pos;
}
int main(){
    int n,target;
    printf("Enter no.of cars:");
    scanf("%d",&n);
    Car a[n];
    printf("Enter positions:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].pos);
    }
    printf("Enter speeds:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].speed);
    }
    printf("Enter target:");
    scanf("%d",&target);
    qsort(a,n,sizeof(a[0]),cmp);
    double lastTime=0;
    int fleets=0;
    for(int i=0;i<n;i++){
        double time=(double)(target-a[i].pos)/a[i].speed;
        if(time>lastTime){
            fleets++;
            lastTime=time;
        }
    }
    printf("Car fleets:%d",fleets);
    return 0;
}