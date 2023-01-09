#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *head=NULL,*temp;
void create(){
struct node *newnode;
newnode=(struct node *)malloc(sizeof(struct node));
printf("Enter data to be entered");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head==NULL)
	head=newnode;
else{
temp=head;
while(temp->next!=NULL){
temp=temp->next;}
temp->next=newnode;}}
void display(){
temp=head;
while(temp!=NULL){
printf("%d\n",temp->data);
temp=temp->next;
}}
int main(){
int c;
do{
printf("1.Create 2.Display");
scanf("%d",&c);
switch(c){
	case(1):create();break;
	case(2):display();break;
	default:exit(0);
}}while(c!=4);
}
