#include<bits/stdc++.h>
using namespace std;
#include "TreeNode.h"

void inorder(Node<int>* root){
	if(root==nullptr) return ;
	cout<<root->val<<" ";
	inorder(root->left);
	inorder(root->right);
}

void levelOrder(Node<int>* root){
	if(root==nullptr) return;
	queue<Node<int>* > q;
	q.push(root);
	while(!q.empty()){
		Node<int>* currentNode= q.front();
		q.pop();
		cout<<currentNode->val<<" ";
		if(currentNode->left!=nullptr) q.push(currentNode->left);
		if(currentNode->right!=nullptr) q.push(currentNode->right);
	}
}

int main() {
	Node<int> * root= new Node<int>(1);
	root->left= new Node<int>(2);
	root->right=new Node<int>(3);
	root->left->left=new Node<int>(5);
	
	inorder(root);
	cout <<endl;
	levelOrder(root);
	cout<<endl;
}