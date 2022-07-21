//Searching in bst: 

#include <iostream>
using namespace std;
class node{
    public: 
    int data;
    node * left;
    node * right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node * insertInBst(node * root, int data){
    if(root==NULL){
        return new node(data);
    }
    if(data<=root->data){
        root->left = insertInBst(root->left, data);
    }
    if(data>root->data){
        root->right = insertInBst(root->right, data);
    }
    return root;
}

node * build(){
    int data;
    cin>>data;
    node *root = nullptr;
    while(data!=-1){
        root = insertInBst(root, data);
        cin>>data;
    }
    return root;
}

bool searchInBst(node * root, int data){
    if(root==NULL){
        return false;
    }
    if(root->data==data){
        return true;
    }
    if(data<=root->data){
        return searchInBst(root->left, data);
    }else{
        return searchInBst(root->right, data);
    }
}


int main(){
    node * root = build();
    if(searchInBst(root, 3)){
        cout<<"PRESENT"<<endl;
    }else{
        cout<<"ABSENT"<<endl;
    }


}