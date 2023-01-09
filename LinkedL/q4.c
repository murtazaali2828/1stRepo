//doubly-circular linked list
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
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to be entered:\n");
    scanf("%d",&newnode->data);
    newnode->next=newnode->pre=NULL;
    if(head==NULL)
        tail=head=newnode;
    else{
        newnode->pre=tail;
        tail->next=newnode;
        tail=newnode;
    }
    tail->next=head;
}
void delete(int n){
    int i=1;
    struct node *temp;
    temp=head;
    while(i<n){
        temp=temp->next;
        i++;
    }
    temp->next->pre=temp->pre;
    temp->pre->next=temp->next;
    free(temp);
}
void display(){
    struct node *temp=head;
    while(temp->next!=head){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
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
