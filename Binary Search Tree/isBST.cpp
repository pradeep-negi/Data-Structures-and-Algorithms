#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node{
    public:
    int key;
    Node* left, *right;
    Node(int data){
        key=data;
        left=NULL;
        right=NULL;
    }
};

bool isBSTUtil(Node * root, int min, int max){
    if(root==NULL)
        return true;
    
    if(root->key < min || root->key > max)
        return false;
  
    return isBSTUtil(root->left, min, root->key-1) && isBSTUtil(root->right,root->key+1, max) ;
        
}

bool isBST(Node * root){
    
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

 int main(){
    Node * root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(9);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right->left=new Node(8);
    cout<<isBST(root);
     return 0;
 }
