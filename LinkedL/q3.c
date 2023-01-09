//doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* pre;
};
struct node *head=NULL;
struct node *tail=NULL;
void create(){
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to be entered:\n");
    scanf("%d",&newnode->data);
    newnode->next=newnode->pre=NULL;
    if(head==NULL)
        tail=head=newnode;
    else{
            tail->next=newnode;
            newnode->pre=tail;
            tail=newnode;
    }
}
void delete(int n){
    int i=1;
    struct node *temp;
    temp=head;
    while(i<n){
        temp=temp->next;
        i++;}
    temp->next->pre=temp->pre;
    temp->pre->next=temp->next;
    free(temp);
}
void display(){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }printf("\n");
}
int main(){
 
    create();
    display();
    create();
    create();
    create();
    delete(2);
    display();
    create();
    delete(2);
    display();
}