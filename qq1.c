#include<stdio.h>
#include<stdlib.h>
#define MAX 8
typedef struct{
    int ele;
}queue;
queue q[MAX];
int IsEmpty(int *rear,int *front){
    if(*rear==*front)
        return 1;
    return 0;
}
int IsFull(int *rear){
    if(*rear==MAX-1)
        return 1;
    return 0;
}
void enqueue(int data,int* rear){
    if(IsFull(rear))
        printf("Queue is full\n");
    else{
        *rear=*rear+1;
        q[*rear].ele=data;
    }
}
void dequeue(int *front,int *rear){
    if(IsEmpty(rear,front))
        printf("Queue is full\n");
    else{
        *front=*front+1;
        int k=q[*front].ele;
        printf("Popped element is %d\n",k);
    }
}
void display(int *front,int *rear){
    for(int i=*front+1;i<=*rear;i++){
        printf("%d\t",q[i].ele);
    }printf("\n");
}
int main(){
    int data,ch,front=-1,rear=-1;
    do{
        printf("Enter 1.Enter 2.Remove 3.Display 4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter data to be added:\n");
            scanf("%d",&data); 
            enqueue(data,&rear);
            break;
            case 2:
            dequeue(&front,&rear);
            break;
            case 3:
            display(&front,&rear);
            break;
            case 4:
            exit(0);   
        }
    }while(ch!=4);
}