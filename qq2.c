#include<stdio.h>
#include<stdlib.h>
#define MAX 3
typedef struct{
    int ele;
}queue;
queue q[MAX];
int IsEmpty(int *rear,int *front){
    if(*rear==*front)
        return 1;
    return 0;
}
int IsFull(int *rear,int *front){
    if(*front==(*rear+1)%MAX)
        return 1;
    return 0;
}
void enqueue(int *rear,int *front,int data){
    if(IsFull(rear,front))
        printf("Queue is full\n");
    else{
        *rear=(*rear+1)%MAX;
        q[*rear].ele=data;
    }
}
void dequeue(int *rear,int *front){
    if(IsEmpty(rear,front))
        printf("Queue is empty\n");
    else{
        *front=(*front+1)%MAX;
        int k=q[*front].ele;
        printf("Popped element is: %d\n",k);
    }
}
void display(int *rear,int *front){
    if(*rear>*front){
        for(int i=*front+1;i<=*rear;i++)
            printf("%d ",q[i].ele);
    }
    else{
        int i=*front+1;
            while(i<MAX)
            {
            printf("%d ",q[i].ele);
                i++;}
                      i=0;
                      while(i<=*rear)
                      {
                        printf("%d ",q[i].ele);
                        i++;}

    }

}
int main(){
    int data,ch,front=0,rear=0;
    do{
        printf("Enter 1.Enter 2.Remove 3.Display 4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter data to be added:\n");
            scanf("%d",&data); 
            enqueue(&rear,&front,data);
            break;
            case 2:
            dequeue(&rear,&front);
            break;
            case 3:
            display(&rear,&front);
            break;
            case 4:
            exit(0);   
        }
    }while(ch!=4);
}