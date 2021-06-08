#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node node;
node *root=NULL;

node * insert(node *, int);
int search(node *, int);  //return -1 or 1; 1 for present, -1 for absent
node * inorderDisplay(node *);

void main(){
	while(1){
		printf("Choose one...\n");
		printf("1) insert in bst.\n");
		printf("2) search in bst.\n");
		printf("3) show in increasing order.\n");
		printf("4) exit.\n");
		int choose;
		scanf("%d",&choose);
		switch(choose){
			case 1:{
				printf("Enter data.\n");
				int data;
				scanf("%d",&data);
				root= insert(root, data);
				break;
			}
			case 2:{
				printf("Enter the key.\n");
				int key;
				scanf("%d",&key);
				int isfound= search(root, key);
				if(isfound==1)
					printf("Element found...\n");
				else 
					printf("Element not found...\n");
				break;
			}
			case 3:{
				printf("Element are ::  ");
				inorderDisplay(root);
				break;
			}
			default: exit(1);
		}
		printf("\n\n");
	}
}

node * inorderDisplay(node *root){
	if(root ==NULL){
		return root;
	}
	else {
		//inorder traversal;
		inorderDisplay(root->left);
		printf("%d ", root->data);
		inorderDisplay(root->right);
	}
	return root;
}

node * createNewNode(int data){
	node* temp= (node *)malloc(sizeof(node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node * insert(node * root, int data){
	if(root==NULL){
		root= createNewNode(data);
	}
	else{
		if(data < root->data){
			//means go to left ;
			root->left=insert(root->left, data);
		}
		else if(data > root->data){
			//means go to right;
			root->right= insert(root->right, data);
		}
	}
	return root;
}

int search(node *root, int key){
	node * temp= root;
	if(root==NULL){
		return -1;
	}
	if(root->data == key){
		return 1;
	}
	else if(key < root->data){
		// goto left;
		search(root->left, key);
	}
	else if(key > root->data){
		//goto right;
		search(root->right, key);
	}
	else 
	return -1;	
}
