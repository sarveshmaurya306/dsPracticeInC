#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"

void printTree(BinaryTreeNode<int> * root){
    //base case;
    if(root==NULL)
        return;
    cout << root->data << " ==> ";
    if(root->left!=NULL){
        cout << " L: " << root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout << " R: " << root->right->data<<" ";
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int> * takeInput(){
    int rootData;
    cout << "Enter data ";
    cin >> rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftchild = takeInput();
    BinaryTreeNode<int> *rightchild = takeInput();
    root->left = leftchild;
    root->right = rightchild;
    return root;
}

BinaryTreeNode<int> * takeInputLevelWise(){
    int rootData;
    cout << "Enter root data ";
    cin >> rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << endl;
        int leftchilddata;
        cin >> leftchilddata;
        if(leftchilddata!=-1){
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftchilddata);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightchilddata;
        cin >> rightchilddata;
        if(rightchilddata!=-1){
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightchilddata);
            front->right = child;
            pendingNodes.push(child);
        }

    }
    return root;
}

void printTreeLevelWise(BinaryTreeNode<int> *root){
    //edge case
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BinaryTreeNode<int> *front = pendingNodes.front();
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

int countNodes(BinaryTreeNode<int> * root){
    //base case
    if(root==NULL){
        return 0;
    }
    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);
    return leftNodes + rightNodes + 1;
}

void inorder(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int height(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameterOfTree(BinaryTreeNode<int> * root){
    if(root==NULL){
        return 0;
    }

    int option1 = height(root->left)+ height(root->right);
    int option2 = diameterOfTree(root->left);
    int option3 = diameterOfTree(root->right);
    return max(option1, max(option2, option3));
} // O(n* h)

//better approach for diameter
pair<int, int> heightDiameter(BinaryTreeNode<int> * root){
    if(root==NULL){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
} //O(N)

int main(){
    //! 2
    /* 
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2; 
    */

    /*
    // 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 -1
    // BinaryTreeNode<int> *root = takeInput();
    */

    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
    // 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeInputLevelWise();
    // printTree(root); 
    // printTreeLevelWise(root);
    // cout << "total nodes: " << countNodes(root);
    // inorder(root);
    cout << "diameter " << diameterOfTree(root) << endl;
    cout << "Height" << heightDiameter(root).first<<endl;
    cout << "Diameter" << heightDiameter(root).second;
    
    delete (root);
    // printTree(root);
}