#include <bits/stdc++.h>
using namespace std;
 
class Node {
    public:
    int val;
    Node* left, *right;
    Node(int d){
        val=d;
    }
};


void pathSumUtil(Node* root, int targetSum, vector<vector<int>> & v2d, vector<int> &v){
    // your code goes here
    
    if(root==NULL)
        return ;
        
    if(root->left==NULL && root->right== NULL && targetSum==root->val)
    {
        v.push_back(root->val);
        v2d.push_back(v);
        v.pop_back();
    }
    
    if(root->left==NULL && root->right == NULL){
        return;
    }
    
    v.push_back(root->val);
    pathSumUtil(root->left,targetSum-root->val, v2d, v);
    pathSumUtil(root->right,targetSum-root->val, v2d, v);
    v.pop_back();
}

vector<vector<int>> pathSum(Node* root, int targetSum){
    // your code goes here
    vector<vector<int> > v2d;
    vector<int>v;
    pathSumUtil(root, targetSum, v2d, v);
    return v2d;
}

int main(){

    Node * root=new Node(2);
    root->left=new Node(6);
    root->right=new Node(4);
    root->left->left=new Node(1);
    root->left->right=new Node(11);
    root->right->left=new Node(9);

    vector<vector<int>> v=pathSum(root, 19);
    int n=v.size();
    for(int i=0;i<n;i++){
        int m=v[i].size();
        for(int j=0;j<m;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
