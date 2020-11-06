#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;
};

typedef struct Node node;
node *head=NULL;

void show();
void insertAtBeginning(int);
void insertAtLast(int);
void insertAt(int, int);
void deleteAt(int);
void reverse();

void main(){
	while(1){
		int choose=0;
		printf("Choose one-->\n1)insert at last\n2)insert at beginning\n3)inset at position\n4)delete at position\n5)reverse\n6)show\n7)exit\n");
		scanf("%d",&choose);
		switch(choose){
			case 1: {
				printf("Enter the data\n");
				int data;
				scanf("%d",&data);
				insertAtLast(data);
				show();
				break;
			}
			case 2:{
				printf("Enter the data\n");
				int data;
				scanf("%d",&data);
				insertAtBeginning(data);
				show();
				break;
			}
			case 3:{
				printf("Enter the data\n");
				int data;
				scanf("%d",&data);
				printf("Provide the position\n");
				int pos;
				scanf("%d",&pos);
				insertAt(data, pos);
				show();
				break;
			}
			case 4:{
				printf("Provide the position\n");
				int pos;
				scanf("%d",&pos);
				deleteAt(pos);
				show();
				break;
			}
			case 5:{
				reverse();
				show();
				break;
			}
			case 6: show();
			break;
			default:exit(1);
		}
	}
}

int lengthNode(node *headx){
	int i=1;
	while(headx!=NULL){
		headx=headx->next;
		i++;
	}
	return i;
}

void reverse(){
	node *current=head;
	node *pre= NULL;
	while(current!=NULL){
		node *tempx=current;
		current=current->next;
		tempx->next=pre;
		pre=tempx;
	}
	head=pre;
}



void deleteAt(int position){
	
	if(head==NULL){
		printf("No element is linked list.\n");
		return;
	}
	if(position > lengthNode(head)-1 || position<= 0){
		printf("Please enter currect position");
		return;
	}
	
	if(position==1){
		node *tofree= head;
		head=head->next;
		free(tofree);
		return;
	}
	
	node *temp= head;
	int i=0;
	
	for(i=0;i<position-2;i++){
		temp=temp->next;
	} //stopped just before deleting node.
	node *tofree= temp->next;
	
	temp->next= temp->next->next;
	
	free(tofree);	
}



void insertAt(int data, int position){
	node *temp1= (node *)malloc(sizeof(node));
	if(position<=0 || position > lengthNode(head)){
		printf("please enter correct position.\n");
		return;
	}
	temp1->data= data;
	temp1->next= NULL;
	
	if(position==1){
		temp1->next=head;
		head=temp1;
		return;
	}
	int i=0;
	node *temp= head;
	for(i=0;i<position-2;i++){
		temp=temp->next;
	}
	temp1->next= temp->next;
	temp->next= temp1;
}



void insertAtBeginning(int data){
	node *temp= (node *)malloc(sizeof(node));
	temp->data=data;
	temp->next=head;
	head=temp;	
}



void insertAtLast(int data){
	node *temp= (node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
	}
	else{
		node *xtemp=head;
		while(xtemp->next!=NULL){
			xtemp=xtemp->next;
		}
		xtemp->next=temp;
	}
}



void show(){
	
	node *temp=head;
	printf("List is\t");
	if(temp==NULL){
		printf("empty...");
	}
	else {	
		while(temp!=NULL){
			printf("%d ", temp->data);
			temp=temp->next;
		}
	}
	printf("\n");
}

