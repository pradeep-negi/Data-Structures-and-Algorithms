#include <bits/stdc++.h>
using namespace std;

class Node{

public:
	int data;
	Node*left;
	Node*right;

	Node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

void preorder(Node * root){
	if(root==NULL)
		return;
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

Node* buildTree(vector<int> & v, int i){

	if(v[i]==-1){
		v[i]=0;
		return NULL;
	}
		
	if(v[i]){
		Node *root=new Node(v[i]);
		v[i]=0;
		root->left=buildTree(v,i+1);
		root->right=buildTree(v,i+1);

		return root;
	}

	return buildTree(v,i+1);
}

int main(){

	vector<int>v={1,2,4,-1,-1,5,7,-1,-1,-1,3,-1,6,-1,-1};
	Node* root = buildTree(v,0);
	preorder(root);
}
