#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"

void print(Node *);
void insertAt(Node *, int, int);
int getTotalNodes(Node *);
Node * takeInput();
Node * deleteAt(Node *, int);
Node * insertr(Node *, int, int);
Node * deleter(Node *, int);
Node * getMid(Node *);
Node * reverser(Node *);
Node * reverseItr(Node *);

int main() {
    Node *head =NULL;
    head=takeInput();
    print(head);
    
    head=reverseItr(head);
    print(head);
}

Node *reverseItr(Node *head){
    Node *pre = NULL, *cur = head, *next=NULL;
    while (cur!=NULL) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

//reverse linked list recursion
Node *reverser(Node *head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    Node *smallAns = reverser(head->next);
    Node *tail = head->next;

    tail->next = head;
    head->next = NULL;
    return smallAns;
}

//print linked list
void print(Node *head){
    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

//take input from user
Node* takeInput(){
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail=NULL;

    while(data!=-1){
        Node *newNode= new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        } else{
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

//get total length of linked list
int getTotalNodes(Node *head){
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}

//insert at ith index
void insertAt(Node *head, int data, int position){
    int length = getTotalNodes(head);
    if(position>0 && position <= length ){
        //first
        if(position==1){
            Node *newNode = new Node(data);
            newNode->next = head;
            head = newNode;
            print(head);
        } else { //last or mid
            while(--position>1){
                head = head->next;
            }
            Node *newNode = new Node(data);
            newNode->next = head->next;
            head->next = newNode;
        }
        return;
    }
    cout << "Invalide index\n";
}

//delete ith index
Node * deleteAt(Node * head, int position){
    int length = getTotalNodes(head);
    if(position > 0 && position <= length ){
        if(position==1){
            Node *toFree = head;
            head = head->next;
            delete toFree;
        } else {
            while(--position>1){
                head = head->next;
            }
            Node *toFree = head->next;
            head->next = head->next->next;
            delete toFree;
        }
    }
    return head;
}

//insertion on ith recursively
Node* insertr(Node * head, int data, int position){
    //base case
    if(head==NULL){
        return head;
    }
    //small calc
    if(position==0){
        Node *newnode = new Node(data);
        newnode->next = head;
        head = newnode;
        return head;
    }
    head->next= insertr(head->next, data, position - 1);
    return head;
}

//deletion on ith recursively
Node * deleter(Node *head, int position){
    if(head==NULL){
        return head;
    }
    if(position==0){
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    head->next=deleter(head->next, position - 1);
    return head;
}

//get middle element;
Node * getMid(Node *head){
    Node *slow = head;
    Node *fast = head;
    while(fast->next!=NULL && fast!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

