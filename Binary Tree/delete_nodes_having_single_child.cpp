#include <iostream>
#include <vector>
using namespace std;

class Node {
    
    public:
    int key;
    Node* left, *right;

    Node(int d){
        key=d;
        left=NULL;
        right=NULL;
    }
};

void inorder(Node * root, vector<int> &v){
    if(root==NULL)
        return;
    inorder(root->left,v);
    v.push_back(root->key);
    inorder(root->right,v);
    return ;
}

Node* removeNodes(Node *root){
    if(root==NULL)
        return NULL;

    if(root->left==NULL && root->right==NULL)
        return root;

    if(!(root->left))
    {
        root->right=removeNodes(root->right);
        Node* temp=root->right;
        delete root;
        return temp;
    }

    if(!(root->right))
    {
        root->left=removeNodes(root->left);
        Node* temp=root->left;
        delete root;
        return temp;
    }
    
    root->left=removeNodes(root->left);
    root->right=removeNodes(root->right);
    return root;
}

vector<int> removeHalfNodes(Node *root)
{
   root=removeNodes(root);
   vector<int> v;
   inorder(root,v);
   return v;
}

int main() {
	// your code goes here
    Node * root=new Node(2);
    root->left=new Node(6);
    root->right=new Node(4);
    root->left->left=new Node(1);
    root->left->right=new Node(11);
    root->right->left=new Node(9);

    vector<int> v =removeHalfNodes(root);
    int n=v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
	return 0;
}
