//Height Balanced tree :
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

class HBpair{
    public: 
    int height;
    bool isBalanced;
};
int absoluteDifference(int a, int b){
    if(a>b){
        return a-b;
    }else{
        return b-a;
    }
}
HBpair balancedHeightChecker(node * root){
    HBpair p;
    if(root==NULL){
        p.height = 0;
        p.isBalanced = true;
        return p;
    }
    HBpair left = balancedHeightChecker(root->left);
    HBpair right = balancedHeightChecker(root->right);
    p.height = max(left.height, right.height) + 1;
    if((absoluteDifference(left.height, right.height)<=1)&& left.isBalanced && right.isBalanced){
        p.isBalanced = true;
    }else{
        p.isBalanced = false;
    }
    return p;

}


int main(){
    node * root;
    root = buildTree();
    HBpair ans = balancedHeightChecker(root);
    if(ans.isBalanced){
        cout<<"BALANCED";
    }else{
        cout<<"NOT BALANCED";
    }
    return 0;
}