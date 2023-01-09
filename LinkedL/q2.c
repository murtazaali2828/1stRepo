//singly-circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node *head=NULL;
void create(){
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to be entered:\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
        temp=head=newnode;
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    newnode->next=head;
}
void delete(int n){
    int i;
    struct node *dnode,*temp=head;
    while(i<n-1){
        temp=temp->next;
    }
    dnode=temp->next;
    temp->next=dnode->next;
    free(dnode);
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