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
Node *merge(Node *a, Node *b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    Node *c;
    if(a->data < b->data){
        c=a;
        c->next = merge(a->next, b);
    }else{
        c=b;
        c->next = merge(a, b->next);
    }
    return c;
}
int main(){
    Node *head1=NULL;
    Node *head2=NULL;
    insertAtHead(head1, 6);
    insertAtHead(head1, 4);
    insertAtHead(head1, 2);
    insertAtHead(head1, 0);
    
    insertAtHead(head2, 7);
    insertAtHead(head2, 5);
    insertAtHead(head2, 3);
    insertAtHead(head2, 1);
    
    printLL(head1);
    cout<<endl;
    printLL(head2);
    cout<<endl;
    Node*c = merge(head1, head2);
    printLL(c);
    return 0;
}