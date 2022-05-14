#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> v){
    int i=v.size()-1;
    stack<int>s;
    vector<int>higher(i+1);
    while(i>=0){
        
        while(!s.empty() && v[i]>=s.top()){
            s.pop();
        }
        
        if(s.empty())
            higher[i]=-1;
            
        else
            higher[i]=s.top();
            
        s.push(v[i]);
        i--;
            
    }
    return higher;
}

int main(){
    vector<int>v={4,5,2,25,6,11,13,9,19};
    vector<int> ans= nextGreaterElement(v);
    int n=ans.size();
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
