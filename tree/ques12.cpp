#include <iostream>
using namespace std;
class node {
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
void printAtLevelK(node *root, int k){
    if(k==0){
        cout<<root->data;
        return;
    }
    if(root==NULL || k<0){
        return;
    }
    printAtLevelK(root->left, k-1);
    printAtLevelK(root->right, k-1);
    return ;
}

int printAtDistanceK(node *root, node * target,int k){
    //Base Case:
    if(root==NULL){
        return -1;
    }
    //Recursive Case: 
    if(root== target){
        printAtLevelK(target, k);
        return 0;
    }
    int DL = printAtDistanceK(root->left, target, k);
    if(DL !=-1){
        if(DL+1==k){
            cout<<root->data;
        }else{
            printAtLevelK(root->right, k-2-DL);
        }
        return 1+DL;
    }
    int DR = printAtDistanceK(root->right, target, k);
    if(DR!=-1){
        if(DR!=-1){
            if(DR+1==k){
                cout<<root->data;
            }else{
                printAtLevelK(root->left, k-2-DR);
            }
            return 1+DR;
        }
    }
    return -1;
}




int main(){
    node * root = buildTree();
    node * target = root->left->left;
    printAtDistanceK(root, target, 2);
}