//Preorder Build and print: 
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
node *buildTree(){
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
void printTree(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
    return;
}
void printIn(node *root){
    if(root==NULL){
        return;
    }
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
    return;
}
void printPo(node *root){
    if(root==NULL){
        return;
    }
    printPo(root->left);
    printPo(root->right);
    cout<<root->data<<" ";
    return;
}
int main(){
    node *root = buildTree();
    printTree(root);
    cout<<endl;
    printIn(root);
    cout<<endl;
    printPo(root);
    cout<<endl;
}