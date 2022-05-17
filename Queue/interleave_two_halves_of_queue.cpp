#include <bits/stdc++.h>
using namespace std;

void print(queue<int> q){

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

queue<int> enqueue(queue<int> &q, int n){
    
    queue<int>q1;
    while(n){
        int temp=q.front();
        q1.push(temp);
        q.pop();
        n--;
    }
    return q1; 
}

queue<int> interLeave(queue<int> q){
    
    int n=q.size();
    n/=2;
    queue<int>q1 = enqueue(q, n);
    queue<int>q2 = enqueue(q, n);
    
    while(n){
        q.push(q1.front());
        q1.pop();
        q.push(q2.front());
        q2.pop();
        n--;
    }
    
    return q;
}

int main()
{
	queue<int>q;
	for(int i=1;i<9;i++){
		q.push(i);
	}
	queue<int> ans =interLeave(q);
	print(ans);
	return 0;
}
