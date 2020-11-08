#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int arr[MAX];
int front=-1;
int rear=-1;

void enqueue(int);
int dequeue();
int peek();
int isEmpty();
void display();

void main(){
		while(1){
		printf("Choose one...\n1)enqueue\n2)dequeue\n3)peek\n4)display\n5)exit\n");
		int choose;
		scanf("%d",&choose);
		switch(choose){
			case 1:{
				printf("Enter data...\n");
				int data;
				scanf("%d",&data);
				enqueue(data);
				break;
			}
			case 2:{
				printf("removed element is == %d\n",dequeue());
				break;
			}
			case 3:{
				printf("top element is == %d\n", peek());
				break;
			}
			case 4: display();
			break;
			default: exit(1);
		}
		printf("\n\n");
	}
}

void display(){
	if(isEmpty()==1)
	return;
	
	printf("queue is == ");
	int i=0;
	for(i=front;i<=rear;i++)
	printf("%d ",arr[i]);
	
	printf("\n");
}

int peek(){
	if(isEmpty()==1)
	return -1;
	
	return arr[front];
}

int dequeue(){
	int toreturn;
	if(isEmpty()==1){
		return -1;
	}
	else if(front == rear){
		toreturn = front;
		front=rear=-1;
	}
	else {
		toreturn = front;
		front =(front+1)%MAX;
	}
	return arr[toreturn];
}

void enqueue(int data){
	if(isEmpty()==1){
		rear++;
		front++;
	}
	else if((rear+1)%MAX == front){
		printf("queue is full...\n");
		return;
	}
	else{
		rear=(rear+1)%MAX;
	}
	arr[rear]=data;
}

int isEmpty(){
	if(front == -1 && rear==-1)
	return 1;
	
	return 0;
}
