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
Node * merge(Node * head1, Node * head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node * c;
    if(head1->data < head2->data){
        c = head1;
        c->next = merge(head1->next, head2);
    }else{
        c = head2;
        c->next = merge(head1, head2->next);
    }
    return c;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
    

         int m;
        cin>>m;
        int arr2[m];
        for(int i=0; i<m; i++){
            cin>>arr2[i];
        }
        Node * head2 = NULL;
        for(int i=m-1; i>=0; i--){
            insertAtHead(head2, arr2[i]);
        }
        Node * head1 = NULL;
        for(int i=n-1; i>=0; i--){
            insertAtHead(head1, arr[i]);
        }

        Node * c = merge(head1, head2);
        printLL(c);
        t--;
    }
}