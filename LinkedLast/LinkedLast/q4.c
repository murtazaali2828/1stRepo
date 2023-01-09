#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *temp;
void create(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to be added:\n");
    scanf("%d",&newnode->data);
    if(head==NULL){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
void insertbegin(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted :\n");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}
void insertend(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted :\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
}
void display(struct node *p){
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }printf("\n");
}
void insertgiven(int n){
    int count=0,i=1;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(n>count){
        printf("Invalid position\n");
    }
    else{
        temp=head;
        while(i!=n){
            temp=temp->next;
            i++;
        }
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data to be inserted :\n");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
int main(){
    int c,n;
    do{
        printf("Enter 1.Add 2.Display 3.Insert At beginning 4.Insert at End 5.Insert after given position 6.Exit\n");
        scanf("%d",&c);
        switch(c){
            case 1:
                create();
                break;
            case 2:
                display(head);
                break;
            case 3:
                insertbegin();
                break;
            case 4:
                insertend();
                break;
            case 5:
                printf("Enter the position after which you want to insert:\n");
                scanf("%d",&n);
                insertgiven(n);
                break;
            case 6:
                exit(0);
        }
    }while(c!=6);
}
