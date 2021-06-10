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

bool isBST3(BinarySearchTreeNode<int> * root, int min=INT_MIN, int max=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    bool isleftok = isBST3(root->left, min, root->data-1);
    bool isrightok = isBST3(root->right, root->data-1, max);
    return isleftok && isrightok;
}

BinarySearchTreeNode<int> * makeBSTFromArray(int arr[], int si , int ei){
    if(si>ei){
        return NULL;
    }
    int mid = (si + ei) / 2;
    BinarySearchTreeNode<int> *root=new BinarySearchTreeNode<int>(arr[mid]);
    root->left = makeBSTFromArray(arr, si, mid - 1);
    root->right = makeBSTFromArray(arr, mid + 1, ei);
    return root;
}


vector<int> ll;
void BSTtoSortedVector(BinarySearchTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    BSTtoSortedVector(root->left);
    ll.push_back(root->data);
    BSTtoSortedVector(root->right);
}

vector<int>* getRootToNodePath(BinarySearchTreeNode<int> *root, int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    if(leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if(rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }
}

int main() {
    // 5 3 2 -1 -1 4 -1 -1 7 6 -1 -1 8 -1 -1
    // BinarySearchTreeNode<int> *root = takeInput();
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

    /* 
    cout << endl;
    // 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1
    printTreeLevelWise(root);
    cout << endl;
    IsBSTReturn opt = isBST2(root);
    cout << opt.isBST << endl; 
    */

    // cout<<isBST3(root);

    //make bst of a sorted numbers
     

    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    BinarySearchTreeNode<int> *root = makeBSTFromArray(arr, 0, 6);
    // printTreeLevelWise(root);
    
    // BSTtoSortedVector(root);
    // for(int x: ll){
    //     cout << x << " ";
    // }

    vector<int> *path=getRootToNodePath(root, 7);
    for (int i = 0; i < path->size();i++){
        cout << path->at(i) << endl;
    }

    //2,47
    delete root;
}