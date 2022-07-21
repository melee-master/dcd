#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int data){
    Node * n = new Node(data);
    Node * temp = head;
    n->next = head;
    if(temp!=NULL){
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = n;
    }
    head = n;
}

int main(){

}