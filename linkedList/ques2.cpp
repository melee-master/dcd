//Insertion art Head, tail and at a specified pos;
//Delete the node at the beginning of a ll;
//Searching(Linear Search)
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
void printLL(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}
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
int listLength(Node *head){
    int len=0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    return len;
}
void inserInMiddle(int data, int pos, Node *&head){
    if(head==NULL || pos==0){
        insertAtHead(head, data);
        return;
    }
    else{
        if(pos>listLength(head)){
            Node *temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            Node *n = new Node(data);
            temp->next = n;
            return;
        }else{
            int jump=1;
            Node *temp = head;
            while(jump<=pos-1){
                temp= temp->next;
                jump++;
            }
            Node *n = new Node(data);
            n->next = temp->next;
            temp->next = n;
        }
    }
}
void delteNodeAtHead(Node *&head){
    if(head==NULL){
        return;
    }
    Node *temp = head->next;
    delete(head);
    head = temp;
    return;
}
bool recursiveSearch(Node *head, int n){
    //Base Case: 
    if(head==NULL){
        return false;
    }
    if(head->data==n){
        return true;
    }else{
        return recursiveSearch(head->next, n);
    }
}
int main(){
    Node *head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    printLL(head);
    cout<<endl;
    inserInMiddle(4, 3, head);
    printLL(head);
    cout<<endl;
    delteNodeAtHead(head);
    printLL(head);
    cout<<endl;
    int n;
    cin>>n;
    bool present = recursiveSearch(head, n);
    if(present){
        cout<<"Present";
    }else{
        cout<<"False";
    }
    return 0;
}