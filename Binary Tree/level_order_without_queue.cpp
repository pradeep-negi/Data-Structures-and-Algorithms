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

int height(Node * root){
	if(root ==NULL)
		return 0;
	
	if(!(root->left) && !(root->right) )
		return 0;

	int h1=height(root->left);
	int h2=height(root->right);

	return max(h1,h2)+1;

}

void printIthLevel(Node *root, int i){

	if(root==NULL)
	{
		return ;
	}
	if(i==0){
		cout<<root->data<<" ";
		return ;
	}

	printIthLevel(root->left, i-1);
	printIthLevel(root->right,i-1);

}

void levelorder(Node * root){

	if(root==NULL)
		return ;
	
	int h=height(root);

	for(int i=0;i<=h;i++){
		printIthLevel(root, i);
		cout<<endl;
	}
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
	vector<int>v={1,2,4,8,-1,-1,9,-1,-1,5,10,-1,-1,11,-1,-1,3,6,-1,13,-1,-1,7,14,-1,-1,-1};
	Node* root = buildTree(v,0);
	levelorder(root);
  return 0;
}
