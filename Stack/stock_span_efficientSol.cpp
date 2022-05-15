#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpanner(vector<int> &stocks){
  
	int n=stocks.size();
	vector<int>span(n);
	stack<int>s;
	int i=0;
	span[i]=1;
    s.push(i);
    int prev_idx=0;
	for(i=1;i<n;i++){
	    
        while(stocks[i]>=stocks[s.top()] && !s.empty())
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

int main()
{
    vector<int>stocks={100,80,60,70,60,75,85};
    int n=stocks.size();
    vector<int>span=stockSpanner(stocks);
    for(int i=0;i<n;i++){
        cout<<span[i]<<" ";
    }
    cout<<endl;
    return 0;
}
