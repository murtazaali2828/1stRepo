//print fibonacci using linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct linknode *list_ptr;
struct linknode{
    int number;
    int next_number;
    list_ptr link;
};
typedef struct linknode ln;

void createfibo(ln *head,int num){
    ln *node,*temp;
    head->link=NULL;
    head->number = 0;
    head->next_number = 1;
    temp = head;
    for(int i =1;i<num;i++){
        node=(ln*)malloc(1*sizeof(ln));
        node->number = temp->next_number;
        node->next_number = temp->number + temp->next_number;
        temp->link = node;
        node->link = NULL;
        temp = node;
    }
}
void display(ln *head,int num){
    ln *temp = head;
    for(int i =0;i<num;i++){
        printf("%d\n",temp->number);
        temp = temp->link;
    }
}
int main(){
    ln *head = NULL;
    int num;
    printf("Enter number of fibonacci numbers to print: ");
    scanf("%d",&num);
    head=(ln*)malloc(sizeof(ln));
    createfibo(head,num);
    display(head,num);
}