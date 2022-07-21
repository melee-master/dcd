//Check the given tree is BST or NOT:
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
node * insertInBst(node * root, int data){
    if(root==NULL){
        return new node(data);
    }
    if(data<=root->data){
        root->left = insertInBst(root->left, data);
    }
    if(data>root->data){
        root->right = insertInBst(root->right, data);
    }
    return root;
}

node * build(){
    int data;
    cin>>data;
    node * root = NULL;
    while(data!=-1){
        
        root = insertInBst(root, data);
        cin>>data;
    }
    return root;
}

void bfs(node * root){
    queue <node *>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * f =q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<f->data<<" ";
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
            q.pop();
        }
    }
}

bool checkIfBst(node * root, int min, int max){
    if(root==NULL){
        return true;
    }
    if(root->data>=min && root->data<max &&  checkIfBst(root->left, min, root->data) && checkIfBst(root->right, root->data, max)){
        return true;
    }
    return false;
}

int main(){
    node * root = build();
    bfs(root);
    return 0;
}