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
Node *middle(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while(fast!=NULL and fast->next!=NULL){
        fast= fast->next->next;
        slow= slow->next;
    }
    return slow;
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
Node * mergeSort(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *mid = middle(head);
    Node *a = head;
    Node *b = mid->next;

    mid->next = NULL;
    a=mergeSort(a);
    b = mergeSort(b);
    Node * c= merge(a, b);
    return c;

}

int main(){
    Node *head1=NULL;
    Node *head2=NULL;
    insertAtHead(head1, 5);
    insertAtHead(head1, 1);
    insertAtHead(head1, 2);
    insertAtHead(head1, 0);
    
    
    
    printLL(head1);
    cout<<endl;
    printLL(head2);
    cout<<endl;
    Node*c = mergeSort(head1);
    printLL(c);
    return 0;
}