//double pointer in singly linked list
//single pointer in doubly linked list

#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node* head=NULL;
struct node* temp,*tail=NULL;
void create(){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to enter:\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
}
void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }printf("\n");
}
void insertbegin(){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to enter:\n");
    scanf("%d",&newnode->data);
    newnode->next=head;
    newnode->prev=NULL;
    head->prev=newnode;
    head=newnode;
}
void insertend(){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to enter:\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=tail;
    tail->next=newnode;
    tail=newnode;
}
void insertAtpos(int n){
    int count=0,i=1;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(n>count)
        printf("Invalid POSITION\n");
    else if(n==1){
        insertbegin();
    }
    else{
       struct node* newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data to enter:\n");
        scanf("%d",&newnode->data);
        temp=head;
        while(i<n-1){
            temp=temp->next;
            i++;
        } 
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next->prev=newnode;
    }
}
int main(){
    int c,n;
    do{
        printf("Enter 1.Add 2.Display 3.Insert At beginning 4.Insert at End 5.Insert after given position 6.Delete At Begin 7.Delete from end 8.Delete from specified position 9.Reverse 10.Exit\n");
        scanf("%d",&c);
        switch(c){
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            // case 3:
            //     insertbegin();
            //     break;
            // case 4:
            //     insertend();
            //     break;
            // case 5:
            //     printf("Enter the position after which you want to insert:\n");
            //     scanf("%d",&n);
            //     insertgiven(n);
            //     break;
            // case 6:
            //     delete_begin();
            //     break;
            // case 7:
            //     delete_end();
            //     break;
            // case 8:
            //     printf("Enter the position after which you want to delete:\n");
            //     scanf("%d",&n);
            //     delete_given(n);
            //     break;
            // case 9:
            //     reverse();
            //     break;
            case 10:
                exit(0);
        }
    }while(c!=10);
}