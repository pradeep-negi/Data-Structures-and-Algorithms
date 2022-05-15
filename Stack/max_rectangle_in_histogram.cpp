#include<bits/stdc++.h>
using namespace std;
 
 vector<int> right(vector<int> graph){
     
    int n= graph.size();
	vector<int>span(n);
	stack<int>s;
	int i=n-1;
	span[i]=0;
    s.push(i);
    int prev_idx=i;
	for(i=n-2;i>=0;i--){
	    
        while(!s.empty() && graph[i]<=graph[s.top()] )
            s.pop();
        if(s.empty())
            span[i]=prev_idx-i;
            
        else
            span[i]=s.top()-i-1;
            
        s.push(i);
        prev_idx=s.top();
	    
	}
	
	return span;
}

vector<int> left(vector<int> graph){
    
    int n=graph.size();
	vector<int>span(n);
	stack<int>s;
	int i=0;
	span[i]=1;
    s.push(i);
    int prev_idx=0;
	for(i=1;i<n;i++){
	    
        while(!s.empty() && graph[i]<=graph[s.top()] )
            s.pop();
        if(s.empty())
            span[i]=i-prev_idx+1;
            
        else
            span[i]=i-s.top();
            
        s.push(i);
        prev_idx=s.top();
	    
	}
	
	return span;
}

 
int getMaxArea(vector<int> v){
    
    int size=v.size();
    vector<int> v1= left(v);
    vector<int> v2= right(v);
    
    for(int i=0;i<size;i++)
        v1[i]=(v1[i]+v2[i]) * v[i];
    

    return *max_element(v1.begin(), v1.end());
    
}

int main() {
	// your code goes here
    vector<int>hist={2,1,5,6,2,3};
    cout<<getMaxArea(hist);
	return 0;
}
