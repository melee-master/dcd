//Count Total no.of Nodes :
#include <iostream>
using namespace std;
class node {
    public:
    int data;
    node * left;
    node * right;
    node(int d){
        data = d;
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
int count (node *root){
    if(root==NULL){
        return 0;
    }
    int length = count(root->left) + count(root->right) + 1;
    return length;
}
int main(){
    node * root = buildTree();
    cout<<count(root);
    return 0;
}