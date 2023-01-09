#include<stdlib.h>
#include <stdio.h>
struct node{
    int data;
    int exp;
    struct node* next;
};
struct node* head=NULL;
void create(int d, int e){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->exp=e;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else{
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
    newnode->next=head;
}
void compare(){
    struct node* current=head,*nnode=NULL;
    int t;
    while(current->next!=head){
        nnode=current->next;
        while(nnode!=head){
            if(current->exp<nnode->exp){
                t=current->data;
                current->data=nnode->data;
                nnode->data=t;
                t=current->exp;
                current->exp=nnode->exp;
                nnode->exp=t;
            }
            nnode=nnode->next;
        }
        current=current->next;
    }
    display();
}
int main(){
    int ch,data,exp;
    do{
        printf("Enter 1.Enter value 2.Display 3.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter data and exponent :\n");
            scanf("%d%d",&data,&exp);
            create(data,exp);
            break;
            case 2:
                compare();
                break;
            case 3:
                exit(0);
                break;
        }
    }while(ch!=4);
    return 0;
}


