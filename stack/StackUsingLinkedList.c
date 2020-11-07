#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Stack *next;
};

typedef struct Node node;

node *top=NULL;

void push(int);
int pop();
int peek();
void display();

void main(){
	while(1){
		printf("Choose one...\n1)push\n2)pop\n3)peek\n4)display\n5)exit\n");
		int choose;
		scanf("%d",&choose);
		switch(choose){
			case 1:{
				printf("Enter data...\n");
				int data;
				scanf("%d",&data);
				push(data);
				break;
			}
			case 2:{
				printf("removed element is == %d\n",pop());
				break;
			}
			case 3:{
				printf("top element is == %d\n", peek());
				break;
			}
			case 4:{
				display();
				break;
			}
			default: exit(1);
		}
		printf("\n\n");
	}
}

void push(int data){
	node *temp= (node *)malloc(sizeof(node));
	temp->data=data;
	if(top==NULL){
		temp->next=NULL;
		
		top=temp;
		return;
	}
	temp->next=top;
	top=temp;
}

int pop(){
	if(top==NULL)
	return -1;
	
	node *tofree= top;
	int toreturn =tofree->data;
	top=top->next;
	free(tofree);
	return toreturn;
}

int peek(){
	if(top==NULL)
	return -1;
	
	return top->data;
}

void display(){
	node *temp= top;
	if(temp==NULL){
		printf("No element\n");
		return;
	}
	printf("elements are == ");
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp=temp->next;
	}
	printf("\n");
}
