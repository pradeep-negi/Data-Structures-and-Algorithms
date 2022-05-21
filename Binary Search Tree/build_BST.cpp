#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

void inorder(Node* root){
    if(root==NULL)
        return ;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* insertNode(Node *root, int key){
    if(root==NULL)
    {
        root=new Node(key);
        return root;
    }

    if(root->data<key){
        root->right=insertNode(root->right, key);
        return root;
    }
        
    
    if(root->data>key){
         root->left=insertNode(root->left, key);
         return root;
    }

    return root;  
}

Node * createBST(vector<int>v){

    Node* root=NULL;
    int n=v.size();
    for(int i=0;i<n;i++){
        root=insertNode(root, v[i]);
    }
    
    return root;
}

 int main(){
     vector<int>v={9,11,5,1,3,6,7,2};
     Node* root =createBST(v);
     inorder(root);
     return 0;
 }
