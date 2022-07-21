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
        head = new Node (data);
        return ;
    }
    Node *n = new Node(data);
    n->next = head;
    head= n;
    return;
}
void printLL(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return;
}
bool circleDetection(Node * head){
    Node * fast = head;
    Node * slow = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
void circleRemoval(Node *&head){
    Node *fast = head;
    Node *slow = head;
    while(fast!=slow){
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = head;
    while(fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }
    Node * prev = head;
    while(prev->next!=slow){
        prev=prev->next;
    }
    prev->next = NULL;
    return;
}

int main(){
    Node * head;

    bool circlePresent = circleDetection(head);

    return 0;
}