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
    root->right = buildTree();
    return root;
}

int height(node *root){
    if(root==NULL){
        return 0;
    }
    return (max(height(root->left), height(root->right))+1);
}

int diameter(node *root){
    if(root==NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1+h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1, max(op2, op3));
}
int main(){

    node * root = buildTree();
    cout<<diameter(root);
    return 0;
}