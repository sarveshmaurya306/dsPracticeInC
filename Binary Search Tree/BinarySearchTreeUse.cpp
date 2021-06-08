#include<bits/stdc++.h>
using namespace std;
#include "BinarySearchTreeNode.h"

BinarySearchTreeNode<int> * takeInput(){
    cout << "Enter data ";
    int data;
    cin >> data;
    if(data==-1){
        return NULL;
    }
    BinarySearchTreeNode<int> *node = new BinarySearchTreeNode<int>(data);
    BinarySearchTreeNode<int> *leftnode= takeInput();
    BinarySearchTreeNode<int> *rightnode = takeInput();

    if(leftnode!=NULL && rightnode!=NULL){
        if(leftnode->data <= node->data){
            node->left = leftnode;
        } else {
            node->right = leftnode;
        }

        if(rightnode->data > node->data){
            node->right = rightnode;
        } else {
            node->left = rightnode;
        }
    } else if( leftnode==NULL && rightnode!=NULL ){
        node->left = leftnode;
        if(rightnode->data > node->data){
            node->right = rightnode;
        } else {
            node->left = rightnode;
        }
    } else if(leftnode!=NULL && rightnode==NULL){
        if(leftnode->data <= node->data){
            node->left = leftnode;
        } else {
            node->right = leftnode;
        }
        node->right = rightnode;
    } else {
        node->left = leftnode;
        node->right = rightnode;
    }

    return node;
}

//inorder
void printTreeInorder(BinarySearchTreeNode<int> * root){
    if(root==NULL)
        return;
    printTreeInorder(root->left);
    cout << root->data << " ";
    printTreeInorder(root->right);
}

void printTreeLevelWise(BinarySearchTreeNode<int> *root){
    //edge case
    if(root==NULL){
        return;
    }
    queue<BinarySearchTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BinarySearchTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << front->data << " == ";
        if(front->left!=NULL){
            pendingNodes.push(front->left);
            cout << " L " << front->left->data;
        }
        if(front->right!=NULL){
            pendingNodes.push(front->right);
            cout << " R " << front->right->data;
        }
        cout << endl;
    }
}

BinarySearchTreeNode<int> * searchNode(BinarySearchTreeNode<int> *root, int searchData){
    if(root==NULL){
        return NULL;
    }
    BinarySearchTreeNode<int> *res=NULL;
    if(searchData > root->data ){
        res= searchNode(root->right, searchData);
    } else if(searchData < root->data){
        res= searchNode(root->left, searchData);
    } else {
        res = root;
    }
    return res;
}

int main() {
    // 5 3 2 -1 -1 4 -1 -1 7 6 -1 -1 8 -1 -1
    BinarySearchTreeNode<int> *root = takeInput();
    /* 
    cout << endl;
    printTreeLevelWise(root);
    */
    /* 
    int searchData;
    cin >> searchData;
    BinarySearchTreeNode<int> *res = searchNode(root, searchData);
    if(res!=NULL){
        cout << "found";
    }else {
        cout << "Not found";
    }
     */
    //1:15
}