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
//same code for height as well
int maxDepth(Node<int> * root){
	if(root==nullptr) return 0;
	int leftDepth= maxDepth(root->left);
	int rightDepth= maxDepth(root->right);
	return max(leftDepth, rightDepth)+1;
}

int isBalanced(Node<int>* root){
	if(root==nullptr) return 0;
	int leftDepth= maxDepth(root->left);
	int rightDepth= maxDepth(root->right);
	
	if(leftDepth==-1 || rightDepth==-1) return -1;
	if(abs(leftDepth-rightDepth)>1) return -1;
	
	return max(leftDepth, rightDepth)+1;
}

//diameter of a tree start here
int height(Node<int> * root, int &res){
	if(root==NULL)
		return 0;
	
	int lh= height(root->left, res);
	int rh= height(root->right, res);
	res=max(res, lh+rh);
	return 1+max(lh, rh);
}
int diameterOfBinaryTree(Node<int>* root) {
	int res= INT_MIN;
	height(root, res);
	return res;
}
//diameter of a tree ends here

//L-18
int maxPathSum(Node<int> * root){
	if(root==nullptr)	return 0;
	int leftSum = maxPathSum(root->left);
	int rightSum = maxPathSum(root->right);
	return root->val+ max(leftSum, rightSum);
}

//l-19 check two trees are equal or not
//just do any traversal ie., inorder/preorder/postorder

int main() {
	Node<int> * root= new Node<int>(9);
	root->left= new Node<int>(2);
	root->right=new Node<int>(3);
	root->right->left=new Node<int>(4);
	root->right->right=new Node<int>(6);
	root->right->left->left=new Node<int>(5);
	/*	
		inorder(root);
		cout <<endl;
		levelOrder(root);
		cout<<endl;
	
		cout<<maxDepth(root)<<endl;
		isBalanced(root)!=-1?cout<<"Balanced\n":cout<<"Not Balanced\n";
		cout<<diameterOfBinaryTree(root)<<endl;
	*/
}