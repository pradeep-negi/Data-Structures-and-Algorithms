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

void levelorder(Node * root){

	if(root==NULL)
		return ;
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* temp=q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty() )	
				q.push(NULL);
		}
			
		else{
			cout<<temp->data<<" ";
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}	
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
