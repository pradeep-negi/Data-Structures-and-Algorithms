#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
    }
};

void printLevelOrder(Node * root){
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
    vector<int>v={1,2,3,4,5,-1,6,-1,-1,7,-1,-1,-1,-1,-1};
    Node* root = buildLevelOrder(v);
    printLevelOrder(root);
	return 0;
}
