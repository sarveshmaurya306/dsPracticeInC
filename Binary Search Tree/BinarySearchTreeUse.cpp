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


class IsBSTReturn{
    public:
        bool isBST;
        int minimum;
        int maximum;
};

IsBSTReturn isBST2(BinarySearchTreeNode<int> * root){
    if(root==NULL){
        IsBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    IsBSTReturn leftoutput = isBST2(root->left);
    IsBSTReturn rightoutput = isBST2(root->right);
    int minimum = min(root->data, min(leftoutput.minimum, rightoutput.minimum));
    int maximum = max(root->data, max(leftoutput.maximum, rightoutput.maximum));

    bool isBSTFinal = (root->data > leftoutput.maximum) && (root->data <= rightoutput.minimum) && leftoutput.isBST && rightoutput.isBST;

    IsBSTReturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = isBSTFinal;

    return output;
    //O(N)
}

/* 
int
maximum(BinarySearchTreeNode<int> *root)
{
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinarySearchTreeNode<int> * root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinarySearchTreeNode<int> * root){
    if(root==NULL){
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->left);

    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}
 */
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
    cout << endl;
    // 4 2 1 -1 -1 13 -1 -1 6 5 -1 -1 7 -1 -1
    printTreeLevelWise(root);
    cout << endl;
    IsBSTReturn opt = isBST2(root);
    cout << opt.isBST << endl;
}