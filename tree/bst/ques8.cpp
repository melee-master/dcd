//Given a Binary Tree Print all the leaf nodes: 
#include <iostream>
#include <queue>
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
node * buildLevelOrderTree(node * root, int value, queue<node *>&q){
    node * Node = new node(value);
    if(root==NULL){
        return root= Node;
    }
    else if(root->left==NULL){
        q.front()->left = Node;
    }
    else{
        q.front()->right = Node;
        q.pop();
    }
    q.push(Node);
    return root;
}
node * createTree(){
    int data;
    cin>>data;
    queue<node *>q;

    node * root = NULL;
    while(data!=-1){
        root = buildLevelOrderTree(root, data, q);
        cin>>data;
    }
    return root;
}
void printLeaf(node * root){
    if(root->left==NULL and root->right==NULL){
        cout<<root->data<<" ";
    }
    if(root->left){
        printLeaf(root->left);
    }
    if(root->right){
        printLeaf(root->right);
    }
    return ;
}
int main(){
    node * root = createTree();
    printLeaf(root);
    return 0;
}