#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node * next;
    Node(int d){
        data = d;
        next = NULL;
    }
};
void insertAtHead(Node *&head, int data){
    if(head == NULL){
        head = new Node(data);
        return;
    }
    Node * n = new Node(data);
    n->next = head;
    head = n;
    return;
}
void printLL(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    } 
    return ;
}
Node * reverseKElements(Node *head, int k){
    if(!head){
        return NULL;
    }
    Node * current  = head;
    Node * next = NULL;
    Node * prev = NULL;
    int count=0;
    while(current!=NULL || count<k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if(next!=NULL){
        head->next = reverseKElements(next, k);
    }
    return prev;
}
int main(){
    int n;
    cin >> n;
    int k;
    cin>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Node * head = NULL;
    for(int i=0; i<n; i++){
        insertAtHead(head, arr[i]);
    }
    
    head = reverseKElements(head,  k);
    printLL(head);
}