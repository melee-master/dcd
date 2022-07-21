//Shortest Distance between nodes of a binary tree :
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
    node * root= new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
node *lca(node * root, int a, int b){
    if(root==NULL){
        return NULL;
    }
    if(root->data==a || root->data==b){
        return root;
    }
    node * leftRoot = lca(root->left, a, b);
    node * rightRoot = lca(root->right, a, b);
    if(leftRoot!=NULL and rightRoot!=NULL){
        return root;
    }
    if(leftRoot!=NULL){
        return leftRoot;
    }
    return rightRoot;
}
int search(node * root, int key, int level){
    if(root==NULL){
        return -1;
    }
    if(root->data==key){
        return level;
    }

    int left = search(root->left, key, level+1);
    if(left!=-1){
        return left;
    }
    int right= search(root->right, key, level+1);
    return right;
}
int findDistance(node * root, int a, int b){
    node * lca_node = lca(root, a, b);
    cout<<lca_node->data<<endl;
    int d1 = search(lca_node, a, 0);
    cout<<d1<<endl;
    
    int d2 = search(lca_node, b, 0);
    cout<<d2<<endl;
    return d1+d2;
}

int main(){
    node * root = buildTree();
    cout<<findDistance(root, 7, 9);
    return 0;
}