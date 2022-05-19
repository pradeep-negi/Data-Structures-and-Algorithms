#include <iostream>
#include <queue>
#include <vector>

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

bool isPalindrome(vector<int> v){
    int n=v.size();
    for(int i=0;i<=n/2;i++){
        if(v[i]!=v[n-i-1])
            return 0;
    }
    return 1;
}

bool isSymmetric(Node* root) {
    //your code goes here
    if(root==NULL)
        return 0;
    
    queue<Node*>q;
    vector<int>v;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            if(!q.empty()) 
                q.push(NULL);
                
            if(!isPalindrome(v))
                    return 0;
                v.clear();
                v.resize(0);
                
        }
        
        else{
            
            if(temp->left!=NULL){
                v.push_back(temp->left->key);
                q.push(temp->left);
            }
            else
                v.push_back(0);
            
            if(temp->right!=NULL){
                v.push_back(temp->right->key);
                q.push(temp->right);
            }
            else
                v.push_back(0);
            
        }
    }
    
    return 1;
}

int main() {
	// your code goes here
    Node * root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right->left=new Node(4);
    root->right->right=new Node(3);

    cout<<isSymmetric(root);
	return 0;
}
