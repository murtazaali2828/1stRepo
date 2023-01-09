#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* pre;
    int data;
    struct node* next;
};
struct node *temp,*head=NULL;
void create(int n){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    newnode->pre=NULL;
    if(head==NULL){
        newnode->next=newnode;
        newnode->pre=newnode;
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->pre=temp;
        newnode->next=head;
    }
}
void display(){
    temp=head;
    while(temp->next!=head){
        printf("%d\t",temp->data);
        temp=temp->next;
    }printf("%d\n",temp->data);
}
int main(){
    int ch,data,exp;
    do{
        printf("Enter 1.Enter value 2.Display 3.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter data :\n");
            scanf("%d",&data);
            create(data);
            break;
            case 2:
                display();         
                break;
            case 3:
                exit(0);
                break;
        }
    }while(ch!=4);
    return 0;
}