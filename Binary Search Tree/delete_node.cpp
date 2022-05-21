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

Node * goRight(Node *root){
     
    if(root==NULL)
        return NULL;
    if(root->right==NULL)
        return root;
    
    return goRight(root->right);
}
 
 Node* inorderPred(Node* root){
     if(root==NULL) 
        return NULL;
     
     return goRight(root->left);
 }
 
 Node* deleteNode(Node* root, int k)
{
    if(root==NULL)
        return NULL;
    
    if(root->data==k){
        
        //case 1 : it is leaf node
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        
        // case 2: it is half node
        else if(root->left==NULL || root->right==NULL)
        {
            Node* temp= root;
            if(root->left)
            {
                root=root->left;
                temp->left=NULL;
            }
            
            else
            {
                root=root->right;
                temp->right=NULL;
            }
            
            delete temp;
            return root;
        }
        
        // case 3: it is full node
        else 
        {
            Node* prev=inorderPred(root);
            root->data=prev->data;
            root->left=deleteNode(root->left, prev->data);
            return root;
        }
        
    }
    
    else if(root->data <k){
        root->right=deleteNode(root->right, k);
        return root;
    }
    
    else{
        root->left=deleteNode(root->left, k);
        return root;
    }
    
    return root;
   
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
     root=deleteNode(root,9);
     inorder(root);
     return 0;
 }
