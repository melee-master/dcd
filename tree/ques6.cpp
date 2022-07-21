//optimized diameter of a tree: 
#include <iostream>
using namespace std;
class node {
    public:
    int data;
    node * left;
    node * right;
    node (int d){
        data = d;
        left = NULL;
        right  = NULL;
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

class Pair{
    public:
    int diameter;
    int height;
};
Pair optimizedDiameter(node *root){
    Pair p;
    if(root==NULL){
        p.diameter = p.height  = 0;
        return p;
    }
    Pair left = optimizedDiameter(root->left);
    Pair right = optimizedDiameter(root->right);
    p.height = max(left.height, right.height)+1;
    p.diameter = max(left.height+ right.height, max(left.diameter, right.diameter));
    return p;
}
int main(){

    node * root = buildTree();
    Pair p = optimizedDiameter(root);
    cout<<p.diameter;

    return 0;
}