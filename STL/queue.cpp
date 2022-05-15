#include <iostream>
#include <queue>
using namespace std;

int main() {
	// your code goes here
    queue<int>q;
    q.push(10); // pushing elements in rear of queue
    q.push(20); // pushing elements in rear of queue
    q.push(30); // pushing elements in rear of queue
    q.push(40); // pushing elements in rear of queue
    q.push(50); // pushing elements in rear of queue

    cout<<q.front()<<endl; // to get the front element
    cout<<q.back()<<endl;  // to get the rear element

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();  // pop the front element
    }

    cout<<endl<<"After popping size of queue is: "<<q.size();

	return 0;
}
