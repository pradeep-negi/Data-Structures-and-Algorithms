#include <iostream>
#include <string>
using namespace std;

class Node {

    public:
    string key;
    Node* left, *right;
    Node(string str)
    {
        key=str;
        left=NULL;
        right=NULL;
    }
};

int evalTree(Node* root){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return stoi(root->key);
        
    int e1=evalTree(root->left);
    int e2=evalTree(root->right);
    
    if(root->key=="+")
        return e1+e2;
    else if(root->key=="-")
        return e1-e2;
    else if(root->key=="*")
        return e1*e2;
    else                        // let us assume only four operations are applicable.
        return e1/e2;
}

int main() {
	// your code goes here
    Node * root=new Node("+");
    root->left=new Node("3");
    root->right=new Node("*");
    root->right->left=new Node("5");
    root->right->right=new Node("2");

    cout<<evalTree(root);
	  return 0;
}
