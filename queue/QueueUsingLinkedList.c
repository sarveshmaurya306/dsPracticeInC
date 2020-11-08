#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};
typedef struct Node node;
node *front=NULL;
node *rear=NULL;

void enqueue(int);
int dequeue();
int peek();
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
	node * temp= front;
	printf("value are == ");
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int peek(){
	if(front==NULL)
	return -1;
	
	return front->data;
}

int dequeue(){
	if(front==NULL){
		return -1;
	}
	node *tofree= front;
	int toreturn =tofree->data;
	
	if(front == rear){
		front = NULL;
		rear=NULL;
		free(tofree);
		return toreturn; 
	}
	front = front->next;
	free(tofree);
	return toreturn;
}

void enqueue(int data){
	node *temp= (node *)malloc(sizeof(node));
	temp->data= data;
	temp->next=NULL;
	if(front == NULL && rear==NULL){
		rear=temp;
		front = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}
