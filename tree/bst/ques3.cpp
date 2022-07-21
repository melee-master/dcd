//Deletion in a BST :
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

node * deleteInBst (node * root, int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left = deleteInBst(root->left, data);
        return root;
    }
    else if(root->data == data){
        //CASE-1: 0 child nodes: 
        if(root->left==NULL and root->right==NULL){
            delete root;
            return NULL;
        }
        //CASE-2: 1 childe node :
        if(root->left==NULL and root->right !=NULL){
            node * temp = root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL and root->right==NULL){
            node * temp = root->left;
            delete root;
            return temp;
        }
        //CASE-3: 2 child nodes: 
        node * replace  = root->right;
        while(replace->left!=NULL){
            replace = replace->left;
        }
        root->data = replace->data;
        root->right  = deleteInBst(root->right, replace->data);
        return root;
    }else{
        root->right = deleteInBst(root->right, data);
        return root;
    }
}


int main(){
    node * root = build();
    bfs(root);
    cout<<endl;
    deleteInBst(root, 7);
    bfs(root);
    return 0;
}