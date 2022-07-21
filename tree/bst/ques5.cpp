#include <iostream>
using namespace std;
class node  { 
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
class linkedList { 
    public: 
    node * head;
    node * tail;
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

linkedList flatten(node * root){
    linkedList l;
    if(root==NULL){
        l.head = l.tail = NULL;
        return l;
    }
    if(root->left==NULL and root->right==NULL){
        l.head = l.tail = root;
        return l;
    }
    if(root->left!=NULL and root->right==NULL){
        linkedList leftLL = flatten(root->left);
        leftLL.tail->right = root;
        l.head = leftLL.tail;
        l.tail = root;
        return l;
    }
    if(root->left==NULL and root->right!=NULL){
        linkedList rightLL = flatten(root->right);
        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }
    linkedList leftLL = flatten(root->left);
    linkedList rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;
    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}





int main(){



    return 0;
}