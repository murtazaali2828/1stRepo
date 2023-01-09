#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct{
    int data;
}queue;
queue Q[MAX];
int isFull(int *rear){
    if(*rear==MAX-1)
        return 1;
    return 0;
}
int isEmpty(int *rear,int *front){
    if(*rear==*front)
        return 1;
    return 0;
}
void addq(int d,int *rear){
    if(isFull(rear))
        printf("Queue is full");
    else{
        *rear=*rear+1;
        Q[*rear].data=d;
    }
}
void deleteq(int *rear,int*front){
    if(isEmpty(rear,front))
    printf("Queue is empty\n");
    else{
        *front=*front+1;
        int d=Q[*front].data;
        printf("Deleted element is %d\n",d);
    }
}
void display(int *rear,int *front){
    for(int i=*front+1;i<=*rear;i++)
    printf("%d\t",Q[i].data);
    printf("\n");
}
int main(){
    int d,ch;
    int front=-1,rear=-1;
    do{
        printf("Enter 1.Enter data 2.Remove data 3.Display 4.Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter data to be entered:\n");
            scanf("%d",&d);
            addq(d,&rear);
            break;
        case 2:
            deleteq(&rear,&front);
            break;
        case 3:
            display(&rear,&front);
            break;
        case 4:
            exit(0);
        }
    }while(ch!=4);
}