//Pre-order pot-order: 
#include <iostream>
#include <queue>
using namespace std;
class node{
    public:
    int data;
    node * left;
    node * right;
    node (int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
node * buildTree(int * inorder, int * preorder, int s, int e){
    static int i =0;
    if(s>e){
        return NULL;
    }
    node * root = new node(preorder[i]);
    if(s==e){
        return root;
    }
    
    int index= -1;
    for(int j=s; j<=e; j++){
        if(root->data == inorder[j]){
            index = j;
            break;
        }
    }
    
    i++;
    root->left = buildTree(inorder, preorder, s, index-1);
    root->right = buildTree(inorder, preorder, index+1, e);
    return root;
}
void bfs(node *root){
    queue<node *>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }

    }
}
int main(){

    int preorder [] = {3, 2, 8, 4, 1, 6, 7, 5};
    int inorder [] = {1, 2, 3, 4, 8, 5, 6, 7};
    int n = sizeof(preorder)/sizeof(int);
    node * root = buildTree(inorder, preorder, 0, n-1);
    bfs(root);
    return 0;
}