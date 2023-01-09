#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *temp,*head=NULL;
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
void delete_begin(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
    }
}
void delete_end(){
    struct node *pnode;
    temp=head;
    while(temp->next!=NULL){
        pnode=temp;
        temp=temp->next;
    }
    if(temp==head){
        head=NULL;
    }
    else{
        pnode->next=NULL;
    }
    free(temp);
}
void delete_given(int n){
    int i=1;
    struct node* delnode;
    temp=head;
    while(i<n-1){
        temp=temp->next;
        i++;
    }
    delnode=temp->next;
    temp->next=delnode->next;
    delnode=NULL;
    free(delnode);
}
void reverse(){
    struct node *pnode,*cnode,*nnode;
    pnode=NULL;
    cnode=nnode=head;
    while(nnode!=NULL){
        nnode=nnode->next;
        cnode->next=pnode;
        pnode=cnode;
        cnode=nnode;
    }
    head=pnode;
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
                delete_begin();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                printf("Enter the position after which you want to delete:\n");
                scanf("%d",&n);
                delete_given(n);
                break;
            case 9:
                reverse();
                break;
            case 10:
                exit(0);
        }
    }while(c!=10);
}
