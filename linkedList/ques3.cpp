//Reverse a Linked List;
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
void reverseNode(Node *&head){
    Node *curr = head;
    Node *prev = NULL;
    
    Node *N;
    while(curr!=NULL){
        N = curr->next;
        curr->next = prev;
        prev = curr;
        curr = N;
    }
    head = prev;
    return;
}
int main(){
    Node *head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    printLL(head);
    cout<<endl;
    reverseNode(head);
    printLL(head);
    return 0;
}