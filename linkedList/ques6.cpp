//Kth node form end: 
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
Node * kthFromLast(Node* head, int k){
    Node * fast = head;
    Node * slow = head;
    for(int i=0; i<k; i++){
        fast = fast->next;
    }
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
int main(){
    Node *head = NULL;
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    int k;
    cin>>k;
    Node * ans = kthFromLast(head, k);
    cout<<ans->data;
    return 0;
}