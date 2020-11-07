#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int top=-1;

int Stack[MAX];

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
			case 1: {
				printf("Enter data...\n");
				int data;
				scanf("%d",&data);
				push(data);
				break;
			}
			case 2:{
				printf("removed element is === %d\n",pop());
				break;
			}
			case 3:{
				printf("top element is === %d\n",peek());
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

void display(){
	if(top==-1){
		printf("no Element !!!\n");
		return;
	}
	int x=top;
	printf("elements are == ");
	while(x>=0){
		printf("%d ", Stack[x]);
		x--;
	}
	printf("\n");
}

int peek(){
	return Stack[top];
}

int pop(){
	if(top==-1)
	return -1;
	
	return Stack[top--];
}

void push(int data){
	if(top>=MAX){
		printf("Overflow!!!\n");
		return;
	}
	top++;
	Stack[top]=data;
}
