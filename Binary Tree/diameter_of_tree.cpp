#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int d){
        data=d;
    }
};

int diameter(Node *root){
    if(root==NULL)
        return 0;
    
    int D1=diameter(root->left);
    int D2=diameter(root->right);
    int h1,h2;

    if(root->left==NULL)
        h1=0;
    else
        h1=root->left->height;

    if(root->right==NULL)
        h2=0;
    else
        h2=root->right->height;

    int D3=h1+h2;
    root->height=1+max(h1,h2);
    return max(D1, max(D2, D3) );

}

Node * buildLevelOrder(vector<int> v){

    int n=v.size();
    if(n==0)    
        return NULL;
    queue<Node *>q;
    Node* root=new Node(v[0]);
    root->left=NULL;
    root->right=NULL;
    q.push(root);
    for(int i=1;i<n;i++)
    {
        if(i%2!=0){
            if(v[i]!=-1){
                Node* temp=new Node(v[i]);
                temp->left=NULL;
                temp->right=NULL;
                Node* parent= q.front();
                parent->left=temp;
                q.push(temp);
            }
            
            else{
                Node* parent= q.front();
                parent->left=NULL;
            }

        }

        else{

            if(v[i]!=-1){
                Node* temp=new Node(v[i]);
                temp->left=NULL;
                temp->right=NULL;
                Node* parent= q.front();
                parent->right=temp;
                q.push(temp);
            }

            else{
                Node* parent=q.front();
                parent->right=NULL;
            }
            
            q.pop();
        }
         
       
    }

    return root;
}

int main() {
	// your code goes here
    vector<int>v={1,2,3,-1,4,5,6,-1,-1,8,-1,-1,11,9,-1,-1,12,10,-1,-1,13};
    Node* root = buildLevelOrder(v);
    int d = diameter(root);
    cout<<d<<endl;
	return 0;
}
