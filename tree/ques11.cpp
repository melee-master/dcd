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

void rightViewFirst(int &maxLevel, node * root, int level){
    if(root==NULL){
        return;
    }
    if(level>maxLevel){
        maxLevel = level;
        cout<<root->data<<" ";
    }
    rightViewFirst(maxLevel, root->right, level+1);
    rightViewFirst(maxLevel, root->left, level+1);
    return;
}

int main(){
    node * root = buildTree();
    int maxLevel = -1;
    rightViewFirst(maxLevel, root, 0);
    return 0;
}