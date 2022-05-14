#include <bits/stdc++.h>
using namespace std;

int spanner(vector<int> stocks, int i, int idx){
    if(i<0)
        return 0;
    if(stocks[i]<=stocks[idx] && i>=0)
        return 1+spanner(stocks, i-1, idx);
    
    return 0;
}

vector<int> stockSpanner(vector<int> &stocks){
	
	int size=stocks.size();
	vector<int>ans(size);
	for(int i=0;i<size;i++)
	{
	    ans[i]=spanner(stocks,i, i);
	}
	
	return ans;
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
