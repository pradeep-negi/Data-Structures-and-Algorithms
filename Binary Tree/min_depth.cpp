#include <iostream>
using namespace std;

class Node {

public:
    int key;
    Node* left;
    Node* right;

    Node(int d){
        key=d;
        left=NULL;
        right=NULL;
    }
};

int minDepth(Node *root) {
  
    if(root->left==NULL && root->right==NULL)
        return 1;
    
    else if(root->left==NULL)
        return minDepth(root->right);
    
    else if(root->right==NULL)
        return minDepth(root->left);
    
    int d1=minDepth(root->left);
    int d2=minDepth(root->right);
    
    return min(d1,d2)+1;
}

int main() {
	// your code goes here
    Node * root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(3);
    root->left->right=new Node(4);

    cout<<minDepth(root);
	return 0;
}
