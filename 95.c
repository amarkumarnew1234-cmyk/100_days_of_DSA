/*Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    float data;
    struct node* next;
};
void insert(struct node** head,float value){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    if(*head==NULL||(*head)->data>=value){
        newNode->next=*head;
        *head=newNode;
    }else{
        struct node* temp=*head;
        while(temp->next&&temp->next->data<value){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
int main(){
    int n;
    printf("Enter no. of elements:");
    scanf("%d",&n);

    float a[n];
    printf("Enter elements (0 to 1):");
    for(int i=0;i<n;i++){
        scanf("%f",&a[i]);
    }
    struct node* bucket[n];
    for(int i=0;i<n;i++){
        bucket[i]=NULL;
    }
    for(int i=0;i<n;i++){
        int index=n*a[i];
        insert(&bucket[index],a[i]);
    }
    int k=0;
    for(int i=0;i<n;i++){
        struct node* temp=bucket[i];
        while(temp){
            a[k++]=temp->data;
            temp=temp->next;
        }
    }
    printf("Sorted array:");
    for(int i=0;i<n;i++){
        printf("%0.2f ",a[i]);
    }
    return 0;
}