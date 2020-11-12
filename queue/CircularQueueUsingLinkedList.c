#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};
typedef struct Node node;

/*
basic rule of queue and stack is insertion and deletion must have O(1) complexity;
that's why taking two pointer: front and back for head and end respectively.
we will use front for deletion and back for insertion. 
taking this because it takes O(1) to delete from front and O(1) to insert at last;
*/

node *front= NULL;
node *back= NULL;

void enqueue(int);
int dequeue();
void display();

void main(){
	while(1){
		printf("Choose one ...\n");
		printf("1) enqueue\n");
		printf("2) dequeue\n");
		printf("3) display queue\n");
		printf("4) exit\n");
		int choice;
		scanf("%d", &choice);
		
		switch(choice){
			case 1:{
				printf("enter data...\n");
				int data;
				scanf("%d",&data);
				enqueue(data);
				break;
			}
			case 2:{
				printf("deleted element is : %d \n", dequeue());
				break;
			}
			case 3: display();
			break;
			default: exit(1);
		}
		printf("\n\n\n");
	}
}
void display(){
	if(front==NULL)
	printf("no element...\n");
	else{
		node *temp= (node *)malloc(sizeof(node));
		temp=front;
		printf("data is : ");
		while(1){
			printf("%d ",temp->data);
			temp=temp->next;
			if(temp==front){
				break;
			}
		}
		printf("\n");
	}
}

void enqueue(int data){
	node *temp= (node *)malloc(sizeof(node));
	temp->data= data;
	if(front==NULL || back==NULL){
		temp->next= temp;
		//above pointer which stores location of itself. coz circular in single element.
		front = temp;
		back= temp;
	}
	else{
		back->next= temp;
		back=temp;
		back->next= front;
	}
}

int dequeue(){
	int toreturn=-1;
	node * temp= (node *)malloc(sizeof(node));
	if(front == NULL || back== NULL){
		printf("no element is there !!!\n");
	}
	else if(front==back){
		temp= front;
		front =NULL;
		back=NULL;
		toreturn = temp->data;
		free(temp);
	}
	else{
		temp=front;
		front= front->next;
		toreturn = temp->data;
		free(temp);
		back->next=front;	
	}
	return toreturn;
}
