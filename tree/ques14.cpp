//Maximum Sum path form any node to any node
#include <iostream>
using namespace std;
class pairMaker{
    public: 
    int branchSum;
    int maxSum;
    pairMaker(){
        branchSum=0;
        maxSum=0;
    }
};
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
pairMaker maxSumPath(node * root){
    pairMaker p;
    if(root==NULL){
        return p;
    }
    pairMaker left = maxSumPath(root->left);
    pairMaker right = maxSumPath(root->right);

    int op1 = root->data;
    int op2 = left.branchSum + root->data;
    int op3 = right.branchSum + root->data;
    int op4 = left.branchSum+right.branchSum+ root->data;

    int currentAnsThroughRoot = max(op1, max(op2, max(op3, op4)));
    p.branchSum = max(left.branchSum, max(right.branchSum, 0))+ root->data;
    p.maxSum = max(left.maxSum, max(currentAnsThroughRoot, right.maxSum));
    return p;
}

int main(){
    node * root;
    root = buildTree();
    pairMaker p = maxSumPath(root);
    cout<<p.maxSum;
}
