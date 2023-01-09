#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *ptr;
}*first=NULL;

void create(int A[],int n){
    int i;
    struct node *l,*last;
    first=calloc(1,sizeof(struct node));
    first->data=A[0];
    first->ptr=NULL;
    last=first;
    for(int i=1;i<n;i++){
        l=calloc(1,sizeof(struct node));
        l->data=A[i];
        l->ptr=NULL;
        last->ptr=l;
        last=l;
    }
}
void display(struct node *p){
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->ptr;
    }
}
int main(){
    int A[]={1,2,3,4,5};
    create(A,5);
    display(first);
    return 0;
}

