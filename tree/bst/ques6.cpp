//Construct Bst form preorder traversal: 
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
int currentIndex = 0;
node * preToBst(int * preOrder, int minimumLimit, int maximumLimit, int n){
    if(currentIndex>=n){
        return NULL;
    }
    node * root = NULL;
    if(preOrder[currentIndex]>minimumLimit&& preOrder[currentIndex]<maximumLimit){
        root = new node(preOrder[currentIndex]);
        currentIndex++;
        root->left  = preToBst(preOrder, minimumLimit, root->data, n);
        root->right = preToBst(preOrder, root->data, maximumLimit, n);
    }
    return root;
}
void bfs(node * root){
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
    return ;
}

int main(){
    int preOrder[] = {10, 5, 1, 7, 40, 50};
    int n = sizeof(preOrder)/sizeof(preOrder[0]);
    node * root  = preToBst(preOrder, INT_MIN, INT_MAX, n);
    bfs(root);
    return 0;
}