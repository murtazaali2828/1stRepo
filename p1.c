#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node *head=NULL;
void create(int x){
    struct node* newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newnode;
    }
    newnode->next=head;
}
void delete(int x){
    struct node* temp,*pnode;
    int i=0;
    while(i<x){
        pnode=temp;
        temp=temp->next;
        i++;
    }
    pnode->next=temp->next;
    free(temp);
}
void display(){
    struct node* temp;
    temp=head;
    while(temp->next!=head){
        printf("%d\t",temp->data);
        temp=temp->next;
    }printf("%d\n",temp->data);
    printf("\n");
}
int main(){
    int ch;
    printf("1.Insert 2.Delete 3.Display 4.Exit\n");
    create(4); 
    create(48);
    create(12);
    create(77);
    delete(3);
    display();     
}
