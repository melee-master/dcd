#include <iostream>
using namespace std;
class Node{
    public: 
        int data;
        Node * next;
        Node (int d){
            data =d;
            next = NULL;
        }
};
void insertAtHead(Node *&head, int data){
    if(head==NULL){
        head = new Node(data);
        return ;
    }
    Node *n = new Node(data);
    n->next = head;
    head = n;
    return ;
}
void printLL(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }

}
Node * kthNodeFromLast(Node *head, int k){
    Node * fast = head;
    Node * slow = head;
    for(int i=0; i<k-1; i++){
        fast = fast->next;
    }
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
int main(){
    int arr[100000];
    int i=0; 
    int num=0;

    while(num!=-1){
        cin>>num;
        arr[i] = num;
        i++;
    }

    Node * head = NULL;
    for(int j=i-2; j>=0; j--){
        insertAtHead(head, arr[j]);
    }

    int k;
    cin>>k;
    Node * c = kthNodeFromLast(head, k);
    cout<<c->data;
    return 0;
}