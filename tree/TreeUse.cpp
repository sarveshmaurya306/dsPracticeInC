#include<bits/stdc++.h>
using namespace std;
#include "TreeNode.h"

TreeNode<int> * takeInputLevelWise(){
    int rootData;
    cout << "Enter root data ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild;i++){
            int childDAta;
            cout << "Enter " << i << " th child of " << front->data << endl;
            cin >> childDAta;
            TreeNode<int> *child=new TreeNode<int>(childDAta);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void levelWisePrint(TreeNode<int>* root){
    //corner case not for recursion
    if(root==NULL){
        return;
    }
    queue<TreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << " : ";
        for (int i = 0; i < front->children.size();i++){
            cout<<front->children[i]->data<<" ";
            q.push(front->children[i]);
        }
        cout << endl;
    }
}

TreeNode<int> * takeInput(){
    int rootData;
    cout << "Enter data ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter number of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n;i++){
        TreeNode<int> * child= takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> * root){
    //edge case not a base case
    if(root==NULL){
        return;
    }
    cout << root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout << root->children[i]->data << "    ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size();i++){
        printTree(root->children[i]);
    }
}

int countNodes(TreeNode<int> * root){
    if(root==NULL){
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < root->children.size();i++){
        ans += countNodes(root->children[i]);
    }
    return ans;
}

int countHeight(TreeNode<int> * root){
    if(root==NULL){
        return 0;
    }
    int height = 0;
    for (int i = 0; i < root->children.size();i++){
        height=max(countHeight(root->children[i]), height);
    }
    return height+1;
}

void printAtLevelK(TreeNode<int> * root, int k){
    //edge case
    if(root==NULL){
        return;
    }
    //base case
    if(k==0){
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size();i++){
        printAtLevelK(root->children[i], k - 1);
    }
}

int countLeafNodes(TreeNode<int> * root){
    //edge case
    if(root==NULL){
        return 0;
    }
    int count = 0;
    //base case
    if(root->children.empty()){
        count++;
    }
    for (int i = 0; i < root->children.size();i++){
        count+=countLeafNodes(root->children[i]);
    }
    return count;
}

void preorder(TreeNode<int> * root){
    //edge case
    if(root==NULL)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size();i++){
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int> * root){
    for (int i = 0; i < root->children.size();i++){
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}

void deleteTree(TreeNode<int>* root){
    for (int i = 0; i < root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}
int main() {
    /* TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(10);
    TreeNode<int> *node2 = new TreeNode<int>(20);

    root->children.push_back(node1);
    root->children.push_back(node2);
    printTree(root); */
     
    //1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int> * root = takeInputLevelWise();
    // printTree(root);
    levelWisePrint(root);
    // cout << countNodes(root);
    // cout << countHeight(root);
    // printAtLevelK(root, 2);
    // cout << countLeafNodes(root);
    // preorder(root);
    // cout << endl;
    // postorder(root);

    //deleting the tree 2 options;
    //this delete will call destructor of the TreeNode for all
    delete root;
    // deleteTree(root);
}