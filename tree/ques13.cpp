//Find the lowest commom ancestor 
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

node * buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node * root = new node(data);
    root->left = buildTree();
    root->right =  buildTree();
    return root;
}

node * lca(node * root, int a, int b){
    if(root==NULL){
        return NULL;
    }
    
    if(root->data==a || root->data==b){
        return root;
    }
    
    node * leftans = lca(root->left, a, b);
    node * rightans = lca(root->right, a, b);

    if(leftans!=NULL && rightans!=NULL){
        return root;
    }

    if(leftans!=NULL){
        return leftans;
    }
    return rightans;
}

int main(){
    node * root = buildTree();
    node * commomAmcestor = lca(root, 7, 9);
    cout<<commomAmcestor->data;
}