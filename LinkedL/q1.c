//singly linked list
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
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}
void delete(int n){
    struct node *temp,*pnode;
    temp=head;
    int i=1;
    while(i<n-1){
        temp=temp->next;
        i++;
    }
    pnode=temp->next;
    temp->next=pnode->next;
    pnode=NULL;
    free(pnode);
}
    // int i=1;
    // struct node* delnode;
    // temp=head;
    // while(i<n-1){
    //     temp=temp->next;
    //     i++;
    // }
    // delnode=temp->next;
    // temp->next=delnode->next;
    // delnode=NULL;
    // free(delnode);

void display(struct node *head){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }printf("\n");
}
    // while(p!=NULL){
    //     printf("%d\t",p->data);
    //     p=p->next;
    // }printf("\n");
int main(){
 
    create();
    display(head);
    create();
    create();
    create();
    delete(2);
    display(head);
    create();
    delete(2);
    display(head);
}
