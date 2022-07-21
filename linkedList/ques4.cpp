//Recursovely Reverse a linked list: 
#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int d){
            data = d;
            next = NULL;
        }
};
void insertAtHead(Node *&head, int data){
    if(head==NULL){
        head = new Node(data);
        return;
    }
    Node *n = new Node(data);
    n->next = head;
    head =n;
    return;
}
void printLL(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}
Node* recRecursive(Node *head){
    if(head->next==NULL || head==NULL){
        return head;
    }
    Node *shead = recRecursive(head->next);
    Node *temp = shead;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    head->next= NULL;
    temp->next = head;
    return shead; 
}
int main(){
    Node *head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    printLL(head);
    cout<<endl;
    head = recRecursive(head);
    printLL(head);
    return 0;
}